#include "Component.h"
#include "BoxCollider.h"
#include "Rigidbody2D.h"

const float kPlayerJumpPower = 35;

class FlappyBirdPlayer : public Component {
  public:
    virtual void onParentGameObjectInit() override;
    
    inline virtual std::string getTypeName() const override { return "FlappyBirdPlayer"; }
    inline void addCollider(std::shared_ptr<BoxCollider> playerCollider) { p_collider = playerCollider; }  
    bool isAlive() const;
    
    void actionJump() const;

  protected:
    std::shared_ptr<BoxCollider> p_collider;  
    std::shared_ptr<Rigidbody2D> p_rigidbody;
};