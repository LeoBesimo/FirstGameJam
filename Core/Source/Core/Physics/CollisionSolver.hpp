#pragma once

#include "Shapes/Shapes.hpp"

namespace Core::Physics
{
	class CollisionSolver
	{
	public:
		void resolveStatic(Manifold m);
	};
}