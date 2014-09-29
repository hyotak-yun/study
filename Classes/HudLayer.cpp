//
//  HudLayer.cpp
//  testgame
//
//  Created by devtak on 2014. 9. 29..
//
//

#include "HudLayer.h"


USING_NS_CC;


HudLayer::HudLayer()
{
	_eventListener = nullptr;
}

HudLayer::~HudLayer()
{
	
}

bool HudLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(HudLayer::onTouchesBegan, this);
	
	auto dispatcher = Director::getInstance()->getEventDispatcher();
	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	
	return true;
}

void HudLayer::onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event)
{
	if (_eventListener)
	{
		_eventListener->onHudEventTouch();
	}
}
