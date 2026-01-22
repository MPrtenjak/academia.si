#ifndef PARSE_H
#define PARSE_H

#include <QString>
#include "Record.h"

bool parseRecord(const QString& line, Record& out);

#endif // PARSE_H
