#ifndef  _TILEDSPRITE_H_
#define  _TILEDSPRITE_H_

#include "cocos2d.h"

class TiledSprite : public ax::Sprite
{
public:
	static TiledSprite* createWithSprite(ax::Sprite* sourceSprite, int width, int height);
private:
	bool initWithTX(ax::Sprite* sourceSprite, int width, int height);
};

#endif // _TILEDSPRITE_H_