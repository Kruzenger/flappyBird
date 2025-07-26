#include "Rigidbody2D.h"
#include "../entities/GameObject.h"

Rigidbody2D::Rigidbody2D(bool isAffectedByPhisics): p_isAffectedByGravity(isAffectedByPhisics) {}

void Rigidbody2D::simulatePhysics(const float& dt) {
    if (p_isAffectedByGravity) {
        p_velocity += Vector2D(0, dt * kGForce * 4);
    }
    p_parentObject->changePosition(p_velocity * dt * kSpeed);
}