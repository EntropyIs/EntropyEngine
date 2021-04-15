#include "ecpch.h"
#include "Layer.h"

Entropy::Layer::Layer(const std::string& name) : _name(name)
{
}

Entropy::Layer::~Layer()
{
}

const std::string& Entropy::Layer::GetName() const
{
	return _name;
}
