//
//  MenuScene.hpp
//  MyPlane
//
//  Created by 史潇 on 15/12/26.
//
//

#ifndef MenuScene_hpp
#define MenuScene_hpp

#include <cocos2d.h>
#include "Bg.hpp"

USING_NS_CC;

class MenuScene : public Layer
{
public:
    static Scene* creatScene();
    CREATE_FUNC(MenuScene);
    virtual bool init();
private:
    Bg* bg;
};

#endif /* MenuScene_hpp */
