#include "BoxCollider.h"

BoxCollider::BoxCollider(const Vector2D& lu_corner, const Vector2D& rd_corner): 
    p_lu_corner(lu_corner), p_rd_corner(rd_corner) {}

BoxCollider::BoxCollider(const uint64_t& hight, const uint64_t& width):
    p_lu_corner(0, 0), p_rd_corner(width, hight) {}

void BoxCollider::addCollision(std::shared_ptr<BoxCollider> collision) {
    p_collisions.push_back(collision);
}

bool BoxCollider::checkCollision(std::shared_ptr<BoxCollider> other) const {
    auto sharedParentObject = p_parentObject.lock();
    auto other_sharedParentObject = other->p_parentObject.lock();
    Vector2D lu_corner = p_lu_corner + sharedParentObject->getGlobalPosition();
    Vector2D rd_corner = p_rd_corner + sharedParentObject->getGlobalPosition();
    Vector2D other_lu_corner = other->p_lu_corner + other_sharedParentObject->getGlobalPosition();
    Vector2D other_rd_corner = other->p_rd_corner + other_sharedParentObject->getGlobalPosition();
    return    !(lu_corner.x > other_rd_corner.x ||
                lu_corner.y > other_rd_corner.y ||
                rd_corner.x < other_lu_corner.x ||
                rd_corner.y < other_lu_corner.y);
}