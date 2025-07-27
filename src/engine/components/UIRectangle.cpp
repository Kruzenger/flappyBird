#include "UIRectangle.h"
#include "../entities/GameObjectManager.h"

void UIRectangle::draw(Vector2D offset) {
    auto startPoint = Rectangle::p_parentObject->getLocalPosition()
                                                .fromWorldToCamera(GameObjectManager::getInstance()
                                                                                     .getCamera()
                                                                                    ->getGlobalPosition()) + offset; 
    int64_t i = startPoint.y > 0 ? startPoint.y : 0;
    for(; i < startPoint.y + static_cast<int64_t>(p_hight) && i < SCREEN_HEIGHT; ++i) {
        int64_t j = startPoint.x > 0 ? startPoint.x : 0;
        for(; j < startPoint.x + static_cast<int64_t>(p_width) && j < SCREEN_WIDTH; ++j) {
            buffer[SCREEN_HEIGHT - i - 1][j] = p_color;
        }
    }
}