//
//  Enity.hpp
//  MyPlane
//
//  Created by 史潇 on 15/12/28.
//
//

#ifndef Enity_hpp
#define Enity_hpp

#include <cocos2d.h>
#include "GlobalDefine.hpp"

USING_NS_CC;

class Enity: public Node{
public:
    Enity();
    ~Enity();
    void bindSprite(Sprite* sprite);
protected:
    EnityType enityType;
    Sprite* mSprite;
    bool isBindSprite = false;
};

#endif /* Enity_hpp */
