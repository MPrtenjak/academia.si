#include "AppException.h"

AppException::AppException(const std::string& msg) : msg(msg) {}

const char* AppException::what() const noexcept {
    return msg.c_str();
}

AppException::~AppException() noexcept {}
