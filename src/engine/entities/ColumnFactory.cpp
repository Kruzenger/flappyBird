#include "ColumnFactory.h"
#include "../components/Rectangle.h"
#include "../components/BoxCollider.h"

ColumnFactory::ColumnFactory(
        const uint64_t& default_width, 
        const uint64_t& default_gap_hight, 
        const uint64_t& default_gap_position, 
        const uint32_t& default_color):
    p_default_width(default_width),
    p_default_gap_hight(default_gap_hight),
    p_default_gap_position(default_gap_position),
    p_default_color(default_color) {}

std::shared_ptr<GameObject> ColumnFactory::create() {
    return create(p_default_gap_hight, p_default_gap_position);
}

std::shared_ptr<GameObject> ColumnFactory::create(const uint64_t& gap_hight, const uint64_t& gap_pos) {
    std::shared_ptr<GameObject> column = std::make_shared<GameObject>();

    std::shared_ptr<GameObject> upper_column = std::make_shared<GameObject>();
    upper_column->addComponent(std::make_shared<Rectangle>(SCREEN_HEIGHT, p_default_width, p_default_color));
    upper_column->addComponent(std::make_shared<BoxCollider>(SCREEN_HEIGHT, p_default_width));
    upper_column->setPosition(0, -static_cast<int64_t>(SCREEN_HEIGHT - gap_pos));

    std::shared_ptr<GameObject> lower_column = std::make_shared<GameObject>();
    lower_column->addComponent(std::make_shared<Rectangle>(SCREEN_HEIGHT, p_default_width, p_default_color));
    lower_column->addComponent(std::make_shared<BoxCollider>(SCREEN_HEIGHT, p_default_width));
    lower_column->setPosition(0, static_cast<int64_t>(gap_pos + gap_hight));

    column->addChild(upper_column);
    column->addChild(lower_column);
    return column;
}