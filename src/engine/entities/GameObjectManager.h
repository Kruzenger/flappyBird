#pragma once

#include "../../utils/Singleton.h"
#include "GameObject.h"
#include <set>
#include <memory>

class GameObjectManager: public Singleton<GameObjectManager> {
  public:
    void renderObjects(const Vector2D& camera_pos);
    void addObject(std::shared_ptr<GameObject> object);
    void updateCollisions();
    void simulatePhysics(const float& dt);

    void updateGlobalPositionRecursivly(std::shared_ptr<GameObject> gameObject, const Vector2D& offset) const;
  
  private:
    std::shared_ptr<GameObject> _rootGameObject = std::make_shared<GameObject>();
    std::vector<std::shared_ptr<GameObject>> _colideableObjects;
    std::vector<std::shared_ptr<GameObject>> _rigidbodyObjects;

    void updateCollideableObjectsRecursivly(std::shared_ptr<GameObject> gameObject);
    void updateRigidbodyObjectsRecursivly(std::shared_ptr<GameObject> gameObject);
};