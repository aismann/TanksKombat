#ifndef __SNEAKY_BUTTON_SKINNED_H__
#define __SNEAKY_BUTTON_SKINNED_H__

#include "SneakyButton.h"

class SneakyButtonSkinnedBase : public cocos2d::Layer
{
	AX_SYNTHESIZE_READONLY(cocos2d::Sprite*, defaultSprite, DefaultSprite);
	AX_SYNTHESIZE_READONLY(cocos2d::Sprite*, activatedSprite, ActivatedSprite);
	AX_SYNTHESIZE_READONLY(cocos2d::Sprite*, disabledSprite, DisabledSprite);
	AX_SYNTHESIZE_READONLY(cocos2d::Sprite*, pressSprite, PressSprite);

	AX_SYNTHESIZE_READONLY(SneakyButton*, button, Button); //Not sure about this

	//Public methods
	CREATE_FUNC(SneakyButtonSkinnedBase);
	SneakyButtonSkinnedBase();
	~SneakyButtonSkinnedBase() override;
	bool init() override;
	void watchSelf(float delta);
	void setContentSize(cocos2d::Size s);
	void setDefaultSprite(cocos2d::Sprite* aSprite);
	void setActivatedSprite(cocos2d::Sprite* aSprite);
	void setDisabledSprite(cocos2d::Sprite* aSprite);
	void setPressSprite(cocos2d::Sprite* aSprite);
	void setButton(SneakyButton* aButton);
};

#endif
