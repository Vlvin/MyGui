#include "Background/Exception.h"


Exception::Exception(const char* message) : message(message) {}

const char* Exception::what() const throw() {
    return this->message.c_str();
}

OutOfRangeException::OutOfRangeException(const char* message, const char* element_id) 
: Exception((std::string(message) + std::string(element_id)).c_str()) {}