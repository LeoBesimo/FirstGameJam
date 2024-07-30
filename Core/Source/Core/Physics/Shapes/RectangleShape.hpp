#pragma once

#include "PhysicsBody.hpp"

namespace Core::Physics
{
	class RectangleShape :
		public PhysicsBody
	{
	public:
		RectangleShape();
		RectangleShape(Math::Vector2 position, Math::Vector2 size = Math::Vector2(10,10));
		~RectangleShape();

		void setSize(Math::Vector2 size);

		std::vector<Math::Vector2> getCorners();

		void update(float dt) override;

	private:
		std::vector<Math::Vector2> m_Corners;
		 
		Math::Vector2 m_Size;

		void calculateCorners();
	};
}