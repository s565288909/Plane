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

//音乐文件名的宏
#define Music_Boom "explosion.mp3"

//获取单例的宏
#define TCache Director::getInstance()->getTextureCache()
#define SFCache SpriteFrameCache::getInstance()
#define AniCache AnimationCache::getInstance()

#define Audio CocosDenshion::SimpleAudioEngine::getInstance()

#endif /* GlobalDefine_hpp */
