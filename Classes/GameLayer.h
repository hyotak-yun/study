//
//  GameLayer.h
//  testgame
//
//  Created by devtak on 2014. 9. 26..
//
//

#pragma once

#include <cocos2d.h>
#include "HudLayer.h"


class PlayerSprite;

class GameLayer : public cocos2d::Layer
	, public HudEventListener
{
public:
	GameLayer();
	virtual ~GameLayer();
	
	CREATE_FUNC(GameLayer);
	
	
protected:
	
private:
	bool init() override;
	void update(float dt) override;
	
	
	void onHudEventActionMoveToRight() override;
	void onHudEventActionMoveToLeft() override;
	void onHudEventActionStop() override;
	
	bool onContactBegin(cocos2d::PhysicsContact& contact);
	void onUpdate(float delta);
	
    PlayerSprite* _playerSprite;
	cocos2d::SEL_SCHEDULE _selSchedule;
	
};

