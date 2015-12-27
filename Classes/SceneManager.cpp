//
//  SceneManager.cpp
//  MyPlane
//
//  Created by 史潇 on 15/12/27.
//
//

#include "SceneManager.hpp"
#include "LoadingScene.hpp"
#include "MenuScene.hpp"

USING_NS_CC;

SceneManager* SceneManager::mSceneManager = NULL;

SceneManager* SceneManager::getInstance(){
    if (mSceneManager==NULL) {
        mSceneManager = new SceneManager();
    }
    return mSceneManager;
}

void SceneManager::changeScene(SceneType sceneType){
    Scene* scene = NULL;
    switch (sceneType) {
        case LoadingScene:
            scene = LoadingScene::createScene();
            break;
        case MenuScene:
            scene = MenuScene::creatScene();
        default:
            break;
    }
    
    if (scene==NULL) {
        return;
    }
    Director* director = Director::getInstance();
    Scene* curScene = director->getRunningScene();
    if (curScene==NULL) {
        director->runWithScene(scene);
    }else{
        director->replaceScene(TransitionFade::create(1.5, scene));
    }
}
