#include "Rectangle.h"

Rectangle::Rectangle(const uint64_t& hight, const uint64_t& width, const uint32_t& color): 
    p_hight(hight),
    p_width(width),
    p_color(color) {}

// Так как появилось понятие глобальных координат, то можно от офсета избавиться,
// кажется лучше просто переписать метод, а офсет оставить на случай необхадимости сдвига
void Rectangle::draw(Vector2D offset) {
    int64_t i = offset.y > 0 ? offset.y : 0;
    for(; i < offset.y + static_cast<int64_t>(p_hight) && i < SCREEN_HEIGHT; ++i) {
        int64_t j = offset.x > 0 ? offset.x : 0;
        for(; j < offset.x + static_cast<int64_t>(p_width) && j < SCREEN_WIDTH; ++j) {
            buffer[SCREEN_HEIGHT - i - 1][j] = p_color;
        }
    }
}