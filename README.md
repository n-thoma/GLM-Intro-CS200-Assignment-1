# Affine Transformations in 2D

This repository contains the implementation of various 2D affine transformations and related functions in the `cs200` namespace. These transformations and functions are designed to work with the GLM (OpenGL Mathematics) library, commonly used in OpenGL programming. Below is a brief description of the functions implemented in the `Affine.h` header file.

## Functions Implemented

- `bool near(float x, float y)`: A convenience function to compare two floating-point numbers for equality within a small epsilon. This function helps handle the finite precision of floating-point computations.

- `bool isPoint(const glm::vec4& P)`: Checks if the given `glm::vec4` represents a 2D point and returns true if so; otherwise, it returns false.

- `bool isVector(const glm::vec4& v)`: Determines whether the provided `glm::vec4` represents a 2D vector and returns true if it does; otherwise, it returns false.

- `bool isAffine(const glm::mat4& A)`: Verifies if the given `glm::mat4` represents a 2D affine transformation matrix and returns true if it does; otherwise, it returns false.

- `glm::vec4 point(float x, float y)`: Creates and returns a 2D point represented by a `glm::vec4` with the specified components `(x, y)`.

- `glm::vec4 vector(float x, float y)`: Constructs and returns a 2D vector as a `glm::vec4` with components `x` and `y`.

- `glm::mat4 affine(const glm::vec4& u, const glm::vec4& v, const glm::vec4& C)`: Generates and returns a 2D affine transformation matrix with columns specified by vectors `u`, `v`, and `C`. This function represents a transformation such that `A(ex) = u`, `A(ey) = v`, and `A(O) = C`.

- `glm::mat4 rotate(float t)`: Produces a 2D affine transformation matrix for rotation by the angle `t` (in degrees) with respect to the origin.

- `glm::mat4 translate(const glm::vec4& v)`: Computes a 2D affine transformation matrix for translation by the 2D vector `v`.

- `glm::mat4 scale(float r)`: Calculates a 2D affine transformation matrix for uniform scaling by a factor `r` with respect to the origin.

- `glm::mat4 scale(float rx, float ry)`: Computes a 2D affine transformation matrix for non-uniform scaling by factors `rx` and `ry` with respect to the origin.

## Usage

To use these functions, include the `Affine.h` header file in your project and make sure to have the GLM library (specifically `glm/glm.hpp`) included in your project as well.

For testing and examples of how to use these functions, you can refer to the provided test drivers in your assignment.

## Note on Floating-Point Precision

When working with floating-point numbers, keep in mind that computations are only accurate to a finite degree of precision. To compare floating-point values for equality, I use the `near` function, which accounts for small differences due to numerical precision.

## Resources

- Documentation for the GLM library can be found at [GLM Documentation](https://glm.g-truc.net/0.9.9/index.html).

- Additional information on GLSL (OpenGL Shading Language) vector and matrix operations can be found at [GLSL Programming/Vector and Matrix Operations](https://en.wikibooks.org/wiki/GLSL_Programming/Vector_and_Matrix_Operations).
