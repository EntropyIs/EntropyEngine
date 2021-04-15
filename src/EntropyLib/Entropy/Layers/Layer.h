#pragma once

#include "Entropy/Tools/API.h"
#include "Entropy/Events/Event.h"

namespace Entropy
{
	class ENTROPY_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		const std::string& GetName() const;

	protected:
		std::string _name;
	};
}