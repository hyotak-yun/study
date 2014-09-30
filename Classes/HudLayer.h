//
//  HudLayer.h
//  testgame
//
//  Created by devtak on 2014. 9. 29..
//
//

#pragma once

#include <cocos2d.h>


class HudEventListener
{
public:
	virtual void onHudEventActionMoveToRight() = 0;
	virtual void onHudEventActionMoveToLeft() = 0;
	virtual void onHudEventActionStop() = 0;
};


class HudLayer : public cocos2d::Layer
{
public:
	HudLayer();
	virtual ~HudLayer();
	
	CREATE_FUNC(HudLayer);
	CC_SYNTHESIZE(HudEventListener*, _eventListener, EventListener);
	
protected:
	
private:
	bool init() override;
	void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* unused_event) override;
	void onTouchesMoved(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* unused_event) override;
	void onTouchesEnded(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* unused_event) override;
	
	cocos2d::Sprite* _buttonRight;
	cocos2d::Sprite* _buttonLeft;
};
