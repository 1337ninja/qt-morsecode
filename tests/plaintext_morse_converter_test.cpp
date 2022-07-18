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
    void convert_valid_plaintext_to_morse()
    {
        PlaintextMorseConverter plaintextMorseConverter;
        std::string actual = plaintextMorseConverter.convert("hello");
        std::string expected("....x.x.-..x.-..x---");
        QCOMPARE(expected, actual);
    }

    void convert_invalid_plaintext()
    {
        PlaintextMorseConverter plaintextMorseConverter;
        std::string actual = plaintextMorseConverter.convert("@@");
        std::string expected("#x#");
        QCOMPARE(expected, actual);
    }

    void convert_valid_morse_to_plaintext()
    {
        PlaintextMorseConverter plaintextMorseConverter;
        std::string actual = plaintextMorseConverter.inverseConvert("....x.x.-..x.-..x---");
        std::string expected("HELLO");
        QCOMPARE(expected, actual);
    }

    void convert_invalid_morse_to_plaintext()
    {
        PlaintextMorseConverter plaintextMorseConverter;
        std::string actual = plaintextMorseConverter.inverseConvert("@x@");
        std::string expected("##");
        QCOMPARE(expected, actual);
    }
};

QTEST_MAIN(PlaintextMorseConverterTest)
#include "plaintext_morse_converter_test.moc"
