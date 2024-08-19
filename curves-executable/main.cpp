#include <tbb/blocked_range.h>
#include <tbb/parallel_reduce.h>

#include <algorithm>
#include <iostream>
#include <memory>
#include <numbers>
#include <random>
#include <ranges>
#include <vector>

#include "Circle.h"
#include "Curve.h"
#include "Ellipse.h"
#include "Helix.h"
#include "Point3D.h"

std::vector<std::shared_ptr<cadex::Curve>> getRandomCurves(int count)
{
    std::vector<std::shared_ptr<cadex::Curve>> curves{};
    curves.reserve(count);

    static std::mt19937 mt{ std::random_device{}() };
    std::uniform_int_distribution shapeTypeDistribution{ 0, 2 };
    std::uniform_real_distribution doubleDistribution{ 1.0, 100.0 };

    for (int i{ 0 }; i < count; ++i)
    {
        int shapeType{ shapeTypeDistribution(mt) };
        if (shapeType == 0)
        {
            double radius{ doubleDistribution(mt) };
            curves.push_back(std::make_shared<cadex::Circle>(radius));
        }
        else if (shapeType == 1)
        {
            double xRadius{ doubleDistribution(mt) };
            double yRadius{ doubleDistribution(mt) };
            curves.push_back(
                std::make_shared<cadex::Ellipse>(xRadius, yRadius));
        }
        else if (shapeType == 2)
        {
            double radius{ doubleDistribution(mt) };
            double step{ doubleDistribution(mt) };
            curves.push_back(std::make_shared<cadex::Helix>(radius, step));
        }
    }

    return curves;
}

void printCoordinatesAndDerivatives(
    const std::vector<std::shared_ptr<cadex::Curve>>& curves)
{
    constexpr double parameter{ std::numbers::pi / 4.0 };
    for (const auto& curve : curves)
    {
        std::cout << "Point: " << curve->getPoint(parameter) << '\n';
        std::cout << "Derivative: " << curve->getDerivative(parameter)
                  << "\n\n";
    }
}

std::vector<std::shared_ptr<cadex::Circle>> populateCircleContainer(
    const std::vector<std::shared_ptr<cadex::Curve>>& curves)
{
    std::vector<std::shared_ptr<cadex::Circle>> circles{};

    for (const auto& curve : curves)
    {
        if (auto circle = std::dynamic_pointer_cast<cadex::Circle>(curve))
        {
            circles.push_back(circle);
        }
    }

    return circles;
}

double calculateTotalRadius(
    const std::vector<std::shared_ptr<cadex::Circle>>& circles)
{
    double totalRadius{ tbb::parallel_reduce(
        tbb::blocked_range<std::size_t>(0, circles.size()), 0.0,
        [&](const tbb::blocked_range<std::size_t>& subrange, double init)
        {
            for (std::size_t i{ subrange.begin() }; i != subrange.end(); ++i)
            {
                init += circles[i]->getRadius();
            }
            return init;
        },
        std::plus<double>{}) };

    return totalRadius;
}

int main()
{
    std::vector<std::shared_ptr<cadex::Curve>> curves{ getRandomCurves(10) };
    printCoordinatesAndDerivatives(curves);

    std::vector<std::shared_ptr<cadex::Circle>> circles{
        populateCircleContainer(curves)
    };

    std::ranges::sort(circles,
                      [](const auto& first, const auto& second)
                      {
                          return first->getRadius() < second->getRadius();
                      });

    std::cout << "Circle radii in ascending order: ";
    for (const auto& circle : circles)
    {
        std::cout << circle->getRadius() << ' ';
    }
    std::cout << '\n';

    std::cout << "Total radii sum: " << calculateTotalRadius(circles) << '\n';

    return 0;
}
