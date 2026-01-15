#ifndef CSV_FORMAT_EXCEPTION_H
#define CSV_FORMAT_EXCEPTION_H

#include "AppException.h"
#include <string>

class CsvFormatException : public AppException {
public:
    CsvFormatException(int lineNo, const std::string& line);
};

#endif
