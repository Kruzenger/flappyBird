#pragma once

#include "Component.h"
#include "../Geometry.h"
#include "../entities/GameObject.h"
#include <vector>

class BoxCollider : public Component {
  public:
    BoxCollider() = default;
    BoxCollider(const Vector2D& lu_corner, const Vector2D& rd_corner);
    BoxCollider(const uint64_t& hight, const uint64_t& width);

    inline void clearCollisions() { p_collisions.clear(); }
    void addCollision(std::shared_ptr<BoxCollider> collision);
    bool checkCollision(std::shared_ptr<BoxCollider> other) const;
    inline std::vector<std::shared_ptr<BoxCollider>>& getCollisions() { return p_collisions; }
    inline virtual std::string getTypeName() const override { return "BoxCollider"; }

  protected:
    std::vector<std::shared_ptr<BoxCollider>> p_collisions;  
    Vector2D p_lu_corner;
    Vector2D p_rd_corner;
};