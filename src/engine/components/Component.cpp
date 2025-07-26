#include "Component.h"
#include "Drawable.h"

bool Component::isDrawable() const {
    return dynamic_cast<const Drawable*>(this) != nullptr;
}

void Component::setParentObject(GameObject* object) { 
    p_parentObject = object;
    onParentGameObjectInit(); 
}
