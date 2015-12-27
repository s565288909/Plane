//
//  AnimationUtils.hpp
//  XiaoMing
//
//  Created by 史潇 on 15/12/7.
//
//

#ifndef AnimationUtils_hpp
#define AnimationUtils_hpp

#include <cocos2d.h>

class AnimationUtils
{
public:
    static cocos2d::Animation* createAniWithPlist(const char* name,const char* file,float delay,unsigned int iLoops);
    static cocos2d::Animation* createAniWithPlist(const char* name,float delay,unsigned int iLoops);
};

#endif /* AnimationUtils_hpp */
