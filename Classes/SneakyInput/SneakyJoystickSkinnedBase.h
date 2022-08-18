#ifndef __JOYSTICK_SKINNED_H__
#define __JOYSTICK_SKINNED_H__

#include "cocos2d.h"
#include "SneakyJoystick.h"

class SneakyJoystickSkinnedBase : public ax::Layer
{
public:
	AX_SYNTHESIZE_READONLY(ax::Sprite*, backgroundSprite, BackgroundSprite);
	AX_SYNTHESIZE_READONLY(ax::Sprite*, thumbSprite, ThumbSprite);
	AX_SYNTHESIZE_READONLY(SneakyJoystick*, joystick, Joystick);

	CREATE_FUNC(SneakyJoystickSkinnedBase);
	SneakyJoystickSkinnedBase();
	virtual ~SneakyJoystickSkinnedBase();
	bool init() override;
	void updatePositions(float delta);
	void setContentSize(ax::Size s);
	void setBackgroundSprite(ax::Sprite* aSprite);
	void setThumbSprite(ax::Sprite* aSprite);
	void setJoystick(SneakyJoystick* aJoystick);
};
#endif