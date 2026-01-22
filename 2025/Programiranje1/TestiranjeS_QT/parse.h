#ifndef PARSE_H
#define PARSE_H

#include <QString>
#include "Record.h"

bool parseRecord(const QString& line, Record& out);

int NajdiMinimalnoStevilo(std::vector<int> seznam);

#endif // PARSE_H
