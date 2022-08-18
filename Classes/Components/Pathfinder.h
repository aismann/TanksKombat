#ifndef  _PATHFINDER_H_
#define  _PATHFINDER_H_

#include "Engine.h"

class ShortestPathStep : public ax::Ref
{
public:
	ShortestPathStep();
	~ShortestPathStep() override;

	static ShortestPathStep* createWithPosition(const Pos2& pos);
	void initWithPosition(const Pos2& pos);

	int getFScore() const;
	bool isEqual(const ShortestPathStep* other) const;
	std::string getDescription() const;

	AX_SYNTHESIZE(Pos2, _position, Position);
	AX_SYNTHESIZE(int, _gScore, GScore);
	AX_SYNTHESIZE(int, _hScore, HScore);
	AX_SYNTHESIZE(ShortestPathStep*, _parent, Parent);
};

class Pathfinder : public ax::Component
{
public:
	const static std::string COMPONENT_NAME;

	CREATE_FUNC(Pathfinder);

	bool isPathExist(const Pos2& from, const Pos2& to, bool getUpClose = false);
	const ax::Vector<ShortestPathStep*>& getShortestPath(const Pos2& from, const Pos2& to, bool getUpClose = false);
private:
	ax::Vector<ShortestPathStep*> _spOpenSteps;
	ax::Vector<ShortestPathStep*> _spClosedSteps;
	ax::Vector<ShortestPathStep*> _moveTowardPath;

	Pathfinder();
	~Pathfinder() override;

	void insertInOpenSteps(ShortestPathStep* step);
	static int computeHScoreFromCoordToCoord(const Pos2& from, const Pos2& to);
	static int costToMoveFromStepToAdjacentStep(const ShortestPathStep* fromStep, const ShortestPathStep* toStep);
	static ssize_t getStepIndex(const ax::Vector<ShortestPathStep*>& steps, const ShortestPathStep* step);

	ShortestPathStep* constructPath(const Pos2& from, const Pos2& to, bool getUpClose = false);
};


#endif // _PATHFINDER_H_