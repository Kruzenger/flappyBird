#include "UIRectangle.h"
#include "../entities/GameObjectManager.h"

RectangleUI::RectangleUI(const uint64_t& hight, const uint64_t& width, const uint32_t& color): 
    p_hight(hight),
    p_width(width),
    p_color(color) {}

void RectangleUI::draw(Vector2D offset) {
    auto sharedParentObject = p_parentObject.lock();
    auto startPoint = sharedParentObject->getLocalPosition() + offset; 
    int64_t i = startPoint.y > 0 ? startPoint.y : 0;
    for(; i < startPoint.y + static_cast<int64_t>(p_hight) && i < SCREEN_HEIGHT; ++i) {
        int64_t j = startPoint.x > 0 ? startPoint.x : 0;
        for(; j < startPoint.x + static_cast<int64_t>(p_width) && j < SCREEN_WIDTH; ++j) {
            buffer[SCREEN_HEIGHT - i - 1][j] = p_color;
        }
    }
}