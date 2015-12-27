//
//  Bg.cpp
//  MyPlane
//
//  Created by 史潇 on 15/12/26.
//
//

#include "Bg.hpp"
#include "GlobalDefine.hpp"

USING_NS_CC;

Bg::Bg(){}
Bg::~Bg(){}

bool Bg::init(){
    if (!Node::init()) {
        return false;
    }
    bg1 = Sprite::createWithTexture(TCache->getTextureForKey(Image_Bg_1));
    bg2 = Sprite::createWithTexture(TCache->getTextureForKey(Image_Bg_2));
    
    bg1->setScale(WINSIZE.width/bg1->getContentSize().width, WINSIZE.height/bg1->getContentSize().height);
    bg2->setScale(WINSIZE.width/bg2->getContentSize().width, WINSIZE.height/bg2->getContentSize().height);
    
    bg1->setPosition(WINSIZE.width/2, WINSIZE.height/2);
    bg2->setPosition(WINSIZE.width/2,WINSIZE.height*1.5f);
    
    this->addChild(bg1);
    this->addChild(bg2);
    
    speed = 2;
    
    this->scheduleUpdate();
    return true;
}

void Bg::update(float delta){
    bg1->setPosition(bg1->getPosition().x,bg1->getPosition().y-speed);
    bg2->setPosition(bg2->getPosition().x,bg2->getPosition().y-speed);
    if (bg1->getPosition().y < -WINSIZE.height/2) {
        bg1->setPosition(bg1->getPosition().x,bg2->getPosition().y+WINSIZE.height);
    }
    else if(bg2->getPosition().y < -WINSIZE.height/2){
        bg2->setPosition(bg2->getPosition().x,bg1->getPosition().y+WINSIZE.height);
    }
}
