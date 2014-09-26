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
	
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite* backgroundSprite = Sprite::create("background_1.png");
	backgroundSprite->setPosition(Vec2(visibleSize.width / 2 + origin.x
									   , visibleSize.height / 2 + origin.y));
	
	addChild(backgroundSprite, 0);

	return true;
}
