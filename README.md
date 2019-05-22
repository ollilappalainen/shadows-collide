# ShadowsCollide
2D collision detection program built as a part of game physics engine.
Includes a terminal UI where user can enter two lists of vertices as x- and y-coordinates and see the collision result.
Valid vertices form a convex polygon of atleast of three vertices.

## Developed with
* C++
* Microsoft Visual Studio 2019 Community

## Features
* Collision test for
    * AABB - AABB
    * Circle - Circle
    * Arbitrary Convex Polygon - Arbitrary Convex Polygon (ie. AABB - triangle, hexagon - OBB, circle - AABB)
* Tests if circle, aabb or arbitrary convex polygon
* UI for inputting vectors
* Light validation for vector string and std::vector
