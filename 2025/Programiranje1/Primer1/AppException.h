#ifndef APP_EXCEPTION_H
#define APP_EXCEPTION_H

#include <exception>
#include <string>

class AppException : public std::exception {
protected:
    std::string msg;

public:
    explicit AppException(const std::string& m);
    virtual const char* what() const noexcept;
    virtual ~AppException() noexcept;
};

#endif
