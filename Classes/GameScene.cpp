//
//  GameScene.cpp
//  MyPlane
//
//  Created by 史潇 on 15/12/28.
//
//

#include "GameScene.hpp"
#include "AppMacros.h"
#include "SceneManager.hpp"

USING_NS_CC;

Scene* GameScene::createScene(){
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setGravity(Vec2(0, 0));
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    auto layer = GameScene::create();
    scene->addChild(layer);
    return scene;
}

bool GameScene::init(){
    if (!Layer::init()) {
        return false;
    }
    gameover = false;
    
    _bg = Bg::create();
    this->addChild(_bg);
    
    _myplane = MyPlane::create();
    this->addChild(_myplane);
    
    score = 0;
    _score = Label::createWithTTF("SCORE:"+Value(score).asString(), "fonts/Marker Felt.ttf", GAME_FONT_SIZE);
    _score->setAnchorPoint(Vec2(0, 0));
    _score->setPosition(0,WINSIZE.height - GAME_FONT_SIZE - 15);
    this->addChild(_score);
    
    _restart = Label::createWithTTF("Restart", "fonts/arial.ttf", TITLE_FONT_SIZE);
    _restart->setPosition(WINSIZE.width/2,WINSIZE.height/2+50);
    this->addChild(_restart);
    
    _exit = Label::createWithTTF("Exit", "fonts/arial.ttf", TITLE_FONT_SIZE);
    _exit->setPosition(WINSIZE.width/2,WINSIZE.height/2-50);
    this->addChild(_exit);
    
    _restart->setVisible(false);
    _exit->setVisible(false);
    
    planeBulletsPool.clear();
    enemyPool.clear();
    
    this->schedule(schedule_selector(GameScene::createBullets),0.3);
    this->schedule(schedule_selector(GameScene::createEnemy), 1);
    this->scheduleUpdate();
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(GameScene::myTouchBegin, this);
    listener->onTouchMoved = CC_CALLBACK_2(GameScene::myTouchMove, this);
    listener->onTouchEnded = CC_CALLBACK_2(GameScene::myTouchEnd, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
    
    auto physicslistener = EventListenerPhysicsContact::create();
    physicslistener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(physicslistener, this);
    return true;
}

void GameScene::update(float delay){
    //Game Over
    if(_myplane->isDead() && !gameover){
        gameover = true;
        this->unschedule(schedule_selector(GameScene::createBullets));
        this->unschedule(schedule_selector(GameScene::createEnemy));
        this->unscheduleUpdate();
        _restart->setVisible(true);
        _exit->setVisible(true);
    }
}

void GameScene::createBullets(float delay){
    if(planeBulletsPool.size()<=data.min) {
        Bullet* bullet = Bullet::create();
        bullet->initData(_myplane);
        planeBulletsPool.pushBack(bullet);
        this->addChild(bullet);
    } else {
        Bullet* mbullet = NULL;
        for (Bullet* bullet : planeBulletsPool) {
            if(!bullet->isUsed()){
                mbullet = bullet;
                mbullet->initData(_myplane);
                break;
            }
        }
        if (mbullet==NULL) {
            mbullet = Bullet::create();
            mbullet->initData(_myplane);
            planeBulletsPool.pushBack(mbullet);
            this->addChild(mbullet);
        }
    }
}

void GameScene::createEnemy(float delay){
    EnemyType type = small;
    if(enemyPool.size()<=enemypoolnum.min) {
        Enemy* enemy = Enemy::create();
        enemy->initData(type);
        enemyPool.pushBack(enemy);
        this->addChild(enemy);
    } else {
        Enemy* mEnemy = NULL;
        for (Enemy* enemy : enemyPool) {
            if(!enemy->isUsed()){
                mEnemy = enemy;
                mEnemy->initData(type);
                break;
            }
        }
        if (mEnemy==NULL) {
            mEnemy = Enemy::create();
            mEnemy->initData(type);
            enemyPool.pushBack(mEnemy);
            this->addChild(mEnemy);
        }
    }
}

bool GameScene::onContactBegin(const PhysicsContact &contact){
    if ((contact.getShapeA()->getBody()->getCategoryBitmask() & PlaneMask) == PlaneMask
        &&
        (contact.getShapeB()->getBody()->getCategoryBitmask() & EnemyMask) == EnemyMask) {
        CCLOG("pengz");
        auto plane = (MyPlane*)contact.getShapeA()->getBody()->getNode();
        plane->die();
    }
    else if ((contact.getShapeB()->getBody()->getCategoryBitmask() & PlaneMask) == PlaneMask
        &&
        (contact.getShapeA()->getBody()->getCategoryBitmask() & EnemyMask) == EnemyMask) {
        CCLOG("pengz");
        auto plane = (MyPlane*)contact.getShapeB()->getBody()->getNode();
        plane->die();
    }
    
    if ((contact.getShapeA()->getBody()->getCategoryBitmask() & BulletMask) == BulletMask
        &&
        (contact.getShapeB()->getBody()->getCategoryBitmask() & EnemyMask) == EnemyMask) {
        auto bullet = (Bullet*)contact.getShapeA()->getBody()->getNode();
        bullet->die();
        auto enemy = (Enemy*)contact.getShapeB()->getBody()->getNode();
        if(enemy->isAttack()){
            score+=100;
            _score->setString("SCORE:"+Value(score).asString());
        }
    }
    else if ((contact.getShapeB()->getBody()->getCategoryBitmask() & BulletMask) == BulletMask
        &&
        (contact.getShapeA()->getBody()->getCategoryBitmask() & EnemyMask) == EnemyMask) {
        auto bullet = (Bullet*)contact.getShapeB()->getBody()->getNode();
        bullet->die();
        auto enemy = (Enemy*)contact.getShapeA()->getBody()->getNode();
        if(enemy->isAttack()){
            score+=100;
            _score->setString("SCORE:"+Value(score).asString());
        }
    }
    
    return true;
}

bool GameScene::myTouchBegin(Touch *touch, Event *event){
    CCLOG("true");
    if (gameover && _restart->getBoundingBox().containsPoint(Pos)) {
        SceneManager::getInstance()->changeScene(SceneManager::GameStartScene);
    }
    else if(gameover && _exit->getBoundingBox().containsPoint(Pos)){
        Director::getInstance()->end();
        
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        exit(0);
#endif
    }
    return true;
}

void GameScene::myTouchMove(cocos2d::Touch *touch, cocos2d::Event *event){
}

void GameScene::myTouchEnd(cocos2d::Touch *touch, cocos2d::Event *event){
}