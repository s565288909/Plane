//
//  GlobalDefine.hpp
//  MyPlane
//
//  Created by 史潇 on 15/12/26.
//
//

#ifndef GlobalDefine_hpp
#define GlobalDefine_hpp

#include <cocos2d.h>
#include "SimpleAudioEngine.h"

USING_NS_CC;

#define WINSIZE Director::getInstance()->getWinSize()

//图片文件名的宏
#define Image_Bg_1 "bg_01.jpg"
#define Image_Bg_2 "bg_02.jpg"
#define Image_Plane_1 "myplane_1.png"
#define Image_Plane_2 "myplane_2.png"
#define Image_EnemyPlane "enemyplane.png"
#define Image_Bullet "bullet.png"

#define Ani_Plane "myplane"
#define Ani_Boom "boom"

#define Image_Main "main.png"
#define Plist_Main "main.plist"

//音乐文件名的宏
#define Audio_Effect_boom "explosion.mp3"
#define Audio_Effect_shoot "shoot.mp3"

//获取单例的宏
#define TCache Director::getInstance()->getTextureCache()
#define SFCache SpriteFrameCache::getInstance()
#define AniCache AnimationCache::getInstance()

#define Pos Director::getInstance()->convertToGL(touch->getLocationInView())

#define Audio CocosDenshion::SimpleAudioEngine::getInstance()

//枚举
enum EnityType{
    PLANE,
    BULLET,
    ENEMY
};

enum EnemyType{
    small,
    medium,
    max
};

//物理掩码
const int PlaneMask = 1 << 1;
const int BulletMask = 1 << 2;
const int EnemyMask = 1 << 3;
const int NullMask = 1 << 0;

#endif /* GlobalDefine_hpp */
