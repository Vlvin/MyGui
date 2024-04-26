#include "Background/Exception.h"


RayException::RayException(const char* message) : message(message) {}

const char* RayException::what() const throw() {
    return this->message.c_str();
}

OutOfRangeException::OutOfRangeException(const char* message, const char* element_id) 
: RayException((std::string(message) + std::string(element_id)).c_str()) {}

NotAUnitTypeException::NotAUnitTypeException(const char* message, std::string typeLiteral)
: RayException((std::string(message) + typeLiteral).c_str()) {}