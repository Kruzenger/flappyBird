#pragma once

#include <cstdint>
#include <string>

class GameObject;
class Component {
  public:
    virtual ~Component() = 0;

    virtual void onParentGameObjectInit() {}
    
    bool isDrawable() const;
    inline virtual std::string getTypeName() const = 0;

    void setParentObject(GameObject* object);
    
  protected:
    GameObject* p_parentObject;
};

inline Component::~Component() {}