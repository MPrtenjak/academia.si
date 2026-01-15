#include "InvalidFieldException.h"
#include <string>

InvalidFieldException::InvalidFieldException(int lineNo,
    const std::string& fieldName,
    const std::string& value,
    const std::string& reason)
    : AppException(std::string("Neveljavno polje v vrstici ") +
        std::to_string(lineNo) + " (" + fieldName + "='" + value +
        "'): " + reason) {
}
