#ifndef  _TANK_H_
#define  _TANK_H_

#include "GameObject.h"
#include "Objects\LevelGrid.h"
#include <array>

class ShortestPathStep;

class Tank : public GameObject
{
public:
	CREATE_FUNC(Tank);

	Team getTeam() const;
	void setTeam(Team team);

	int getAmmo() const;
	void setAmmo(int ammo);

	int getLives() const;
	void setLives(int lives);

	bool init() override;

	bool tryMove(Direction direction);
	bool moveToward(const Pos2& target, bool getUpClose = false);
	void stopMoveToward();
	void move(Direction direction);
	bool tryShoot();
	void doAction(TankAction action);
	bool isShooting() const;
	bool isGhostState() const;
	bool isFallIntoHoleState() const;
	bool isMoveTowardState();
	Pos2 getMoveTowardTarget() const;
	const ax::Vector<ShortestPathStep*>& getMoveTowardPath() const { return _moveTowardPath; }
	bool isAIEnabled();
	void setAIEnabled(bool enabled);

	void damage(bool ghostState = true);
	void kill();

	void setGridDirection(Direction direction) override;
private:
	int _lives;
	int _ammo;
	Team _team;
	std::map<Direction, ax::Action*> _idleStates;
	ax::Action* _shotState;
	ax::Action* _moveTowardState;
	ax::Sprite* _shot;
	Pos2 _prevPosition;

	ax::Vector<ShortestPathStep*> _moveTowardPath;
	ax::DrawNode* _debugPathLine;

	const float _moveTowardStepDelay = 0.2f;

	Tank();
	Tank(Team team, int lives, int ammo);
	~Tank() override;

	void startIdleState();
	void stopIdleState();
	void startShotState();
	void stopShotState();
	void startGhostState();
	void stopGhostState();
	void startFallIntoHoleState();
	bool startMoveTowardState(const Pos2& target, bool getUpClose = false);
	void addMoveTowardDebugPath();
	void stopMoveTowardState();
	void updateMoveTowardState();

	void respawnIntoPosition(Pos2 position);

	static ax::Action* createIdleAction(Direction direction, const std::string& frame);

	void shotAnimationStarted();
	void shotAnimationFinished();

	bool onCollidedWithBlock(Direction direction, const TileValue& value);
	bool onCollidedWithGameObject(Direction direction, GameObject* obj);
	void onPostCollidedWithGameObject(GameObject* obj);
};

#endif // _TANK_H_