#pragma once
#include <exception>
#include <string>

class RayException : public std::exception  {
protected:
    std::string message;
public:
    RayException(const char* message);
    const char* what() const throw();
};

class OutOfRangeException : public RayException {
public:
    OutOfRangeException(const char* message, const char* element_id);
};

class NotAUnitTypeException : public RayException {
public:
    NotAUnitTypeException(const char* message, std::string typeLiteral);
};