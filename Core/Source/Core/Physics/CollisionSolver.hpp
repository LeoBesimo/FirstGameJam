#pragma once

#include "Shapes/Shapes.hpp"
#include <math.h>

namespace Core::Physics
{
	class CollisionSolver
	{
	public:
		void resolveStatic(Manifold m);
		void resolveDynamic(Manifold m);
		void resolveDynamicWithFriction(Manifold m);
	};
}