//
//  Enity.cpp
//  MyPlane
//
//  Created by 史潇 on 15/12/28.
//
//

#include "Enity.hpp"


USING_NS_CC;

Enity::Enity(){}

Enity::~Enity(){}

void Enity::bindSprite(Sprite *sprite){
    mSprite = sprite;
    isBindSprite = true;
    mSprite->setAnchorPoint(Vec2(0, 0));
    this->addChild(mSprite);
    this->setContentSize(mSprite->getContentSize());
    this->setAnchorPoint(Vec2(0.5f, 0.5f));
    auto body = PhysicsBody::createBox(this->getContentSize());
    switch (enityType) {
        case PLANE:
            body->setCategoryBitmask(PlaneMask);
            body->setCollisionBitmask(NullMask);
            body->setContactTestBitmask(EnemyMask);
            break;
        case BULLET:
            body->setCategoryBitmask(BulletMask);
            body->setCollisionBitmask(NullMask);
            body->setContactTestBitmask(EnemyMask);
            break;
        case ENEMY:
            body->setCategoryBitmask(EnemyMask);
            body->setCollisionBitmask(NullMask);
            body->setContactTestBitmask(BulletMask | PlaneMask);
            break;
        default:
            break;
    }
    this->setPhysicsBody(body);
    
}
