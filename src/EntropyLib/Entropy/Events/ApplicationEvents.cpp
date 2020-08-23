#include "ApplicationEvents.h"

#include <sstream>

inline unsigned int Entropy::WindowResizeEvent::getWidth()
{
    return width;
}

inline unsigned int Entropy::WindowResizeEvent::getHeight()
{
    return height;
}

std::string Entropy::WindowResizeEvent::toString() const
{
    std::stringstream ss;
    ss << "WindowREsizeEvent: " << width << ", " << height;
    return ss.str();
}
