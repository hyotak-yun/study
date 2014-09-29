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
	virtual void onHudEventTouch() = 0;
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
	void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event* event);
	
};
