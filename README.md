# ShadowsCollide
2D collision detection software.

## Features
* Collision test for
    * AABB - AABB
    * Circle - Circle
    * Arbitrary Convex Polygon - Arbitrary Convex Polygon (ie. AABB - triangle, hexagon - OBB, circle - AABB)
* Tests if circle, aabb or arbitrary convex polygon
* UI for inputting vectors
* Light validation for vector string and std::vector

## Known issues
* Memory optimization, at the moment choosing which type of test to use and running test takes <2ms
* Polygon containment might not work, tested only with Separating Axis Test
* Program exit signals are not handled correctly
* AABB collision test doesn't handle equal vectors as colliding vectors
* AABB collision doesn't show distance as negative value if collision is true
* Cicle - Convex Polygon test does not work properly and is not used in main program