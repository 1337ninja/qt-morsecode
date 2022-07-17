#include <QObject>
#include <QTest>
#include <QDebug>
#include <QString>
#include <string>
#include "plaintext_morse_converter.h"

class PlaintextMorseConverterTest: public QObject
{
    Q_OBJECT

private slots:
    void initTestCase()
    {}

    void convert_plaintext_to_morse()
    {
        PlaintextMorseConverter plaintextMorseConverter;
        std::string actual = plaintextMorseConverter.convert("hello");
        std::string expected("....x.x.-..x.-..x---");
        QCOMPARE(expected, actual);
    }

    void cleanupTestCase()
    {}
};

QTEST_MAIN(PlaintextMorseConverterTest)
#include "plaintext_morse_converter_test.moc"
