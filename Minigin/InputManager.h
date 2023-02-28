#pragma once
#include "Singleton.h"

namespace gentgine
{
	class InputManager final : public Singleton<InputManager>
	{
	public:
		bool ProcessInput();
	};

}
