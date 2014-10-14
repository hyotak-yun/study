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
#include "EnemySprite.h"


using namespace cocos2d;


const int PADDING_SCREEN	(10);
static GameLayer* g_currentGameLayer = nullptr;


GameLayer::GameLayer()
{
	_posStartTouch = Point::ZERO;
	_posStartPlayer = Point::ZERO;
	_player = nullptr;
}


GameLayer::~GameLayer()
{
	g_currentGameLayer = nullptr;
}

GameLayer* GameLayer::getCurrentInstance()
{
	return g_currentGameLayer;
}

const Vector<Sprite*>& GameLayer::getEnemys()
{
	return _enemys;
}

const PlayerSprite* GameLayer::getPlayer()
{
	return _player;
}


bool GameLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}
	
	g_currentGameLayer = this;

	_winSize = Director::getInstance()->getWinSize();
	
	initPlayer();

	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(GameLayer::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(GameLayer::onTouchMoved, this);
	
	getEventDispatcher()->addEventListenerWithFixedPriority(touchListener, 1);
	
	scheduleUpdate();
	schedule(schedule_selector(GameLayer::onUpdateEnemy), 1.0/* + rand() % 4*/);
	
	return true;
}

void GameLayer::initPlayer()
{
	_player = PlayerSprite::create();
	addChild(_player);
	_player->setPosition(Point(_winSize.width / 2, _winSize.height / 2));
}

void GameLayer::onHudEventActionMoveToRight()
{
}

void GameLayer::onHudEventActionMoveToLeft()
{
}

void GameLayer::onHudEventActionStop()
{
}

bool GameLayer::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event)
{
	_posStartTouch = touch->getLocation();
	auto player = (PlayerSprite*)getChildByTag(PlayerSprite::TAG);
	_posStartPlayer = player->getPosition();
	
	return true;
}

void GameLayer::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* unused_event)
{
	Point location = touch->getLocation();
	Point posChange = location - _posStartTouch;
	
	auto player = (PlayerSprite*)getChildByTag(PlayerSprite::TAG);
	player->setPosition(_posStartPlayer + posChange);
}

void GameLayer::update(float delta)
{
	
}

void GameLayer::onUpdateEnemy(float delta)
{
	int x = PADDING_SCREEN + rand() % (static_cast<int>(_winSize.width) - PADDING_SCREEN * 2);
	
	EnemySprite* enemy = nullptr;
	if (rand() % 100 < 20)
	{
		enemy = EnemySprite::create(EnemySprite::EnemyType::EnemyTypeBoss);
	}
	else
	{
		enemy = EnemySprite::create(EnemySprite::EnemyType::EnemyTypeNormal);
	}
	enemy->setPosition(Point(x, _winSize.height));
	addChild(enemy);
	
	int duration = rand() % 5;
	if (duration == 0)
	{
		duration = 1;
	}
	auto action0 = MoveBy::create(duration, Point(0, -_winSize.height));
	auto action = Sequence::create(action0, CallFuncN::create(CC_CALLBACK_1(GameLayer::resetEnemy, this)), NULL);
	enemy->runAction(action);
	
	_enemys.pushBack(enemy);
}

void GameLayer::resetEnemy(Ref* sender)
{
	auto enemy = reinterpret_cast<Sprite*>(sender);
	_enemys.eraseObject(enemy);
	removeChild(enemy);
}

