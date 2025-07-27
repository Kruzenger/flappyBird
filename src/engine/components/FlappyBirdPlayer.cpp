#include "FlappyBirdPlayer.h"
#include "../Engine.h"

void FlappyBirdPlayer::onParentGameObjectInit() {
    p_collider = p_parentObject->findComponentByTypeName<BoxCollider>("BoxCollider");
    p_rigidbody = p_parentObject->findComponentByTypeName<Rigidbody2D>("Rigidbody2D");
}

void FlappyBirdPlayer::actionJump() const { 
    p_rigidbody->setVelocity(Vector2D(p_rigidbody->getVelocity().x, kPlayerJumpPower)); 
}

bool FlappyBirdPlayer::isAlive() const { 
    return p_collider->getCollisions().empty() && p_parentObject->getGlobalPosition().y < SCREEN_HEIGHT && p_parentObject->getGlobalPosition().y > 0; 

}