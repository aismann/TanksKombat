#ifndef __SNEAKY_BUTTON_H__
#define __SNEAKY_BUTTON_H__

#include "cocos2d.h"

class SneakyButton : public ax::Node
{
protected:
	ax::Point center;
	float radiusSq;

	ax::Rect bounds;

	AX_SYNTHESIZE(bool, status, Status);
	AX_SYNTHESIZE_READONLY(bool, active, IsActive);
	AX_SYNTHESIZE_READONLY(bool, value, Value);
	AX_SYNTHESIZE(bool, isHoldable, IsHoldable);
	AX_SYNTHESIZE(bool, isToggleable, IsToggleable);
	AX_SYNTHESIZE(float, rateLimit, RateLimit);

	AX_SYNTHESIZE_READONLY(float, radius, Radius);

	virtual void onEnterTransitionDidFinish() override;
	virtual void onExit() override;
	void initWithRect(const ax::Rect& rect);
	void limiter(float delta);
	void setRadius(float r);
	virtual bool onTouchBegan(ax::Touch *touch, ax::Event *event);
	virtual void onTouchMoved(ax::Touch *touch, ax::Event *event);
	virtual void onTouchEnded(ax::Touch *touch, ax::Event *event);
	virtual void onTouchCancelled(ax::Touch *touch, ax::Event *event);

	ax::EventListenerTouchOneByOne * _eventListenerTouch;
};

#endif