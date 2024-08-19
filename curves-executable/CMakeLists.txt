find_package(TBB REQUIRED)

add_executable(curves_executable main.cpp)

target_link_libraries(curves_executable PRIVATE curves)
target_link_libraries(curves_executable PRIVATE TBB::tbb)
