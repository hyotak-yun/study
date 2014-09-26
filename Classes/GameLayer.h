//
//  GameLayer.h
//  testgame
//
//  Created by devtak on 2014. 9. 26..
//
//

#pragma once

#include <cocos2d.h>


class GameLayer : public cocos2d::Layer
{
public:
	GameLayer();
	virtual ~GameLayer();
	
	CREATE_FUNC(GameLayer);
	
	
protected:
	virtual bool init();
	
};

