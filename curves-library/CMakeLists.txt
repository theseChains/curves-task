add_library(curves SHARED
    src/Circle.cpp
    src/Ellipse.cpp
    src/Helix.cpp
    src/Point3D.cpp
)

target_include_directories(curves PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
