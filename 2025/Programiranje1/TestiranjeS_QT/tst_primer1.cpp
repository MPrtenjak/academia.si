#include <QTest>

#include <QString>
#include "Record.h"
#include "parse.h"

class primer1 : public QObject
{
    Q_OBJECT

public:
    primer1();
    ~primer1();

private slots:
    void test_case1();

    void parseTest_data();
    void parseTest();

    void testirajMinStevilo_data();
    void testirajMinStevilo();

    /*
    void WhenInputIsCorrect_then_ExpectCorrectResult();
    void WhenInputIsCorrect_then_ExpectCorrectResult1();
    void WhenInputISIncorrect_the_ExcpectFail();
    void WhenInputISIncorrect_the_ExcpectFail1();
    void WhenInputHasSpaces_the_ExcpectNoSpaces();
    void WhenNumberIsNegative_then_ExpectCorrectResult();
    void WhenNumberIsNotInteger_then_ExpectException();
    */
};

primer1::primer1() {}

primer1::~primer1() {}

void primer1::testirajMinStevilo_data()
{
    QTest::addColumn<std::vector<int>>("seznam");
    QTest::addColumn<int>("minVrednost");

    QTest::newRow("t1") << std::vector<int>({ }) << 1;
    QTest::newRow("t2") << std::vector<int>({ 12 }) << 12;
    QTest::newRow("t3") << std::vector<int>({ -15 }) << -15;
    QTest::newRow("t4") << std::vector<int>({ 12, 3 }) << 3;
    QTest::newRow("t5") << std::vector<int>({ 3, 12 }) << 3;
    QTest::newRow("t6") << std::vector<int>({ -15, 7, -8 }) << -15;
    QTest::newRow("t7") << std::vector<int>({ 7, -15, -8 }) << -15;
    QTest::newRow("t8") << std::vector<int>({ 7, -8, -15 }) << -15;
    QTest::newRow("t9") << std::vector<int>({ -15, 7, -8, 5,6,7,8,9,34,6454,7,56, -456 }) << -456;
    QTest::newRow("t10") << std::vector<int>({ 100000000, 1000000001, 1000000002 }) << 100000000;

/*
    QTest::newRow("t7") << std::vector<int>({ 1, 2, 3}) << 1;
    QTest::newRow("t8") << std::vector<int>({ 1, 2, 3}) << 1;
    QTest::newRow("t9") << std::vector<int>({ 1, 2, 3}) << 1;
    QTest::newRow("t10") << std::vector<int>({ 1, 2, 3}) << 1;
    QTest::newRow("t11") << std::vector<int>({ 1, 2, 3}) << 1;
    QTest::newRow("t12") << std::vector<int>({ 1, 2, 3}) << 1;
*/
}

void primer1::testirajMinStevilo()
{
    // ARR
    QFETCH(std::vector<int>, seznam);
    QFETCH(int, minVrednost);

    try {
        int rezultat = NajdiMinimalnoStevilo(seznam);

        QCOMPARE(rezultat, minVrednost);
    }
    catch (...) {
        QCOMPARE(seznam.size(), 0);
    }
}


void primer1::parseTest_data()
{
//    QString	bool
//        dataLine	dataSuccess

    QTest::addColumn<QString>("dataLine");
    QTest::addColumn<bool>("expectThrow");
    QTest::addColumn<bool>("dataSuccess");
    QTest::addColumn<QString>("dataName");
    QTest::addColumn<int>("dataPoints");

    QTest::newRow("WhenInputIsCorrect_then_ExpectCorrectResult")
        << QString("jan;2423")
        << false
        << true
        << QString("jan")
        << 2423;

    QTest::newRow("WhenPointsAre0_then_ExpectCorrectResult")
        << QString("feb;0")
        << false
        << true
        << QString("feb")
        << 0;

    QTest::newRow("WhenInputDoesNotHaveComma_the_ExcpectFail")
        << QString("xxxxxxx")
        << false
        << false;

    QTest::newRow("WhenInputIsNotInteger_the_ExcpectException")
        << QString("xxxx;xxx")
        << true;

    QTest::newRow("WhenInputHasSpaces_the_ExcpectNoSpaces")
        << QString("        Matilda     ;   12   ")
        << false
        << true
        << QString("Matilda")
        << 12;

    QTest::newRow("WhenInputHasSpacesInTheName_the_ExcpectSpacesWillRemainInTheName")
        << QString("        Ana   Lisa     ;   12   ")
        << false
        << true
        << QString("Ana   Lisa")
        << 12;

    QTest::newRow("WhenNumberIsNegative_then_ExpectCorrectResult")
        << QString("xxx;-13")
        << false
        << true
        << QString("xxx")
        << -13;

    QTest::newRow("WhenNumberIsNotInteger_then_ExpectException")
        << QString("xxx;13.4")
        << true;
}

void primer1::parseTest()
{
    // ARR
    QFETCH(QString, dataLine);
    QFETCH(bool, expectThrow);

    if (expectThrow) {
        Record rec;
        QVERIFY_THROWS_EXCEPTION(std::exception, bool rezultat = parseRecord(dataLine, rec));
        return;
    }

    QFETCH(bool, dataSuccess);

    // ACT
    Record rec;
    bool rezultat = parseRecord(dataLine, rec);

    // ASS
    QCOMPARE(rezultat, dataSuccess);

    if (dataSuccess) {
        QFETCH(QString, dataName);
        QFETCH(int, dataPoints);

        QCOMPARE(rec.name, dataName);
        QCOMPARE(rec.points, dataPoints);
    }
}

void primer1::test_case1() {}

/*
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
*/

QTEST_APPLESS_MAIN(primer1)

#include "tst_primer1.moc"
