//
//  PlayerSprite.h
//  testgame
//
//  Created by devtak on 2014. 9. 26..
//
//

#pragma once

#include <cocos2d.h>

class PlayerSprite : public cocos2d::Sprite
{
public:
	PlayerSprite();
	virtual ~PlayerSprite();
    
    CREATE_FUNC(PlayerSprite);
	
	static const int TAG;
    
private:
	bool init() override;
	void onUpdateBullet(float delta);
	void resetBullet(Ref* sender);
	
	cocos2d::Vector<Sprite*> bullets;
};