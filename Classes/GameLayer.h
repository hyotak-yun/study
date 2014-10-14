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
	
	static GameLayer* getCurrentInstance();
	const cocos2d::Vector<cocos2d::Sprite*>& getEnemys();
	const PlayerSprite* getPlayer();
	
protected:
	
private:
	bool init() override;
	void update(float dt) override;
	
	void initPlayer();
	
	
	void onHudEventActionMoveToRight() override;
	void onHudEventActionMoveToLeft() override;
	void onHudEventActionStop() override;
	
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* unused_event) override;
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* unused_event) override;
	
	void onUpdateEnemy(float delta);
	void resetEnemy(Ref* sender);
	
	cocos2d::Size _winSize;
	cocos2d::Point _posStartTouch;
	cocos2d::Point _posStartPlayer;
	cocos2d::Vector<cocos2d::Sprite*> _enemys;
	PlayerSprite* _player;
	
};

