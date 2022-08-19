#ifndef _SIMPLEMENUITEM_H_
#define _SIMPLEMENUITEM_H_

#include "axys.h"

class SimpleMenuItem : public ax::MenuItemAtlasFont
{
public:
	static SimpleMenuItem* create();
	static SimpleMenuItem* create(const ax::ccMenuCallback& callback);
	static SimpleMenuItem* create(const std::string& value, const std::string& charMapFile, int itemWidth, int itemHeight, char startCharMap);
	static SimpleMenuItem* create(const std::string& value, const std::string& charMapFile, int itemWidth, int itemHeight, char startCharMap, const ax::ccMenuCallback& menuItemActivate);

	void activate() override;

	void setValues(const std::vector<std::string>& values);
	const std::vector<std::string>& getValues() const
	{
		return _values;
	}

	const std::string& getCurrentValue() const;

	void setCurrentValue(const std::string& value);

	int getCurrentValueIndex() const
	{
		return _currentValue;
	}
	void setCurrentValueIndex(int index);

	void setValueChangedCallback(const ax::ccMenuCallback& onValueChanged)
	{
		_onValueChanged = onValueChanged;
	}

	void setActivateCallback(const ax::ccMenuCallback& menuItemActivate)
	{
		setCallback(menuItemActivate);
	}

	bool selectNextValue();
	bool selectPrevValue();

	bool isCurrent() const { return _isCurrent; }
	void setCurrent(bool current);
protected:
	virtual void onValueChanged(bool playSound = true);
private:
	int _currentValue;
	bool _isCurrent;
	std::string _originalString;
	std::vector<std::string> _values;
	ax::ccMenuCallback _onValueChanged;

	void updateLabel();
};


#endif // _SIMPLEMENUITEM_H_
