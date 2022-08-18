#ifndef __JOYSTICK_SKINNED_H__
#define __JOYSTICK_SKINNED_H__

#include "cocos2d.h"
#include "SneakyJoystick.h"

class SneakyJoystickSkinnedBase : public cocos2d::Layer
{
public:
	AX_SYNTHESIZE_READONLY(cocos2d::Sprite*, backgroundSprite, BackgroundSprite);
	AX_SYNTHESIZE_READONLY(cocos2d::Sprite*, thumbSprite, ThumbSprite);
	AX_SYNTHESIZE_READONLY(SneakyJoystick*, joystick, Joystick);

	CREATE_FUNC(SneakyJoystickSkinnedBase);
	SneakyJoystickSkinnedBase();
	virtual ~SneakyJoystickSkinnedBase();
	bool init() override;
	void updatePositions(float delta);
	void setContentSize(cocos2d::Size s);
	void setBackgroundSprite(cocos2d::Sprite* aSprite);
	void setThumbSprite(cocos2d::Sprite* aSprite);
	void setJoystick(SneakyJoystick* aJoystick);
};
#endif