#ifndef  _GAMEOBJECT_H_
#define  _GAMEOBJECT_H_

#include "Engine.h"

class Engine;

class GameObject : public ax::Node
{
public:
	enum class Type : int
	{
		TANK = 0, BONUS, EXPLOSION, PROJECTILE
	};

	enum class Direction : int
	{
		UP, DOWN, LEFT, RIGHT
	};

	GameObject(Type type);
	~GameObject() override;

	Pos2 getGridPosition() const;
	void setGridPosition(const Pos2& p);
	void setGridPosition(int x, int y);

	static Pos2 getGridPosition(const ax::Node* node);
	static void setGridPosition(ax::Node* node, const Pos2& p);
	static void setGridPosition(ax::Node* node, int x, int y);
	static void setGridDirection(ax::Node* node, Direction direction);
	static Pos2 directionToOffset(Direction direction);
	static Direction offsetToDirection(Pos2 offset);
	static float directionToRotation(Direction direction);

	static void updatePassableLayer(const Pos2& pos, const Pos2& prevPos);
	static void removeFromPassableLayer(const Pos2& pos);

	AX_PROPERTY(Direction, _direction, GridDirection);
	AX_PROPERTY(ax::Sprite*, _sprite, Sprite);
	AX_SYNTHESIZE_READONLY(Type, _type, Type);
	AX_SYNTHESIZE(bool, _isPassable, Passable);

	virtual bool init() override;
protected:
	Engine* _engine;
	Pos2 _position;
};

#endif // _GAMEOBJECT_H_