#ifndef __HIGHSCORES_SCENE_H__
#define __HIGHSCORES_SCENE_H__

#include "BaseScene.h"


class HighScoresScene : public BaseScene
{
public:
	static ax::Scene* createScene();
	bool init() override;
	CREATE_FUNC(HighScoresScene);

private:
	void menuItemActivated(Ref* pSender);
	void onMenuItemActivated(int menuItem);
	void onKeyEvent(ax::EventKeyboard::KeyCode keyCode, ax::Event* event) override;
};

#endif // __HIGHSCORES_SCENE_H__
