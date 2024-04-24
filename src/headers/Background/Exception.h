#pragma once
#include <exception>
#include <string>

class Exception : public std::exception  {
protected:
    std::string message;
public:
    Exception(const char* message);
    const char* what() const throw();
};

class OutOfRangeException : public Exception {
public:
    OutOfRangeException(const char* message, const char* element_id);
};