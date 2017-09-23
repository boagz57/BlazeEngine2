#pragma once
#include "GameEngine/Input/InputManager.h"
#include "GameEngine/Physics/PhysicsManager.h"
#include "GameEngine/Animation/AnimationManager.h"
#include "Containers/Map.h"
#include "Fighter.h"

enum class AnimationState
{
	WALKINGUP
};

class Game
{
public:
	Game() = default;

	void Init();
	void Update();
	void Shutdown();

	void MoveRight(Fighter* const fighter);
	void MoveLeft(Fighter* const fighter);
	void Jump(Fighter* const fighter);

private:
	Blz::Input::Manager input;
	Blz::Animation::Manager animation;
	Blz::Physics::Manager physics;

	Fighter* p_Player;
	Fighter* p_AI;

	uint16 walkingUp;
	uint16 walkingRight;
	uint16 walkingLeft;
	uint16 walkingDown;

	uint16 AIWalkingRight;
};

