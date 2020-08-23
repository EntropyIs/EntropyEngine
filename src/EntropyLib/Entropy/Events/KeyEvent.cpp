#include "KeyEvent.h"

#include <sstream>

inline int Entropy::KeyEvent::getKeyCode() const
{
    return keyCode;
}

std::string Entropy::KeyPressedEvent::toString() const
{
    std::stringstream ss;
    ss << "KeyPressedEvent: " << keyCode << " (" << repeatCount << " repeats)";
    return ss.str();
}

std::string Entropy::KeyReleasedEvent::toString() const
{
    std::stringstream ss;
    ss << "KeyReleasedEvent: " << keyCode;
    return ss.str();
}
