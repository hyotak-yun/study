//
//  EnemySprite.h
//  testgame
//
//  Created by devtak on 2014. 10. 8..
//
//
#pragma once

#include <cocos2d.h>


class EnemySprite : public cocos2d::Sprite
{
public:
	enum EnemyType
	{
		EnemyTypeNormal,
		EnemyTypeBoss,
	};
	
	enum EnemyStatus
	{
		EnemyAlive,
		EnemyDestroyed,
	};
	
	EnemySprite(EnemyType type = EnemyTypeNormal);
	virtual ~EnemySprite();
	
	static EnemySprite* create(EnemyType type);
	static const int TAG;
	CC_SYNTHESIZE(EnemyType, _enemyType, EnemyType)
	CC_SYNTHESIZE(EnemyStatus, _enemyStatus, EnemyStatus)
	
	float getHealthPoint();
	void setDamage(float power);
	
private:
	bool init() override;
	void update(float delta) override;
	void resetExplosion(cocos2d::Ref* sender);
	
	float _healthPoint;
};