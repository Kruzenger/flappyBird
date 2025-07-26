#pragma once

#include "../components/Component.h"
#include "../Geometry.h"
#include <vector>
#include <string>

class GameObject {
  public:
    void render(Vector2D offset);
    void addComponent(Component* component);
    void addChild(GameObject* child);

    template <typename T>
    T* findComponentByTypeName(const std::string& typeName) const {
        for(auto component : p_components) {
            if(component->getTypeName() == typeName) {
                return dynamic_cast<T*>(component);
            }
        }
        return nullptr; 
    }

    const Vector2D& changePosition(const Vector2D& delta_pos);
    const Vector2D& changePosition(const int64_t& delta_x, const int64_t& delta_y);
    const Vector2D& setPosition(const Vector2D& newPos);
    inline const Vector2D& setGlobalPosition(const Vector2D& newPos) { return p_globalPosition = newPos; }
    const Vector2D& setPosition(const int64_t& new_x, const int64_t& new_y);
    inline const Vector2D& getLocalPosition() const { return p_localPosition; }
    inline const Vector2D& getGlobalPosition() const { return p_globalPosition; }

    bool CheckCollision();
    inline const int64_t& getPriority() const {return p_priority; }
    inline std::vector<GameObject*>& getChildren() { return p_children; }
    
  protected:
    std::vector<Component*> p_components;
    std::vector<GameObject*> p_children;
    Vector2D p_localPosition;
    Vector2D p_globalPosition;

    int64_t p_priority;
};