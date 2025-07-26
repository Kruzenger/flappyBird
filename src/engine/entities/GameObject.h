#pragma once

#include "../components/Component.h"
#include "../Geometry.h"
#include <vector>
#include <string>
#include <memory>

class GameObject : public std::enable_shared_from_this<GameObject> {
  public:
    void render(Vector2D offset);
    void addComponent(std::shared_ptr<Component> component);
    void addChild(std::shared_ptr<GameObject> child);

    template <typename T>
    std::shared_ptr<T> findComponentByTypeName(const std::string& typeName) const {
        for(auto component : p_components) {
            if(component->getTypeName() == typeName) {
                return std::dynamic_pointer_cast<T>(component);
            }
        }
        return nullptr; 
    }

    const Vector2D& changePosition(const Vector2D& delta_pos);
    const Vector2D& changePosition(const int64_t& delta_x, const int64_t& delta_y);
    const Vector2D& setLocalPosition(const Vector2D& newPos);
    const Vector2D& setLocalPosition(const int64_t& new_x, const int64_t& new_y);
    const Vector2D& setGlobalPosition(const Vector2D& newPos);
    inline const Vector2D& getLocalPosition() const { return p_localPosition; }
    inline const Vector2D& getGlobalPosition() const { return p_globalPosition; }

    bool CheckCollision();
    inline const int64_t& getPriority() const {return p_priority; }
    inline std::vector<std::shared_ptr<GameObject>>& getChildren() { return p_children; }
    
  protected:
    std::vector<std::shared_ptr<Component>> p_components;
    std::vector<std::shared_ptr<GameObject>> p_children;
    Vector2D p_localPosition;
    Vector2D p_globalPosition;

    int64_t p_priority;
};