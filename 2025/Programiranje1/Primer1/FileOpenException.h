#ifndef FILE_OPEN_EXCEPTION_H
#define FILE_OPEN_EXCEPTION_H

#include "AppException.h"
#include <string>

class FileOpenException : public AppException {
public:
    explicit FileOpenException(const std::string& filename);
};

#endif
