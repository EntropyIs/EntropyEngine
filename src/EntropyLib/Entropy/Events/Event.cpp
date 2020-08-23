#include "Event.h"

std::string Entropy::Event::toString() const
{
	return getName();
}

inline bool Entropy::Event::isInCategory(EventCategory category)
{
	return getCategoryFlags() & category;
}
