#ifndef __ABOUT_SCENE_H__
#define __ABOUT_SCENE_H__

#include "BaseScene.h"

class AboutScene : public BaseScene
{
public:
	static ax::Scene* createScene();
	AboutScene();
	bool init() override;
	CREATE_FUNC(AboutScene);

private:
	void onKeyPressed(ax::EventKeyboard::KeyCode code, ax::Event* event) override;
	void showDebugInfo();
	ax::Label* _content;
	ax::Label* _content2;
};

#endif // __ABOUT_SCENE_H__
