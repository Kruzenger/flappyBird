#include "Component.h"
#include "Drawable.h"

bool Component::isDrawable() const {
    return dynamic_pointer_cast<const Drawable>(shared_from_this()) != nullptr;
}

void Component::setParentObject(std::shared_ptr<GameObject> object) { 
    p_parentObject = object;
    onParentGameObjectInit(); 
}
