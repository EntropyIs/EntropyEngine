#pragma once
#include "Entropy/Tools/API.h"

namespace Entropy
{
	namespace Graphics
	{
		class ENTROPY_API Renderer
		{
		public:
			Renderer() {};
			virtual ~Renderer() {};

			virtual void OnUpdate() = 0;
			virtual void OnRender() = 0;
		};
	}
}