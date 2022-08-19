#ifndef __SNEAKY_JOYSTICK_H__
#define __SNEAKY_JOYSTICK_H__

#include "axys.h"

class SneakyJoystick : public ax::Node
{
protected:
	float joystickRadiusSq;
	float thumbRadiusSq;
	float deadRadiusSq;

	AX_SYNTHESIZE_READONLY(ax::Point, stickPosition, StickPosition);
	AX_SYNTHESIZE_READONLY(float, degrees, Degrees);
	AX_SYNTHESIZE_READONLY(ax::Point, velocity, Velocity);
	AX_SYNTHESIZE(bool, autoCenter, AutoCenter);
	AX_SYNTHESIZE_READONLY(bool, isDPad, IsDPad);
	AX_SYNTHESIZE(bool, hasDeadzone, HasDeadzone);
	AX_SYNTHESIZE(int, numberOfDirections, NumberOfDirections);
	AX_SYNTHESIZE(bool, innerThumb, InnerThumb);

	AX_SYNTHESIZE_READONLY(float, joystickRadius, JoystickRadius);
	AX_SYNTHESIZE_READONLY(float, thumbRadius, ThumbRadius);
	AX_SYNTHESIZE_READONLY(float, deadRadius, DeadRadius);

	~SneakyJoystick() override;

	void initWithRect(const ax::Rect& rect);
	void onEnterTransitionDidFinish() override;
	void onExit() override;
	void setIsDPad(bool b);
	void setJoystickRadius(float r);
	void setThumbRadius(float r);
	void setDeadRadius(float r);
	virtual bool onTouchBegan(ax::Touch* touch, ax::Event* event);
	virtual void onTouchMoved(ax::Touch* touch, ax::Event* event);
	virtual void onTouchEnded(ax::Touch* touch, ax::Event* event);
	virtual void onTouchCancelled(ax::Touch* touch, ax::Event* event);

private:
	void updateVelocity(ax::Point point);

	ax::EventListenerTouchOneByOne* _eventListenerTouch;

};
#endif
