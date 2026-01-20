#include <QTest>

#include <QString>

struct Record
{
    QString name;
    int points = 0;
};

inline bool parseRecord(const QString& line, Record& out)
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

class primer1 : public QObject
{
    Q_OBJECT

public:
    primer1();
    ~primer1();

private slots:
    void test_case1();

    void WhenInputIsCorrect_then_ExpectCorrectResult();
    void WhenInputIsCorrect_then_ExpectCorrectResult1();
    void WhenInputISIncorrect_the_ExcpectFail();
    void WhenInputISIncorrect_the_ExcpectFail1();
    void WhenInputHasSpaces_the_ExcpectNoSpaces();
    void WhenNumberIsNegative_then_ExpectCorrectResult();
    void WhenNumberIsNotInteger_then_ExpectException();
};

primer1::primer1() {}

primer1::~primer1() {}

void primer1::test_case1() {}

void primer1::WhenInputIsCorrect_then_ExpectCorrectResult() {
    // ARR
    QString test = "jan;2423";

    // ACT
    Record vhod;
    bool rezultat = parseRecord(test, vhod);

    // ASS
    QCOMPARE(rezultat, true);
    QCOMPARE(vhod.name, "jan");
    QCOMPARE(vhod.points, 2423);
}

void primer1::WhenInputIsCorrect_then_ExpectCorrectResult1() {
    // ARR
    QString test = "feb;111";

    // ACT
    Record vhod;
    bool rezultat = parseRecord(test, vhod);

    // ASS
    QCOMPARE(rezultat, true);
    QCOMPARE(vhod.name, "feb");
    QCOMPARE(vhod.points, 111);
}


void primer1::WhenInputISIncorrect_the_ExcpectFail() {
    // ARR
    QString test = "xxxxxxx";

    // ACT
    Record vhod;
    bool rezultat = parseRecord(test, vhod);

    // ASS
    QCOMPARE(rezultat, false);
}


void primer1::WhenInputISIncorrect_the_ExcpectFail1() {
    // ARR
    QString test = "xxxx;xxx";

    // ACT
    Record vhod;
    QVERIFY_THROWS_EXCEPTION(std::exception, bool rezultat = parseRecord(test, vhod));
}


void primer1::WhenInputHasSpaces_the_ExcpectNoSpaces() {
    // ARR
    QString test = "        Matilda     ;   12   ";

    // ACT
    Record vhod;
    bool rezultat = parseRecord(test, vhod);

    // ASS
    QCOMPARE(rezultat, true);
    QCOMPARE(vhod.name, "Matilda");
    QCOMPARE(vhod.points, 12);
}


void primer1::WhenNumberIsNegative_then_ExpectCorrectResult() {
    // ARR
    QString test = "xxx;-13";

    // ACT
    Record vhod;
    bool rezultat = parseRecord(test, vhod);

    // ASS
    QCOMPARE(rezultat, true);
    QCOMPARE(vhod.name, "xxx");
    QCOMPARE(vhod.points, -13);
}

void primer1::WhenNumberIsNotInteger_then_ExpectException() {
    // ARR
    QString test = "xxx;-13.14";

    // ACT
    Record vhod;
    QVERIFY_THROWS_EXCEPTION(std::exception, bool rezultat = parseRecord(test, vhod));

}

QTEST_APPLESS_MAIN(primer1)

#include "tst_primer1.moc"
