#pragma once

#include "../../utils/Singleton.h"
#include "GameObject.h"
#include <set>

class GameObjectManager: public Singleton<GameObjectManager> {
  public:
    void renderObjects(const Vector2D& camera_pos);
    void addObject(GameObject* object);
    void updateCollisions();
    void simulatePhysics(const float& dt);

    void updateGlobalPositionRecursivly(GameObject* gameObject, const Vector2D& offset) const;
  
  private:
    GameObject* _rootGameObject = new GameObject();
    std::vector<GameObject*> _colideableObjects;
    std::vector<GameObject*> _rigidbodyObjects;

    void updateCollideableObjectsRecursivly(GameObject* gameObject);
    void updateRigidbodyObjectsRecursivly(GameObject* gameObject);
};