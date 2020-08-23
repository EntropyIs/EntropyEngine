#include "MouseEvent.h"

#include <sstream>

inline float Entropy::MouseMovedEvent::getX() const
{
    return x;
}

inline float Entropy::MouseMovedEvent::getY() const
{
    return y;
}

std::string Entropy::MouseMovedEvent::toString() const
{
    std::stringstream ss;
    ss << "MouseMovedEvent: " << x << ", " << y;
    return ss.str();
}

inline float Entropy::MouseScrolledEvent::getXOffset() const
{
    return xOffset;
}

inline float Entropy::MouseScrolledEvent::getYOffset() const
{
    return yOffset;
}

std::string Entropy::MouseScrolledEvent::toString() const
{
    std::stringstream ss;
    ss << "MouseScrolledEvent: " << xOffset << ", " << yOffset;
    return ss.str();
}

inline int Entropy::MouseButtonEvent::getButton() const
{
    return 0;
}

std::string Entropy::MouseButtonPressedEvent::toString() const
{
    std::stringstream ss;
    ss << "MouseButtonPressedEvent: " << mouseButton;
    return ss.str();
}

std::string Entropy::MouseButtonReleasedEvent::toString() const
{
    std::stringstream ss;
    ss << "MouseButtonReleasedEvent: " << mouseButton;
    return ss.str();
}
