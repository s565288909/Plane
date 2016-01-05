//
//  GameScene.hpp
//  MyPlane
//
//  Created by 史潇 on 15/12/28.
//
//

#ifndef GameScene_hpp
#define GameScene_hpp

#include <cocos2d.h>
#include <MyPlane.hpp>
#include <Bullet.hpp>
#include <Bg.hpp>
#include <Enemy.hpp>

USING_NS_CC;

class GameScene : public Layer{
public:
    static Scene* createScene();
    virtual bool init();
    virtual void update(float delay);
    CREATE_FUNC(GameScene);
private:
    Bg* _bg;
    MyPlane* _myplane;
    Label* _score;
    Label* _restart;
    Label* _exit;
    int score;
    float moveX,moveY;
    bool touchedPlane;
    bool myTouchBegin(Touch* touch, Event* event);
    void myTouchMove(Touch* touch, Event* event);
    void myTouchEnd(Touch* touch, Event* event);
    void createBullets(float delay);
    void createEnemy(float delay);
    Vector<Bullet*> planeBulletsPool;
    struct{
        unsigned int left = 0;
        unsigned int min = 10;
    }data;
    Vector<Enemy*> enemyPool;
    struct{
        unsigned int left = 0;
        unsigned int min = 10;
    }enemypoolnum;
    bool gameover;
    bool onContactBegin(const PhysicsContact& contact);
};

#endif /* GameScene_hpp */
