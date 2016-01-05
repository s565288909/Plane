//
//  LoadingScene.cpp
//  MyPlane
//
//  Created by 史潇 on 15/12/26.
//
//

#include "LoadingScene.hpp"
#include "GlobalDefine.hpp"
#include "AppMacros.h"
#include "SimpleAudioEngine.h"
#include "SceneManager.hpp"
#include "AnimationUtils.hpp"

USING_NS_CC;

Scene* LoadingScene::createScene(){
    auto scene = Scene::create();
    auto layer = LoadingScene::create();
    scene->addChild(layer);
    return scene;
}

bool LoadingScene::init(){
    if (!Layer::init()) {
        return false;
    }
    loadNum = 0;
    auto lable = Label::createWithTTF("Loading", "fonts/arial.ttf", TITLE_FONT_SIZE);
    this->addChild(lable);
    lable->setPosition(WINSIZE.width/2,WINSIZE.height/2);
    loadingAssets();
    return true;
}

void LoadingScene::loadingAssets(){
    TCache->addImageAsync(Image_Main, CC_CALLBACK_1(LoadingScene::loadOver, this));
    TCache->addImageAsync(Image_Bg_1,CC_CALLBACK_1(LoadingScene::loadOver, this));
    TCache->addImageAsync(Image_Bg_2, CC_CALLBACK_1(LoadingScene::loadOver, this));
    _loadAudioThread = new std::thread(&LoadingScene::loadingAudio,this);
}

void LoadingScene::loadingAudio(){
    Audio->preloadEffect(Audio_Effect_boom);
    Audio->preloadEffect(Audio_Effect_shoot);
}

void LoadingScene::loadOver(Texture2D* texture){
    loadNum++;
    if (loadNum==1) {
        SpriteFrameCache::getInstance()->addSpriteFramesWithFile(Plist_Main);
        AnimationUtils::createAniWithPlist(Ani_Plane, 0.3f, -1);
        AnimationUtils::createAniWithPlist(Ani_Boom, 0.1f, 1);
    }
    if (loadNum==3) {
        this->scheduleOnce(schedule_selector(LoadingScene::changeScene), 1);
    }
}

void LoadingScene::changeScene(float delay){
    CCLOG("over");
    SceneManager::getInstance()->changeScene(SceneManager::MenuScene);
}

void LoadingScene::onExit(){
    Layer::onExit();
    _loadAudioThread->join();
    CC_SAFE_DELETE(_loadAudioThread);
}