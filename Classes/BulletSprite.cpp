//
//  BulletSprite.cpp
//  testgame
//
//  Created by devtak on 2014. 10. 8..
//
//

#include "BulletSprite.h"
#include "GameLayer.h"
#include "EnemySprite.h"
#include "PlayerSprite.h"

using namespace cocos2d;


const int BulletSprite::TAG = 1001;


BulletSprite::BulletSprite(BulletType type) : _bulletType(type)
{
	_power = 1.0;
}

BulletSprite::~BulletSprite()
{
	
}

BulletSprite* BulletSprite::create(BulletType type)
{
	BulletSprite* ret = new BulletSprite(type);
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

float BulletSprite::getPower()
{
	return _power;
}

bool BulletSprite::init()
{
	std::string imageName = "";
	if (BulletTypeNormal == _bulletType)
	{
		imageName = "missile.png";
		_power = 1.0;
	}
	else if (BulletTypePower == _bulletType)
	{
		imageName = "missile_pow.png";
		_power = 2.0;
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

void BulletSprite::update(float delta)
{
	const PlayerSprite* player = GameLayer::getCurrentInstance()->getPlayer();
	Point pt = player->convertToWorldSpace(getBoundingBox().origin);
	Rect rectBullet = Rect(pt.x, pt.y, boundingBox().size.width, boundingBox().size.height);
	
	const Vector<Sprite*> enemys = GameLayer::getCurrentInstance()->getEnemys();
	for (Sprite* sprite : enemys)
	{
		EnemySprite* enemy = reinterpret_cast<EnemySprite*>(sprite);
		if (EnemySprite::EnemyDestroyed == enemy->getEnemyStatus())
		{
			continue;
		}
		
		Rect rectEnemy = enemy->getBoundingBox();
		if (rectBullet.intersectsRect(rectEnemy))
		{
			enemy->setDamage(_power);
			_power = 0;
			setVisible(false);
			
			unscheduleUpdate();
		}
	}
}
