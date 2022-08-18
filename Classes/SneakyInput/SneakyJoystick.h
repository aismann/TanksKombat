#ifndef __SNEAKY_JOYSTICK_H__
#define __SNEAKY_JOYSTICK_H__

#include "cocos2d.h"

class SneakyJoystick : public cocos2d::Node
{
protected:
	float joystickRadiusSq;
	float thumbRadiusSq;
	float deadRadiusSq;

	AX_SYNTHESIZE_READONLY(cocos2d::Point, stickPosition, StickPosition);
	AX_SYNTHESIZE_READONLY(float, degrees, Degrees);
	AX_SYNTHESIZE_READONLY(cocos2d::Point, velocity, Velocity);
	AX_SYNTHESIZE(bool, autoCenter, AutoCenter);
	AX_SYNTHESIZE_READONLY(bool, isDPad, IsDPad);
	AX_SYNTHESIZE(bool, hasDeadzone, HasDeadzone);
	AX_SYNTHESIZE(int, numberOfDirections, NumberOfDirections);
	AX_SYNTHESIZE(bool, innerThumb, InnerThumb);

	AX_SYNTHESIZE_READONLY(float, joystickRadius, JoystickRadius);
	AX_SYNTHESIZE_READONLY(float, thumbRadius, ThumbRadius);
	AX_SYNTHESIZE_READONLY(float, deadRadius, DeadRadius);

	~SneakyJoystick() override;

	void initWithRect(const cocos2d::Rect& rect);
	void onEnterTransitionDidFinish() override;
	void onExit() override;
	void setIsDPad(bool b);
	void setJoystickRadius(float r);
	void setThumbRadius(float r);
	void setDeadRadius(float r);
	virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	virtual void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);

private:
	void updateVelocity(cocos2d::Point point);

	cocos2d::EventListenerTouchOneByOne* _eventListenerTouch;

};
#endif
