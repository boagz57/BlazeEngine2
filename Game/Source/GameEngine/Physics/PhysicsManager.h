#pragma once
#include "../../Universal/SmallVector.h"
#include "../Scene.h"

namespace Blz
{
	namespace Physics
	{
		class PhysicsManager
		{
		public:
			PhysicsManager();
			~PhysicsManager();

			void Init();
			void Shutdown();
			Scene Update(Scene scene);

		private:
			Blz::SmallVector<Fighter> fighters;
		};
	}
}