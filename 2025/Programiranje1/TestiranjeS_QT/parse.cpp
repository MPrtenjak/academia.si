#include "parse.h"

bool parseRecord(const QString& line, Record& out)
{
    const int sep = line.indexOf(';');
    if (sep <= 0) return false;                 // ni ';' ali pa je ime prazno

    const QString name = line.left(sep).trimmed();
    const QString pointsStr = line.mid(sep + 1);

    bool ok = false;
    const int points = pointsStr.toInt(&ok);
    // if (!ok) return false;
    if (!ok) throw std::exception();

    out.name = name;
    out.points = points;
    return true;
}
