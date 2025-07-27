#include "UIDrawable.h"
#include "Rectangle.h"

class UIRectangle : public virtual UIDrawable, virtual Rectangle {
  public:
    virtual void draw(Vector2D offset) override;
};