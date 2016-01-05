//
//  MyPlane.cpp
//  MyPlane
//
//  Created by 史潇 on 15/12/28.
//
//

#include "MyPlane.hpp"
#include "GlobalDefine.hpp"

USING_NS_CC;

MyPlane::MyPlane(){}

MyPlane::~MyPlane(){}

bool MyPlane::init(){
    if (!Node::init()) {
        return false;
    }
    enityType = PLANE;
    touchedPlane = false;
    
    bindSprite(Sprite::createWithSpriteFrameName(Image_Plane_1));
    auto animate = Animate::create(AniCache->getAnimation(Ani_Plane));
    mSprite->runAction(animate);
//    this->addChild(mSprite);
//    this->setAnchorPoint(Vec2(0.5f, 0.5f));
    this->setPosition(WINSIZE.width/2,100);
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(MyPlane::myTouchBegin, this);
    listener->onTouchMoved = CC_CALLBACK_2(MyPlane::myTouchMove, this);
    listener->onTouchEnded = CC_CALLBACK_2(MyPlane::myTouchEnd, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}

void MyPlane::die(){
    dead = true;
    this->getPhysicsBody()->setEnabled(false);
    mSprite->stopAllActions();
    auto animation = AniCache->getAnimation(Ani_Boom);
    animation->setLoops(0.5f);
    animation->setDelayPerUnit(1);
    animation->setRestoreOriginalFrame(false);
    auto animate = Animate::create(animation);
    mSprite->runAction(Sequence::create(animate,DelayTime::create(1),CallFunc::create([&]{
        this->removeFromParent();
    }), NULL));
    _eventDispatcher->removeEventListenersForTarget(this);
}

bool MyPlane::isDead(){return dead;}


bool MyPlane::myTouchBegin(Touch *touch, Event *event){
    Vec2 vec = Pos;
    if (this->getBoundingBox().containsPoint(vec)) {
        moveX = vec.x;
        moveY = vec.y;
        touchedPlane = true;
    }
    return true;
}

void MyPlane::myTouchMove(Touch *touch, Event *event){
    if (touchedPlane) {
        Vec2 vec = Pos;
        Point pos = this->getPosition();
        this->setPosition(pos.x+(vec.x-moveX),pos.y+(vec.y-moveY));
        moveX = vec.x;
        moveY = vec.y;
    }
}

void MyPlane::myTouchEnd(Touch *touch, Event *event){
    touchedPlane = false;
}
