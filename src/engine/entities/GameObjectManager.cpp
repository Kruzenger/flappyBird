#include "GameObjectManager.h"
#include "../components/BoxCollider.h"
#include "../components/Rigidbody2D.h"

void GameObjectManager::renderObjects(const Vector2D& camera_pos) {
    for(auto object : _rootGameObject->getChildren()) {
        object->render(Vector2D(0, 0));
    }
}

// TODO: Убрать зависимость от порядка добавления свойств. Нужно сделать
// отдельный метод с добавлением и обработкой всех полей и свойств, а при
// добавлении объекта в обработку или при добавлении новых компанент вызывать его.
void GameObjectManager::addObject(std::shared_ptr<GameObject> object) {
    _rootGameObject->addChild(object);
    updateRigidbodyObjectsRecursivly(object);
    updateCollideableObjectsRecursivly(object);
    updateGlobalPositionRecursivly(object, Vector2D(0, 0));
}

void GameObjectManager::updateCollisions() {
    for(auto object : _colideableObjects) {
        std::shared_ptr<BoxCollider> collider = object->findComponentByTypeName<BoxCollider>("BoxCollider");
        collider->clearCollisions();
    }

    for(auto object1 : _colideableObjects) {
        std::shared_ptr<BoxCollider> collider1 = object1->findComponentByTypeName<BoxCollider>("BoxCollider");
        for(auto object2 : _colideableObjects) {
            if(object1 == object2)
                continue;
                
            std::shared_ptr<BoxCollider> collider2 = object2->findComponentByTypeName<BoxCollider>("BoxCollider");
            if(collider1->checkCollision(collider2)) {
                collider1->addCollision(collider2);
                collider2->addCollision(collider1);
            }
        }
    }
}

void GameObjectManager::simulatePhysics(const float& dt) {
    for(auto object : _rigidbodyObjects) {
        object->findComponentByTypeName<Rigidbody2D>("Rigidbody2D")->simulatePhysics(dt);
    }
}

void GameObjectManager::updateCollideableObjectsRecursivly(std::shared_ptr<GameObject> gameObject) {
    if(gameObject) {
        if(gameObject->findComponentByTypeName<BoxCollider>("BoxCollider")){
            _colideableObjects.push_back(gameObject);
        }
        for(auto object : gameObject->getChildren()) {
            if(object->findComponentByTypeName<BoxCollider>("BoxCollider")){
                updateCollideableObjectsRecursivly(object);
            }
        }
    }
}

void GameObjectManager::updateRigidbodyObjectsRecursivly(std::shared_ptr<GameObject> gameObject) {
    if(gameObject) {
        if(gameObject->findComponentByTypeName<Rigidbody2D>("Rigidbody2D")){
            _rigidbodyObjects.push_back(gameObject);
        }
        for(auto object : gameObject->getChildren()) {
            if(object->findComponentByTypeName<Rigidbody2D>("Rigidbody2D")){
                updateRigidbodyObjectsRecursivly(object);
            }
        }
    }
}

void GameObjectManager::updateGlobalPositionRecursivly(std::shared_ptr<GameObject> gameObject, const Vector2D& offset) const {
    if(gameObject) {
        gameObject->setGlobalPosition(gameObject->getLocalPosition() + offset);
        for(auto object : gameObject->getChildren()) {
            updateGlobalPositionRecursivly(object, gameObject->getGlobalPosition());
        }
    }
}