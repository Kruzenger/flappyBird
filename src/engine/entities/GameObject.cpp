#include "GameObject.h"
#include "../components/Drawable.h"

void GameObject::render(Vector2D offset) {
    for(auto component : p_components) {
        if(component->isDrawable()) {
            dynamic_cast<Drawable*>(component)->draw(offset);
        }
    }

    for(auto child : p_children) {
        child->render(offset + child->getLocalPosition());
    }
}

void GameObject::addComponent(Component* component) {
    p_components.push_back(component);
    component->setParentObject(this);
}

void GameObject::addChild(GameObject* child) {
    p_children.push_back(child);
}

const Vector2D& GameObject::changePosition(const Vector2D& delta_pos) {
    p_localPosition += delta_pos;
    p_globalPosition += delta_pos;
    return p_localPosition;
}

const Vector2D& GameObject::setPosition(const Vector2D& new_pos) {
    p_localPosition = new_pos;
    return p_localPosition;
}

const Vector2D& GameObject::setPosition(const int64_t& new_x, const int64_t& new_y) {
    p_localPosition.x = new_x;
    p_localPosition.y = new_y;
    return p_localPosition;
}