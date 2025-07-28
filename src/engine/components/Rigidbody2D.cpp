#include "Rigidbody2D.h"
#include "../entities/GameObject.h"

Rigidbody2D::Rigidbody2D(bool isAffectedByPhisics): p_isAffectedByGravity(isAffectedByPhisics) {}

void Rigidbody2D::simulatePhysics(const float& dt) {
    if (p_isAffectedByGravity) {
        p_velocity += kGForceDirection * dt * (kGForce * 4);
    }
    auto sharedParentObject = p_parentObject.lock();
    sharedParentObject->changePosition(p_velocity * dt * kSpeed);
}