#include "AppException.h"

AppException::AppException(const std::string& m) : msg(m) {}

const char* AppException::what() const noexcept {
    return msg.c_str();
}

AppException::~AppException() noexcept {}
