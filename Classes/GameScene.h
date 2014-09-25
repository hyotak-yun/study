//
//  GameScene.h
//  testgame
//
//  Created by devtak on 2014. 9. 25..
//
//

#pragma once

#include "cocos2d.h"


class GameScene : public cocos2d::Scene
{
public:
	GameScene();
	virtual ~GameScene();

	CREATE_FUNC(GameScene);
	
protected:
	virtual bool init();
	
};