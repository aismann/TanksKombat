#ifndef __SETTINGS_SCENE_H__
#define __SETTINGS_SCENE_H__

#include "BaseScene.h"


class SettingsScene : public BaseScene
{
public:
	static ax::Scene* createScene();
	bool init() override;
	void onExit() override;
	CREATE_FUNC(SettingsScene);

private:
	void onKeyEvent(ax::EventKeyboard::KeyCode keyCode, ax::Event* event) override;
	void menuItemActivated(ax::Ref* pSender);
	void menuItemValueChanged(Ref* pSender);
	void onMenuItemActivated(int menuItem);
};

#endif // __SETTINGS_SCENE_H__
