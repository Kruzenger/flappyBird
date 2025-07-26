#pragma once

#include "Component.h"
#include "../Geometry.h"

const float kGForce = 9.82f; // we are in Homel, Belarus))) (p.s. in different cities G-force is slightly different)
const Vector2D kGForceDirection = Vector2D(0, -1);
const float kSpeed = 10.0;
const Vector2D kStartVelocity = Vector2D(25, -25);

class Rigidbody2D : public Component {
  public:
    Rigidbody2D() = default;
    Rigidbody2D(bool isAffectedByPhisics);

    inline virtual std::string getTypeName() const override { return "Rigidbody2D"; }
    inline void setVelocity(const Vector2D& value) { p_velocity = value; }
    inline const Vector2D& getVelocity() { return p_velocity; }
    void simulatePhysics(const float& dt);

  protected:
    bool p_isAffectedByGravity = true;  
    Vector2D p_velocity = kStartVelocity;
};