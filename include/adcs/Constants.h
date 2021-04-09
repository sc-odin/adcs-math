#pragma once

// PHYSICS CONSTANTS
#define CONST_GRAVITATIONAL_CONSTANT 6.67408e-11
#define CONST_EARTH_MASS 5.9722e24
#define CONST_EARTH_RADIUS 6371.2
#define CONST_SUNLIT_AREA 0.06
#define CONST_SPEED_OF_LIGHT 2.99792458e8
#define CONST_UNITLESS_REFLECTANCE_FACTOR 0.6
#define CONST_SOLAR_CONSTANT 1367
#define CONST_PI 3.14159265358979323846
#define CONST_DEG_TO_RAD CONST_PI / 180.0
#define CONST_MAGNETORQUER_SATURATION_X 0.24
#define CONST_MAGNETORQUER_SATURATION_Y 0.24
#define CONST_MAGNETORQUER_SATURATION_Z 0.13


namespace adcs {
    // IMPORTANT LOCATIONS
    const double GROUND_LOCATION [3]= {1266.06,-4295.81,4526.14};
    const double ARGENTINA_LOCATION[3] = {1612.36,-4182.16,-4522.83};
    const double NAMIBIA_LOCATION[3] = {5659.26,1238.85,-2659.2};

    // INERTIA VALUES
    const double MOMENT_OF_INERTIA[3] = {0.04582275, 0.04561065, 0.0085932349};
    const double PRODUCT_OF_INERTIA[3] = {0.000947555, -0.000072545546, -0.000031658756};
}