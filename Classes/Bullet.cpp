//
//  Bullet.cpp
//  MyPlane
//
//  Created by 史潇 on 15/12/31.
//
//

#include "Bullet.hpp"
#include "GlobalDefine.hpp"

Bullet::Bullet(){};

Bullet::~Bullet(){};

bool Bullet::init(){
    enityType = BULLET;
    bindSprite(Sprite::createWithSpriteFrameName(Image_Bullet));
    this->scheduleUpdate();
    return true;
}

bool Bullet::isUsed(){
    return used;
}

void Bullet::initData(MyPlane *plane){
    _myPlane = plane;
    speed = 20;
    this->setPosition(_myPlane->getPosition().x,_myPlane->getPosition().y+50);
    //other
    used = true;
    this->setVisible(true);
    this->getPhysicsBody()->setEnabled(true);
    //initData时播放音效
    Audio->playEffect(Audio_Effect_shoot);
}

void Bullet::die(){
    used = false;
    this->setVisible(false);
    this->getPhysicsBody()->setEnabled(false);
}

void Bullet::update(float delay){
    this->setPosition(this->getPosition().x, this->getPosition().y+speed);
    if (this->getPosition().y - this->getContentSize().height/2 > WINSIZE.height) {
        die();
    }
}