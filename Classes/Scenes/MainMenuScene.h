#ifndef __MAINMENUSCENE_H__
#define __MAINMENUSCENE_H__

#include "axys.h"
#include "BaseScene.h"

class MainMenuScene : public BaseScene
{
public:
	static ax::Scene* createScene();
	bool init() override;

	CREATE_FUNC(MainMenuScene);

private:
	void onKeyEvent(ax::EventKeyboard::KeyCode keyCode, ax::Event* event) override;
	void menuItemActivated(ax::Ref* pSender);
	void onMenuItemActivated(int menuItem);
	void exitGame();
};

#endif // __MAINMENUSCENE_H__
