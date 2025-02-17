#ifndef _SIMPLEMENU_H_
#define _SIMPLEMENU_H_

#include "axys.h"
#include "SimpleMenuItem.h"

class SimpleMenu : public ax::Menu
{
public:
	friend SimpleMenuItem;

	enum class Type
	{
		HORIZONTAL, VERTICAL
	};

	static SimpleMenu* create(Type type);

#if (AX_TARGET_PLATFORM == AX_PLATFORM_WINRT)
	// VS2013 does not support nullptr in variable args lists and variadic templates are also not supported.
	typedef ax::MenuItem* M;
	static SimpleMenu* create(Type type, M m1, std::nullptr_t listEnd) { return variadicCreate(type, m1, NULL); }
	static SimpleMenu* create(Type type, M m1, M m2, std::nullptr_t listEnd) { return variadicCreate(type, m1, m2, NULL); }
	static SimpleMenu* create(Type type, M m1, M m2, M m3, std::nullptr_t listEnd) { return variadicCreate(type, m1, m2, m3, NULL); }
	static SimpleMenu* create(Type type, M m1, M m2, M m3, M m4, std::nullptr_t listEnd) { return variadicCreate(type, m1, m2, m3, m4, NULL); }
	static SimpleMenu* create(Type type, M m1, M m2, M m3, M m4, M m5, std::nullptr_t listEnd) { return variadicCreate(type, m1, m2, m3, m4, m5, NULL); }
	static SimpleMenu* create(Type type, M m1, M m2, M m3, M m4, M m5, M m6, std::nullptr_t listEnd) { return variadicCreate(type, m1, m2, m3, m4, m5, m6, NULL); }
	static SimpleMenu* create(Type type, M m1, M m2, M m3, M m4, M m5, M m6, M m7, std::nullptr_t listEnd) { return variadicCreate(type, m1, m2, m3, m4, m5, m6, m7, NULL); }
	static SimpleMenu* create(Type type, M m1, M m2, M m3, M m4, M m5, M m6, M m7, M m8, std::nullptr_t listEnd) { return variadicCreate(type, m1, m2, m3, m4, m5, m6, m7, m8, NULL); }
	static SimpleMenu* create(Type type, M m1, M m2, M m3, M m4, M m5, M m6, M m7, M m8, M m9, std::nullptr_t listEnd) { return variadicCreate(type, m1, m2, m3, m4, m5, m6, m7, m8, m9, NULL); }
	static SimpleMenu* create(Type type, M m1, M m2, M m3, M m4, M m5, M m6, M m7, M m8, M m9, M m10, std::nullptr_t listEnd) { return variadicCreate(type, m1, m2, m3, m4, m5, m6, m7, m8, m9, m10, NULL); }

	// On WP8 for lists longer than 10 items, use createWithArray or variadicCreate with NULL as the last argument.
	static SimpleMenu* variadicCreate(Type type, ax::MenuItem* item, ...);
#else
	static SimpleMenu* create(Type type, ax::MenuItem* item, ...) AX_REQUIRES_NULL_TERMINATION;
#endif

	static SimpleMenu* createWithArray(Type type, const ax::Vector<ax::MenuItem*>& arrayOfItems);
	static SimpleMenu* createWithItems(Type type, ax::MenuItem* firstItem, va_list args);

	SimpleMenu();
	~SimpleMenu() override;

	void setCurrentMenuItemTag(int currentMenuItem);

	SimpleMenuItem* getCurrentMenuItem() const
	{
		return _currentMenuItem;
	}

protected:
	virtual void onCurrentItemChanged(SimpleMenuItem* menuItem, bool playSound = true);
	virtual void onItemActivated(SimpleMenuItem* menuItem, bool playSound = true);
private:
	int _listenerId;
	SimpleMenuItem* _currentMenuItem;
	Type _type;

	std::function<void(ax::Ref*)> _onItemChanged;

	bool onKeyPressed2(ax::EventKeyboard::KeyCode keyCode, ax::Event* event);
	void initOpt(Type type);

	void updateMenuItems(SimpleMenuItem* menuItem);
};


#endif // _SIMPLEMENU_H_
