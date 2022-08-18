#ifndef  _EXPLOSION_H_
#define  _EXPLOSION_H_

#include "GameObject.h"


class Explosion : public GameObject
{
public:
	CREATE_FUNC(Explosion);

	static Explosion* createFromPool(const Pos2& pos);
	static void clearPool();

	bool init() override;
	bool inUse() const;

private:
	static ax::Vector<Explosion*> _explosionPool;

	ax::Animation* _animation;

	Explosion();
	~Explosion() override;
	void activate(Pos2 pos);
};

#endif // _EXPLOSION_H_