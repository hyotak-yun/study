//
//  BulletSprite.h
//  testgame
//
//  Created by devtak on 2014. 10. 8..
//
//

#pragma once

#include <cocos2d.h>


class BulletSprite : public cocos2d::Sprite
{
public:
	enum BulletType
	{
		BulletTypeNormal,
		BulletTypePower,
	};
	
	BulletSprite(BulletType type = BulletTypeNormal);
	virtual ~BulletSprite();
	
	static BulletSprite* create(BulletType type);
	static const int TAG;
	CC_SYNTHESIZE(BulletType, _bulletType, BulletType)
	float getPower();
	
private:
	bool init() override;
	void update(float delta) override;
	
	float _power;
};