#pragma once

#include <cstdint>
#include <string>
#include <memory>

class GameObject;
class Component : public std::enable_shared_from_this<Component> {
  public:
    virtual ~Component() = 0;

    inline virtual std::string getTypeName() const = 0;
    virtual void onParentGameObjectInit() {}
    bool isDrawable() const;
    void setParentObject(std::shared_ptr<GameObject> object);
    
  protected:
    std::shared_ptr<GameObject> p_parentObject;
};

inline Component::~Component() {}