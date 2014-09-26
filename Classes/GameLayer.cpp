//
//  GameLayer.cpp
//  testgame
//
//  Created by devtak on 2014. 9. 26..
//
//

#include "GameLayer.h"
#include "BackgroundLayer.h"


using namespace cocos2d;


GameLayer::GameLayer()
{
	
}


GameLayer::~GameLayer()
{
	
}


bool GameLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	const Size visibleSize = Director::getInstance()->getVisibleSize();
	const Point origin = Director::getInstance()->getVisibleOrigin();
	
	
	return true;
}