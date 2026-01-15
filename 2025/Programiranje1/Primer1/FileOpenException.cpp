#include "FileOpenException.h"

FileOpenException::FileOpenException(const std::string& filename)
    : AppException(std::string("Datoteke ni mogoce odpreti: ") + filename) {
}
