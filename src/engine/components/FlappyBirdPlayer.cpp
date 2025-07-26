#include "FlappyBirdPlayer.h"

void FlappyBirdPlayer::onParentGameObjectInit() {
    p_collider = p_parentObject->findComponentByTypeName<BoxCollider>("BoxCollider");
    p_rigidbody = p_parentObject->findComponentByTypeName<Rigidbody2D>("Rigidbody2D");
}