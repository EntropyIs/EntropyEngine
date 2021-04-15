#pragma once

#include "Entropy/Tools/API.h"
#include "Entropy/Layers/Layer.h"

#include <vector>

namespace Entropy
{
	class ENTROPY_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin();
		std::vector<Layer*>::iterator end();

	private:
		std::vector<Layer*> _layers;
		std::vector<Layer*>::iterator _layerInsert;
	};
}