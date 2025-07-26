#pragma once

#include "Drawable.h"

class Rectangle : public Drawable {
  public:
    Rectangle() = delete;
    Rectangle(const uint64_t& hight, const uint64_t& length, const uint32_t& color = 0);

    inline virtual std::string getTypeName() const override { return "Rectangle"; }
    virtual void draw(Vector2D offset) override;

  protected:
    uint64_t p_hight;
    uint64_t p_width;
    uint32_t p_color = 0;
};