//
//  Bg.hpp
//  MyPlane
//
//  Created by 史潇 on 15/12/26.
//
//

#ifndef Bg_hpp
#define Bg_hpp

#include <cocos2d.h>

USING_NS_CC;

class Bg : public Node{
public:
    Bg();
    ~Bg();
    CREATE_FUNC(Bg);
    virtual bool init();
    virtual void update(float delta);
private:
    Sprite* bg1;
    Sprite* bg2;
    float speed;
};

#endif /* Bg_hpp */
