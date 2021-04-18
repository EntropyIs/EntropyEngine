#include "EPCH.h"
#include "LayerStack.h"

Entropy::LayerStack::LayerStack()
{
	_layerInsert = _layers.begin();
}

Entropy::LayerStack::~LayerStack()
{
	for (Entropy::Layer* layer : _layers)
		delete layer;
}

void Entropy::LayerStack::PushLayer(Layer* layer)
{
	_layerInsert = _layers.emplace(_layerInsert, layer);
}

void Entropy::LayerStack::PushOverlay(Layer* overlay)
{
	_layers.emplace_back(overlay);
}

void Entropy::LayerStack::PopLayer(Layer* layer)
{
	auto it = std::find(_layers.begin(), _layers.end(), layer);
	if (it != _layers.end())
	{
		_layers.erase(it);
		_layerInsert--;
	}
}

void Entropy::LayerStack::PopOverlay(Layer* overlay)
{
	auto it = std::find(_layers.begin(), _layers.end(), overlay);
	if (it != _layers.end())
		_layers.erase(it);
}

std::vector<Entropy::Layer*>::iterator Entropy::LayerStack::begin()
{
	return _layers.begin();
}

std::vector<Entropy::Layer*>::iterator Entropy::LayerStack::end()
{
	return _layers.end();
}
