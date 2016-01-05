//
//  MyPlane.hpp
//  MyPlane
//
//  Created by 史潇 on 15/12/28.
//
//

#ifndef MyPlane_hpp
#define MyPlane_hpp

#include <cocos2d.h>
#include <Enity.hpp>

USING_NS_CC;

class MyPlane : public Enity {
public:
    MyPlane();
    ~MyPlane();
    virtual bool init();
    CREATE_FUNC(MyPlane);
    bool myTouchBegin(Touch* touch, Event* event);
    void myTouchMove(Touch* touch, Event* event);
    void myTouchEnd(Touch* touch, Event* event);
    void die();
    bool isDead();
private:
    float moveX,moveY;
    bool touchedPlane;
    bool dead = false;
};

#endif /* MyPlane_hpp */
