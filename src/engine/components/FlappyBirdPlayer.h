#include "Component.h"
#include "BoxCollider.h"
#include "Rigidbody2D.h"

class FlappyBirdPlayer : public Component {
  public:

    virtual void onParentGameObjectInit() override;
    
    inline virtual std::string getTypeName() const override { return "FlappyBirdPlayer"; }
    inline void addCollider(BoxCollider* playerCollider) { p_collider = playerCollider; }  
    inline bool isAlive() const { return p_collider->getCollisions().empty(); }

    inline void actionJump() const { p_rigidbody->setVelocity(Vector2D(p_rigidbody->getVelocity().x, -35)); }

  protected:
    BoxCollider* p_collider;  
    Rigidbody2D* p_rigidbody;
};