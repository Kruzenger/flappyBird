#pragma once

#include "../../utils/AbstractFactory.h"
#include "GameObject.h"

class ColumnFactory : public AbstractFactory<GameObject> {
  public:
    ColumnFactory(
            const uint64_t& default_width, 
            const uint64_t& default_gap_hight, 
            const uint64_t& default_gap_position, 
            const uint32_t& default_color);

    std::shared_ptr<GameObject> create() override;
    std::shared_ptr<GameObject> create(const uint64_t& gap_hight, const uint64_t& gap_pos);
    
  protected:
    uint64_t p_default_width;
    uint64_t p_default_gap_hight;
    uint64_t p_default_gap_position;
    uint32_t p_default_color;
};