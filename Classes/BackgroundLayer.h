//
//  BackgroundLayer.h
//  testgame
//
//  Created by devtak on 2014. 9. 26..
//
//

#pragma once


#include <cocos2d.h>


class BackgroundLayer : public cocos2d::Layer
{
public:
	BackgroundLayer();
	virtual ~BackgroundLayer();
	
	
	CREATE_FUNC(BackgroundLayer);
	
protected:
	virtual bool init();
	
};