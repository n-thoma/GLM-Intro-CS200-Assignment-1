//-----------------------------------------------------------------------------
// 
//  Author: Nathaniel Thoma
// 
//  Assignment: 1
// 
//  Course: CS 200
// 
//  Term: Fall 2023
// 
//-----------------------------------------------------------------------------

#include "Affine.h"

//-----------------------------------------------------------------------------

bool cs200::isPoint(const glm::vec4& P)
{
  // Checks if the w is 1
  if (P.w == 1.0f)
    return true;

  return false;
}

bool cs200::isVector(const glm::vec4& v)
{
  // Checks if the w is 0
  if (v.w == 0.0f)
    return true;

  return false;
}

bool cs200::isAffine(const glm::mat4& A)
{
  // Checks if last row is (0, 0, 0, 1).
  if (A[0][3] == 0 && A[1][3] == 0 && A[2][3] == 0 && A[3][3] == 1)
    return true;

  return false;
}

//-----------------------------------------------------------------------------

glm::vec4 cs200::point(float x, float y)
{
  return glm::vec4(x, y, 0.0f, 1.0f);
}

glm::vec4 cs200::vector(float x, float y)
{
  return glm::vec4(x, y, 0.0f, 0.0f);
}

//-----------------------------------------------------------------------------

glm::mat4 cs200::affine(const glm::vec4& u, const glm::vec4& v, const glm::vec4& C)
{
  glm::mat4 A(0);

  A[0][0] = u.x; A[1][0] = v.x; A[2][0] = 0; A[3][0] = C.x;
  A[0][1] = u.y; A[1][1] = v.y; A[2][1] = 0; A[3][1] = C.y;
  A[0][2] =   0; A[1][2] =   0; A[2][2] = 1; A[3][2] =   0;
  A[0][3] =   0; A[1][3] =   0; A[2][3] = 0; A[3][3] =   1;

  return A;
}

glm::mat4 cs200::rotate(float t)
{
  // Convert degrees to radians
  float radians = glm::radians(t);

  float cosTheta = std::cos(radians);
  float sinTheta = std::sin(radians);

  glm::mat4 A(0);
  A[0][0] = cosTheta; A[1][0] = -sinTheta; A[2][0] = 0; A[3][0] = 0;
  A[0][1] = sinTheta; A[1][1] =  cosTheta; A[2][1] = 0; A[3][1] = 0;
  A[0][2] =        0; A[1][2] =         0; A[2][2] = 1; A[3][2] = 0;
  A[0][3] =        0; A[1][3] =         0; A[2][3] = 0; A[3][3] = 1;

  return A;
}

glm::mat4 cs200::translate(const glm::vec4& v)
{
  glm::mat4 A(0);
  A[0][0] = 1; A[1][0] = 0; A[2][0] = 0; A[3][0] = v.x;
  A[0][1] = 0; A[1][1] = 1; A[2][1] = 0; A[3][1] = v.y;
  A[0][2] = 0; A[1][2] = 0; A[2][2] = 1; A[3][2] =   0;
  A[0][3] = 0; A[1][3] = 0; A[2][3] = 0; A[3][3] =   1;

  return A;
}

glm::mat4 cs200::scale(float r)
{
  glm::mat4 A(0);
  A[0][0] = r; A[1][0] = 0; A[2][0] = 0; A[3][0] = 0;
  A[0][1] = 0; A[1][1] = r; A[2][1] = 0; A[3][1] = 0;
  A[0][2] = 0; A[1][2] = 0; A[2][2] = 1; A[3][2] = 0;
  A[0][3] = 0; A[1][3] = 0; A[2][3] = 0; A[3][3] = 1;

  return A;
}

glm::mat4 cs200::scale(float rx, float ry)
{
  glm::mat4 A(0);
  A[0][0] = rx; A[1][0] =  0; A[2][0] = 0; A[3][0] = 0;
  A[0][1] =  0; A[1][1] = ry; A[2][1] = 0; A[3][1] = 0;
  A[0][2] =  0; A[1][2] =  0; A[2][2] = 1; A[3][2] = 0;
  A[0][3] =  0; A[1][3] =  0; A[2][3] = 0; A[3][3] = 1;

  return A;
}
