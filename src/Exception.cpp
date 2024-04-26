#include "Background/Exception.h"


RayException::RayException(const char* message) : message(message) {}

const char* RayException::what() const throw() {
    return this->message.c_str();
}

OutOfRangeException::OutOfRangeException(const char* message, const char* elementId) 
: RayException((std::string(message) + std::string(elementId)).c_str()) {}

NotAUnitTypeException::NotAUnitTypeException(const char* message, std::string typeLiteral)
: RayException((std::string(message) + typeLiteral).c_str()) {}

NoSuchElementException::NoSuchElementException(const char* message, std::string elementIndex)
: RayException((std::string(message) + elementIndex).c_str()) {}