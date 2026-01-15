#ifndef INVALID_FIELD_EXCEPTION_H
#define INVALID_FIELD_EXCEPTION_H

#include "AppException.h"
#include <string>

class InvalidFieldException : public AppException {
public:
    InvalidFieldException(int lineNo,
        const std::string& fieldName,
        const std::string& value,
        const std::string& reason);
};

#endif
