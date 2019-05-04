# ShadowsCollide
2D collision detection software.

##Features
* Collision test for
    * AABB - AABB
    * Circle - Circle
    * Arbitrary Convex Polygon - Arbitrary Convex Polygon (ie. AABB - triangle, hexagon - OBB, circle - AABB)
* Tests if circle, aabb or arbitrary convex polygon
* UI for inputting vectors
* Light validation for vector string and std::vector

##Known issues
* Memory optimization
* Polygon containment might not work, tested only with Separating Axis Test
* Program exit signals are not handled correctly
