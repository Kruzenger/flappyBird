#pragma once

#include <cstdint>

struct Vector2D {
    Vector2D();
    Vector2D(float x, float y);
    ~Vector2D() { 
        int a = 1;
        a += 2;
    }

    const Vector2D& operator+=(const Vector2D& other);
    Vector2D operator+(const Vector2D& other) const;
    const Vector2D& operator-=(const Vector2D& other);
    Vector2D operator-(const Vector2D& other) const;
    const Vector2D& operator*=(const float& other);
    Vector2D operator*(const float& other) const;

    Vector2D fromWorldToCamera(const Vector2D& camera_pos) const;
    Vector2D fromCameraToWorld(const Vector2D& camera_pos) const;

    float x = 0;
    float y = 0;
};

struct Line {
    Vector2D p_start;
    Vector2D p_end;
};

struct Segment {
    Vector2D p_start;
    Vector2D p_end;
};

class AbstractShape {
  public:
    virtual ~AbstractShape() = 0;
};

class RectangleShape : public AbstractShape {
  public:
    RectangleShape() = default;
    RectangleShape(const Vector2D& lu_corner, const Vector2D& rd_corner);
    bool checkIntersection(const RectangleShape& other) const;

  protected:
    Vector2D p_lu_corner;
    Vector2D p_rd_corner;
};

