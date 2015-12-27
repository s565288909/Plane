//
//  MenuScene.cpp
//  MyPlane
//
//  Created by 史潇 on 15/12/26.
//
//

#include "MenuScene.hpp"
#include "AppMacros.h"
#include "GlobalDefine.hpp"

USING_NS_CC;

Scene* MenuScene::creatScene()
{
    auto scene = Scene::create();
    auto layer = MenuScene::create();
    scene->addChild(layer);
    return scene;
}

bool MenuScene::init(){
    if (!Layer::init()) {
        return false;
    }
    bg = Bg::create();
    this->addChild(bg);
    auto label = Label::createWithTTF("Start Game", "fonts/arial.ttf", TITLE_FONT_SIZE);
    label->setPosition(WINSIZE.width/2,WINSIZE.height/2);
    
    return true;
}