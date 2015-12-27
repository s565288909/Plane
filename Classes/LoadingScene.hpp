//
//  LoadingScene.hpp
//  MyPlane
//
//  Created by 史潇 on 15/12/26.
//
//

#ifndef LoadingScene_hpp
#define LoadingScene_hpp

#include <cocos2d.h>

USING_NS_CC;

class LoadingScene : public Layer{
public:
    static Scene* createScene();
    CREATE_FUNC(LoadingScene);
    virtual bool init();
    virtual void onExit();
private:
    void loadingAssets();
    void loadingAudio();
    void changeScene(float delay);
    void loadOver(Texture2D* texture);
    int loadNum;
    std::thread* _loadAudioThread;
};

#endif /* LoadingScene_hpp */
