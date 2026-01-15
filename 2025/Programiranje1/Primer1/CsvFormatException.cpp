#include "CsvFormatException.h"
#include <string>

CsvFormatException::CsvFormatException(int lineNo, const std::string& line)
    : AppException(std::string("Napacen CSV format v vrstici ") +
        std::to_string(lineNo) + ": '" + line + "' (manjka ';')") {
}
