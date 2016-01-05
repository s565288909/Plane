//
//  Bullet.hpp
//  MyPlane
//
//  Created by 史潇 on 15/12/31.
//
//

#ifndef Bullet_hpp
#define Bullet_hpp

#include <cocos2d.h>
#include <Enity.hpp>
#include <MyPlane.hpp>

USING_NS_CC;

class Bullet : public Enity{
public:
    Bullet();
    ~Bullet();
    virtual bool init();
    virtual void update(float delay);
    CREATE_FUNC(Bullet);
    bool isUsed();
    void initData(MyPlane* plane);
    void die();
private:
    bool used;
    float speed;
    MyPlane* _myPlane;
};

#endif /* Bullet_hpp */
