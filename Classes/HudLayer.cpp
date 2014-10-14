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
	_buttonRight = nullptr;
	_buttonLeft = nullptr;
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
	

	_buttonRight = Sprite::create("CloseNormal.png");
	_buttonRight->setPosition(Vec2(100, 50));
	addChild(_buttonRight, 0);
	
	_buttonLeft = Sprite::create("CloseNormal.png");
	_buttonLeft->setPosition(Vec2(50, 50));
	addChild(_buttonLeft, 0);
	
	auto listener = EventListenerTouchAllAtOnce::create();
	listener->onTouchesBegan = CC_CALLBACK_2(HudLayer::onTouchesBegan, this);
	listener->onTouchesMoved = CC_CALLBACK_2(HudLayer::onTouchesMoved, this);
	listener->onTouchesEnded = CC_CALLBACK_2(HudLayer::onTouchesEnded, this);
	
	auto dispatcher = Director::getInstance()->getEventDispatcher();
//	dispatcher->addEventListenerWithSceneGraphPriority(listener, this);
	dispatcher->addEventListenerWithFixedPriority(listener, 1);

	return true;
}

void HudLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event* unused_event)
{
	if (_eventListener == nullptr)
	{
		return;
	}
	
	auto touch = *touches.cbegin();
	auto location = touch->getLocation();
	
	if (_buttonRight && _buttonRight->boundingBox().containsPoint(location))
	{
		_eventListener->onHudEventActionMoveToRight();
	}
	else if (_buttonLeft && _buttonLeft->boundingBox().containsPoint(location))
	{
		_eventListener->onHudEventActionMoveToLeft();
	}
}

void HudLayer::onTouchesMoved(const std::vector<Touch*>& touches, Event* unused_event)
{
	if (_eventListener == nullptr)
	{
		return;
	}

	if (_buttonRight && _buttonLeft)
	{
		auto touch = *touches.cbegin();
		auto location = touch->getLocation();

		if (!_buttonRight->boundingBox().containsPoint(location)
			&& !_buttonLeft->boundingBox().containsPoint(location))
		{
			_eventListener->onHudEventActionStop();
		}
	}
}

void HudLayer::onTouchesEnded(const std::vector<Touch*>& touches, Event* unused_event)
{
	if (_eventListener == nullptr)
	{
		return;
	}
	
	_eventListener->onHudEventActionStop();
}

