#include "../Scene.h"
#include "Components/Position.h"
#include "PhysicsEngine.h"

namespace Blz
{
	namespace Physics
	{
		auto Engine::Init() -> void
		{
		}

		auto Engine::Shutdown() -> void
		{

		}

		auto Engine::Update(Scene& scene) -> void
		{
			ec.AddContext("When updating Physics engine");

			for (Fighter& fighter : scene.fighters)
			{
				//Move fighter by current translation
				Comp::Position newFighterPosition = [](Comp::Velocity fighterVelocity, Comp::Position fighterPosition, Comp::Movement fighterMovement) -> Comp::Position
				{
					fighterPosition.Add(fighterVelocity.GetCurrentState().x * engineClock.GetPreviousFrameTime(), fighterVelocity.GetCurrentState().y * engineClock.GetPreviousFrameTime());

					return fighterPosition;
				}(fighter.GetVelocity(), fighter.GetPosition(), fighter.GetMovement());


				//Add Gravity and prevent velocity from continually sliding by zeroing out velocity x
				Comp::Velocity newFighterVel = [](Comp::Velocity fighterVelocity, Comp::Movement fighterMovement) -> Comp::Velocity
				{
					fighterVelocity.Add(0.0f, (fighterMovement.GetGravity() * engineClock.GetPreviousFrameTime()));
					fighterVelocity.ZeroOutX();

					return fighterVelocity;
				}(fighter.GetVelocity(), fighter.GetMovement());


				{//Set window borders
					newFighterPosition.ClampMaxPositionTo(160.0f, 90.0f);
					newFighterPosition.ClampMinPositionTo(0.0f, 5.0f);
				}

				fighter.Insert(newFighterPosition);
				fighter.Insert(newFighterVel);
			}
		}
	}
}