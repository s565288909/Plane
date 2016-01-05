//
//  Enemy.cpp
//  MyPlane
//
//  Created by 史潇 on 16/1/2.
//
//

#include "Enemy.hpp"
#include <stdlib.h>

Enemy::Enemy(){}

Enemy::~Enemy(){}

bool Enemy::init(){
    if (!Node::init()) {
        return false;
    }
    enityType = ENEMY;
    mType = small;
    return true;
}

void Enemy::initData(EnemyType type){
    switch (type) {
        case small:
            if (!isBindSprite || mType != small) {
                bindSprite(Sprite::createWithSpriteFrameName(Image_EnemyPlane));
            }
            mType = small;
            hp = 1;
            speed = 5;
            srand ((unsigned)time(nullptr));
            int _ran = rand()%(int)(WINSIZE.width - this->getContentSize().width)+ this->getContentSize().width/2;
            this->setPosition(_ran,WINSIZE.height+this->getContentSize().height);
            break;
    }
    used = true;
    this->setVisible(true);
    this->getPhysicsBody()->setEnabled(true);
}

bool Enemy::isAttack(){
    hp--;
    if (hp<=0) {
        BoomAndDie();
        return true;
    }
    return false;
}

void Enemy::Die(){
    used = false;
    this->setVisible(false);
    this->getPhysicsBody()->setEnabled(false);
}

void Enemy::BoomAndDie(){
    Audio->playEffect(Audio_Effect_boom);
    this->getPhysicsBody()->setEnabled(false);
    auto animate = Animate::create(AniCache->getAnimation(Ani_Boom));
    mSprite->runAction(Sequence::create(animate,CallFunc::create([&]{
        Die();
    }), NULL));
}

bool Enemy::isUsed(){return used;}

void Enemy::update(float delta){
    this->setPosition(this->getPosition().x, this->getPosition().y-speed);
    if (this->getPosition().y + this->getContentSize().height/2 < 0) {
        Die();
    }
}

