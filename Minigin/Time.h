#pragma once
#include "Singleton.h"

namespace gentgine
{
	class Time final : public Singleton<Time>
	{
	public:
		float GetDeltaTime() const { return m_DeltaTime; }
		float GetFixedTimeStep() const { return m_FixedTimeStep; }

	private:
		friend class Singleton<Time>;
		friend class Minigin;
		Time() = default;


		void SetDeltaTime(float deltaTime) { m_DeltaTime = deltaTime; }

		float m_DeltaTime = 0.f;
		float m_FixedTimeStep = 0.02f;
	};

}

