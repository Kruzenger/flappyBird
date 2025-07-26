#include "Geometry.h"

Vector2D::Vector2D(): x(0), y(0) {}

Vector2D::Vector2D(float x, float y): 
    x(x), 
    y(y) {}

const Vector2D& Vector2D::operator+=(const Vector2D& other) {
    this->x += other.x;
    this->y += other.y;
    return *this;
}

Vector2D Vector2D::operator+(const Vector2D& other) const {
    Vector2D copy = *this;
    return copy += other;
}

const Vector2D& Vector2D::operator-=(const Vector2D& other) {
    this->x -= other.x;
    this->y -= other.y;
    return *this;
}

Vector2D Vector2D::operator-(const Vector2D& other) const {
    Vector2D copy = *this;
    return copy -= other;
}

const Vector2D& Vector2D::operator*=(const float& multiplier) {
    this->x *= multiplier;
    this->y *= multiplier;
    return *this;
}

Vector2D Vector2D::operator*(const float& multiplier) const {
    Vector2D copy = *this;
    return copy *= multiplier;
}

Vector2D Vector2D::fromWorldToCamera(const Vector2D& camera_pos) const {
    return operator-(camera_pos);
}

Vector2D Vector2D::fromCameraToWorld(const Vector2D& camera_pos) const {
    return operator+(camera_pos);
}

AbstractShape::~AbstractShape() = default;

RectangleShape::RectangleShape(const Vector2D& lu_corner, const Vector2D& rd_corner):
    p_lu_corner(lu_corner),
    p_rd_corner(rd_corner) {}

bool RectangleShape::checkIntersection(const RectangleShape& other) const {
    return    !(p_lu_corner.x > other.p_rd_corner.x ||
                p_lu_corner.y < other.p_rd_corner.y ||
                p_rd_corner.x < other.p_lu_corner.x ||
                p_rd_corner.y > other.p_lu_corner.y);
}