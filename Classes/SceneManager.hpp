//
//  SceneManager.hpp
//  MyPlane
//
//  Created by 史潇 on 15/12/27.
//
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include <cocos2d.h>

USING_NS_CC;

class SceneManager : public Ref
{
public:
    enum SceneType{
        LoadingScene,
        MenuScene,
        GameStartScene,
        GameOverScene
    };
    static SceneManager* getInstance();
    void changeScene(SceneType sceneType);
    
private:
    static SceneManager* mSceneManager;
};

#endif /* SceneManager_hpp */
