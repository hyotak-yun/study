//
//  EnemySprite.cpp
//  testgame
//
//  Created by devtak on 2014. 10. 8..
//
//

#include "EnemySprite.h"
#include "GameLayer.h"


using namespace cocos2d;


const int EnemySprite::TAG = 1002;


EnemySprite::EnemySprite(EnemyType type) : _enemyType(type)
{
	_healthPoint = 0;
	_enemyStatus = EnemyStatus::EnemyAlive;
}

EnemySprite::~EnemySprite()
{
	
}

EnemySprite* EnemySprite::create(EnemyType type)
{
	EnemySprite* ret = new EnemySprite(type);
	if (ret && ret->init())
	{
		ret->autorelease();
		return ret;
	}
	else
	{
		delete ret;
		ret = NULL;
		return NULL;
	}
}

bool EnemySprite::init()
{
	std::string imageName = "";
	if (EnemyTypeNormal == _enemyType)
	{
		imageName = "enemy.png";
		_healthPoint = 6.0;
	}
	else if (EnemyTypeBoss == _enemyType)
	{
		imageName = "boss.png";
		_healthPoint = 15.0;
	}
	else
	{
		return false;
	}
	
	if(!Sprite::initWithFile(imageName))
	{
		return false;
	}
	
	setTag(TAG);
	scheduleUpdate();
	
	return true;
}

void EnemySprite::update(float delta)
{
}

float EnemySprite::getHealthPoint()
{
	return _healthPoint;
}

void EnemySprite::setDamage(float power)
{
	_healthPoint -= power;
	if (_healthPoint <= 0)
	{
		_healthPoint = 0;
		_enemyStatus = EnemyDestroyed;
		
		setOpacity(0);
		unscheduleUpdate();
		
		auto particle = ParticleSystemQuad::create("explosion.plist");
		particle->setPosition(Point(boundingBox().size.width / 2, boundingBox().size.height / 2));
		particle->setScale(0.5);
		
		addChild(particle);
		
		auto action0 = DelayTime::create(1.0);
		auto action = Sequence::create(action0, CallFuncN::create(CC_CALLBACK_1(EnemySprite::resetExplosion, this)), NULL);
		particle->runAction(action);
	}
}

void EnemySprite::resetExplosion(Ref* sender)
{
	auto particle = reinterpret_cast<ParticleSystemQuad*>(sender);
	Node::removeChild(particle);
}


