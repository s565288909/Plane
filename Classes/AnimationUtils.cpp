//
//  AnimationUtils.cpp
//  XiaoMing
//
//  Created by 史潇 on 15/12/7.
//
//

#include "AnimationUtils.hpp"

USING_NS_CC;

Animation* AnimationUtils::createAniWithPlist(const char* name, const char* file,float delay, unsigned int iLoops)
{
    auto frameCache = SpriteFrameCache::getInstance();
    frameCache->addSpriteFramesWithFile(StringUtils::format("%s%s.list",file,name), StringUtils::format("%s%s.png",file,name));
    SpriteFrame* spriteFrame = NULL;
    Vector<SpriteFrame*> array;
    int index = 1;
    while (true) {
        spriteFrame = frameCache->getSpriteFrameByName(StringUtils::format("%s_%d",name,index++));
        if (spriteFrame == NULL) {
            break;
        }
        array.pushBack(spriteFrame);
    }
    
    auto animation = Animation::create();
    animation->createWithSpriteFrames(array);
    animation->setDelayPerUnit(delay);
    animation->setLoops(iLoops);
    animation->setRestoreOriginalFrame(true);
    return animation;
}

Animation* AnimationUtils::createAniWithPlist(const char *name, float delay, unsigned int iLoops)
{
    SpriteFrame* spriteFrame = NULL;
    SpriteFrameCache* frameCache = SpriteFrameCache::getInstance();
    Vector<SpriteFrame*> array;
    int index = 1;
    while (true) {
        spriteFrame = frameCache->getSpriteFrameByName(StringUtils::format("%s_%d.png",name,index++));
        if (spriteFrame == NULL) {
            break;
        }
        array.pushBack(spriteFrame);
    }
    
    Animation* animation = Animation::createWithSpriteFrames(array);
    animation->setDelayPerUnit(delay);
    animation->setLoops(iLoops);
    animation->setRestoreOriginalFrame(true);
    //加入缓存
    auto cache = AnimationCache::getInstance();
    cache->addAnimation(animation, name);
    return animation;
}