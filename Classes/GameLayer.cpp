//
//  GameLayer.cpp
//  testgame
//
//  Created by devtak on 2014. 9. 26..
//
//

#include "GameLayer.h"
#include "BackgroundLayer.h"
#include "PlayerSprite.h"


using namespace cocos2d;


GameLayer::GameLayer()
{
    _playerSprite = nullptr;
	
}


GameLayer::~GameLayer()
{
    _playerSprite = nullptr;
}


bool GameLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	const Size visibleSize = Director::getInstance()->getVisibleSize();
	const Point origin = Director::getInstance()->getVisibleOrigin();
    
    _playerSprite = PlayerSprite::create();
    addChild(_playerSprite);
    _playerSprite->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
	
	auto groundBody = PhysicsBody::create();
	groundBody->addShape(PhysicsShapeBox::create(Size(visibleSize.width, 30)));
	groundBody->setDynamic(false);
	groundBody->setLinearDamping(0.0f);
	
	auto groundNode = Node::create();
	groundNode->setPhysicsBody(groundBody);
	groundNode->setPosition(visibleSize.width / 2, 0);
	
	addChild(groundNode);
	
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameLayer::onContactBegin, this);
	getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);
	
	
	_selSchedule = schedule_selector(GameLayer::onUpdate);
	schedule(_selSchedule);
	
	return true;
}

void GameLayer::onHudEventTouch()
{
	
}

bool GameLayer::onContactBegin(PhysicsContact& contact)
{
	return true;
}

void GameLayer::onUpdate(float delta)
{
	
}


