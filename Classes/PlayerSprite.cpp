//
//  PlayerSprite.cpp
//  testgame
//
//  Created by devtak on 2014. 9. 26..
//
//


#include "PlayerSprite.h"

using namespace cocos2d;


PlayerSprite::PlayerSprite()
{
	
}

PlayerSprite::~PlayerSprite()
{
	
}

bool PlayerSprite::init()
{
//    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    if(!Sprite::initWithFile("bat_1.png"))
    {
        return false;
    }
    
    PhysicsBody* physicsBody = PhysicsBody::create();
    physicsBody->addShape(PhysicsShapeCircle::create(15));
    physicsBody->setDynamic(true);
    physicsBody->setLinearDamping(0.0f);
    physicsBody->setGravityEnable(true);
    
    setPhysicsBody(physicsBody);
	
	return true;
}
