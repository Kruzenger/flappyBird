#pragma once

#include "Component.h"
#include "../Engine.h"
#include "../Geometry.h"
#include <string>

class Drawable : public Component{
  public:
    virtual ~Drawable() {}
    
    virtual void draw(Vector2D offset) = 0;
};