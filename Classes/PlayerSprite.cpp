//
//  PlayerSprite.cpp
//  testgame
//
//  Created by devtak on 2014. 9. 26..
//
//


#include "PlayerSprite.h"
#include "BulletSprite.h"


using namespace cocos2d;


const int PlayerSprite::TAG = 1000;


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
    
    if(!Sprite::initWithFile("player.png"))
    {
        return false;
    }
	
	setTag(TAG);
	
/*
    PhysicsBody* physicsBody = PhysicsBody::create();
    physicsBody->addShape(PhysicsShapeCircle::create(15));
    physicsBody->setDynamic(true);
    physicsBody->setLinearDamping(0.0f);
    physicsBody->setGravityEnable(true);
    
    setPhysicsBody(physicsBody);
*/
	schedule(schedule_selector(PlayerSprite::onUpdateBullet), 0.1);
	
	return true;
}

void PlayerSprite::onUpdateBullet(float delta)
{
	auto bullet = BulletSprite::create(BulletSprite::BulletType::BulletTypeNormal);
	bullet->setPosition(Point(boundingBox().size.width / 2, boundingBox().size.height));
	addChild(bullet);
	
	Size winSize = Director::getInstance()->getWinSize();
	auto action0 = MoveBy::create(1.0, Point(0,winSize.height));
	auto action = Sequence::create(action0, CallFuncN::create(CC_CALLBACK_1(PlayerSprite::resetBullet, this)), NULL);
	bullet->runAction(action);
	
	bullets.pushBack(bullet);
}

void PlayerSprite::resetBullet(Ref* sender)
{
	auto bullet = reinterpret_cast<BulletSprite*>(sender);
	bullets.eraseObject(bullet);
	cocos2d::Node::removeChild(bullet);
}