#pragma once

#include "Manifold.hpp"
#include "Shapes/Shapes.hpp"

namespace Core::Physics
{
	class CollisionSolver
	{
	public:
		void resolveStatic(Manifold m);
	};
}