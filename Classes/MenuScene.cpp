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
#include "SceneManager.hpp"

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
    startgamelabel = Label::createWithTTF("Start Game", "fonts/arial.ttf", TITLE_FONT_SIZE);
    startgamelabel->setPosition(WINSIZE.width/2,WINSIZE.height/2);
    this->addChild(startgamelabel);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(MenuScene::myTouchBegin, this);
    listener->onTouchMoved = CC_CALLBACK_2(MenuScene::myTouchMove, this);
    listener->onTouchEnded = CC_CALLBACK_2(MenuScene::myTouchEnd, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    return true;
}

bool MenuScene::myTouchBegin(Touch *touch, Event *event){
    Vec2 vec = Pos;
    if (startgamelabel->getBoundingBox().containsPoint(vec)) {
        SceneManager::getInstance()->changeScene(SceneManager::GameStartScene);
    }
    return true;
}

void MenuScene::myTouchMove(Touch *touch, Event *event){

}

void MenuScene::myTouchEnd(Touch *touch, Event *event){}
