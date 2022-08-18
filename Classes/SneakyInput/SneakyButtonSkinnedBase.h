#ifndef __SNEAKY_BUTTON_SKINNED_H__
#define __SNEAKY_BUTTON_SKINNED_H__

#include "SneakyButton.h"

class SneakyButtonSkinnedBase : public ax::Layer
{
	AX_SYNTHESIZE_READONLY(ax::Sprite*, defaultSprite, DefaultSprite);
	AX_SYNTHESIZE_READONLY(ax::Sprite*, activatedSprite, ActivatedSprite);
	AX_SYNTHESIZE_READONLY(ax::Sprite*, disabledSprite, DisabledSprite);
	AX_SYNTHESIZE_READONLY(ax::Sprite*, pressSprite, PressSprite);

	AX_SYNTHESIZE_READONLY(SneakyButton*, button, Button); //Not sure about this

	//Public methods
	CREATE_FUNC(SneakyButtonSkinnedBase);
	SneakyButtonSkinnedBase();
	~SneakyButtonSkinnedBase() override;
	bool init() override;
	void watchSelf(float delta);
	void setContentSize(ax::Size s);
	void setDefaultSprite(ax::Sprite* aSprite);
	void setActivatedSprite(ax::Sprite* aSprite);
	void setDisabledSprite(ax::Sprite* aSprite);
	void setPressSprite(ax::Sprite* aSprite);
	void setButton(SneakyButton* aButton);
};

#endif
