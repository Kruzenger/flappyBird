#include "FlappyBirdPlayer.h"
#include "../Engine.h"

void FlappyBirdPlayer::onParentGameObjectInit() {
    auto sharedParentObject = p_parentObject.lock();
    p_collider = sharedParentObject->findComponentByTypeName<BoxCollider>("BoxCollider");
    p_rigidbody = sharedParentObject->findComponentByTypeName<Rigidbody2D>("Rigidbody2D");
}

void FlappyBirdPlayer::actionJump() const { 
    p_rigidbody->setVelocity(Vector2D(p_rigidbody->getVelocity().x, kPlayerJumpPower)); 
}

bool FlappyBirdPlayer::isAlive() const { 
    auto sharedParentObject = p_parentObject.lock();
    return  p_collider->getCollisions().empty() && 
            sharedParentObject->getGlobalPosition().y < SCREEN_HEIGHT && 
            sharedParentObject->getGlobalPosition().y > 0; 

}