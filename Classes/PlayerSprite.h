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
    
private:
	bool init() override;
};