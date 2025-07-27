#pragma once

#include "../../utils/Singleton.h"
#include "GameObject.h"
#include <set>
#include <memory>

class GameObjectManager: public Singleton<GameObjectManager> {
  public:
    void renderObjects(const Vector2D& offset);
    void renderUI(const Vector2D& offset);
    void addObject(std::shared_ptr<GameObject> object);
    void addObjectUI(std::shared_ptr<GameObject> object);

    inline void addCamera(std::shared_ptr<GameObject> camera) { _mainCamera = camera; } 
    inline std::shared_ptr<GameObject> getCamera() { return _mainCamera; }
    void updateCollisions();
    void simulatePhysics(const float& dt);

  private:
    std::shared_ptr<GameObject> _rootGameObject = std::make_shared<GameObject>();
    std::shared_ptr<GameObject> _rootGameObjectUI = std::make_shared<GameObject>();
    std::vector<std::shared_ptr<GameObject>> _colideableObjects;
    std::vector<std::shared_ptr<GameObject>> _rigidbodyObjects;
    std::shared_ptr<GameObject> _mainCamera;

    void updateCollideableObjectsRecursivly(std::shared_ptr<GameObject> gameObject);
    void updateRigidbodyObjectsRecursivly(std::shared_ptr<GameObject> gameObject);
    void updateGlobalPositionRecursivly(std::shared_ptr<GameObject> gameObject, const Vector2D& offset) const;
};