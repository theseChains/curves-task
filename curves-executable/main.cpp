#include <tbb/parallel_reduce.h>
#include <tbb/blocked_range.h>

#include <algorithm>
#include <iostream>
#include <memory>
#include <numbers>
#include <ranges>
#include <vector>

#include "../curves-library/Circle.h"
#include "../curves-library/Curve.h"
#include "../curves-library/Ellipse.h"
#include "../curves-library/Helix.h"
#include "../curves-library/Point3D.h"

int main()
{
    std::vector<std::shared_ptr<cadex::Curve>> curves{};

    curves.push_back(std::make_unique<cadex::Circle>(5.0));
    curves.push_back(std::make_unique<cadex::Circle>(10.0));
    curves.push_back(std::make_unique<cadex::Circle>(8.0));
    curves.push_back(std::make_unique<cadex::Circle>(3.0));

    curves.push_back(std::make_unique<cadex::Ellipse>(5.0, 6.0));
    curves.push_back(std::make_unique<cadex::Ellipse>(10.0, 3.0));

    curves.push_back(std::make_unique<cadex::Helix>(5.0, 8.0));
    curves.push_back(std::make_unique<cadex::Helix>(10.0, 4.0));

    constexpr double parameter{ std::numbers::pi / 4.0 };
    for (const auto& curve : curves)
    {
        std::cout << "Point: " << curve->getPoint(parameter) << '\n';
        std::cout << "Derivative: " << curve->getDerivative(parameter)
                  << "\n\n";
    }

    std::vector<std::shared_ptr<cadex::Circle>> circles{};

    for (const auto& curve : curves)
    {
        if (auto circle = std::dynamic_pointer_cast<cadex::Circle>(curve))
        {
            circles.push_back(circle);
        }
    }

    std::ranges::sort(circles,
                      [](const auto& first, const auto& second)
                      {
                          return first->getRadius() < second->getRadius();
                      });

    std::cout << "circle radii in ascending order: ";
    for (const auto& circle : circles)
    {
        std::cout << circle->getRadius() << ' ';
    }
    std::cout << '\n';

    double totalRadius = tbb::parallel_reduce(
        tbb::blocked_range<std::size_t>(0, circles.size()),
        0.0,
        [&](const tbb::blocked_range<std::size_t>& subrange, double init)
        {
            for (std::size_t i{ subrange.begin() }; i != subrange.end(); ++i)
            {
                init += circles[i]->getRadius();
            }
            return init;
        },
        std::plus<double>{});

    std::cout << "total circle radii: " << totalRadius << '\n';

    return 0;
}
