//
//  GameScene.cpp
//  testgame
//
//  Created by devtak on 2014. 9. 25..
//
//

#include "GameScene.h"
#include "GameLayer.h"
#include "BackgroundLayer.h"
#include "HudLayer.h"


using namespace cocos2d;


GameScene::GameScene()
{
	
}

GameScene::~GameScene()
{
	
}

bool GameScene::init()
{
	if (!Scene::initWithPhysics())
	{
		return false;
	}
	
	getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	getPhysicsWorld()->setGravity(Vec2(0, -900));
	
	BackgroundLayer* backgroundLayer = BackgroundLayer::create();
	if (!backgroundLayer)
	{
		return false;
	}
	addChild(backgroundLayer);
	
	GameLayer* gameLayer = GameLayer::create();
	if (!gameLayer)
	{
		return false;
	}
	addChild(gameLayer);
	
	HudLayer* hudLayer = HudLayer::create();
	if (!hudLayer)
	{
		return false;
	}
	addChild(hudLayer);
	
	hudLayer->setEventListener(gameLayer);
	
	return true;
}
