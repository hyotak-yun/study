//
//  BackgroundLayer.cpp
//  testgame
//
//  Created by devtak on 2014. 9. 26..
//
//

#include "BackgroundLayer.h"

using namespace cocos2d;


BackgroundLayer::BackgroundLayer()
{
	
}

BackgroundLayer::~BackgroundLayer()
{
	
}

bool BackgroundLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

//	Size visibleSize = Director::getInstance()->getVisibleSize();
//	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			auto sprite = Sprite::create("tile.png");
			
			sprite->setAnchorPoint(Point::ZERO);
			sprite->setPosition(Point(i * sprite->boundingBox().size.width
									  , j * sprite->boundingBox().size.height));
			addChild(sprite);
		}
	}
	
	auto action0 = Sequence::create(MoveBy::create(0.5, Point(0, -49)), Place::create(Point::ZERO), NULL);
	auto action1 = RepeatForever::create(action0);
	runAction(action1);

	return true;
}
