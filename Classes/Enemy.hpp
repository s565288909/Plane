//
//  Enemy.hpp
//  MyPlane
//
//  Created by 史潇 on 16/1/2.
//
//

#ifndef Enemy_hpp
#define Enemy_hpp

#include <cocos2d.h>
#include <Enity.hpp>
#include "GlobalDefine.hpp"

USING_NS_CC;

class Enemy : public Enity{
public:
    Enemy();
    ~Enemy();
    virtual bool init();
    virtual void update(float delta);
    CREATE_FUNC(Enemy);
    void initData(EnemyType type);
    bool isUsed();
    bool isAttack();
    void Die();
    void BoomAndDie();
private:
    EnemyType mType;
    int hp;
    float speed;
    bool used;
};

#endif /* Enemy_hpp */
