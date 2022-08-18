#ifndef __BASE_SCENE_H__
#define __BASE_SCENE_H__

#include "Engine.h"

#include "SneakyInput/SneakyButton.h"
#include "SneakyInput/SneakyButtonSkinnedBase.h"
#include "SneakyInput/SneakyJoystick.h"
#include "SneakyInput/SneakyJoystickSkinnedBase.h"

#define CHANGE_SCENE(__TYPE__) \
{ \
if(SCENE_TRANSITION) \
	Director::getInstance()->replaceScene(TransitionTurnOffTiles::create(0.5f, __TYPE__::createScene())); \
else \
	Director::getInstance()->replaceScene(__TYPE__::createScene()); \
} \


class JoystickWithSimulator : public SneakyJoystick
{
	ax::EventKeyboard::KeyCode getKeyCodeFromVelocity() const;
	bool onTouchBegan(ax::Touch* touch, ax::Event* event) override;
	void onTouchEnded(ax::Touch* touch, ax::Event* event) override;
};

//

class ButtonWithSimulator : public SneakyButton
{
	bool onTouchBegan(ax::Touch* touch, ax::Event* event) override;
	void onTouchEnded(ax::Touch* touch, ax::Event* event) override;
};

//

class BaseScene : public ax::LayerColor
{
public:
	BaseScene();
	virtual bool init(const ax::Color4B& backgroundColor);
	virtual bool onTouchBegan(ax::Touch* touch, ax::Event* event);
	virtual void onTouchMoved(ax::Touch* touch, ax::Event* event);
	virtual void onTouchEnded(ax::Touch* touch, ax::Event* event);
	virtual void onTouchCancelled(ax::Touch* touch, ax::Event* event);
	virtual void onKeyPressed(ax::EventKeyboard::KeyCode keyCode, ax::Event* event);
	virtual void onKeyReleased(ax::EventKeyboard::KeyCode keyCode, ax::Event* event);
	virtual void onKeyEvent(ax::EventKeyboard::KeyCode keyCode, ax::Event* event);
	static BaseScene* getCurrentScene();

	int addKeyboardEvents(KeyboardEventsFunc touchEvent);
	bool removeKeyboardEvents(int);
	void addJoystick();
	void onExit() override;
#ifndef NDEBUG //if DEBUG
	static void debugPrint(const std::string& output);
#endif
protected:
	Engine* _engine = Engine::getInstance();
private:
	std::deque<TouchEventsFunc> _touchEvents;
	std::deque<KeyboardEventsFunc> _keyboardEvents;
	ax::EventListenerTouchOneByOne* _eventListenerTouch;

	ax::Layer* _onScreenJoystickLayer;
};

#endif // __BASE_SCENE_H__
