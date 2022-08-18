#ifndef __GAMESETTINGSSCENE_H__
#define __GAMESETTINGSSCENE_H__

#include "BaseScene.h"


class GameSettingsScene : public BaseScene
{
public:
	static ax::Scene* createScene();
	bool init() override;
	CREATE_FUNC(GameSettingsScene);

private:
	void onKeyEvent(ax::EventKeyboard::KeyCode keyCode, ax::Event* event) override;
	void menuItemActivated(ax::Ref* pSender);
	void menuItemValueChanged(ax::Ref* pSender);
	void onMenuItemActivated(int menuItem);
};

#endif // __GAMESETTINGSSCENE_H__
