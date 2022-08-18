#ifndef __SNEAKY_BUTTON_H__
#define __SNEAKY_BUTTON_H__

#include "cocos2d.h"

class SneakyButton : public cocos2d::Node
{
protected:
	cocos2d::Point center;
	float radiusSq;

	cocos2d::Rect bounds;

	AX_SYNTHESIZE(bool, status, Status);
	AX_SYNTHESIZE_READONLY(bool, active, IsActive);
	AX_SYNTHESIZE_READONLY(bool, value, Value);
	AX_SYNTHESIZE(bool, isHoldable, IsHoldable);
	AX_SYNTHESIZE(bool, isToggleable, IsToggleable);
	AX_SYNTHESIZE(float, rateLimit, RateLimit);

	AX_SYNTHESIZE_READONLY(float, radius, Radius);

	virtual void onEnterTransitionDidFinish() override;
	virtual void onExit() override;
	void initWithRect(const cocos2d::Rect& rect);
	void limiter(float delta);
	void setRadius(float r);
	virtual bool onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchMoved(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchEnded(cocos2d::Touch *touch, cocos2d::Event *event);
	virtual void onTouchCancelled(cocos2d::Touch *touch, cocos2d::Event *event);

	cocos2d::EventListenerTouchOneByOne * _eventListenerTouch;
};

#endif