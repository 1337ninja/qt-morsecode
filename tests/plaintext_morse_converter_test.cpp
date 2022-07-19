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

    void convert_valid_plaintext_with_spaces_and_nos_to_morse()
    {
        PlaintextMorseConverter plaintextMorseConverter;
        std::string actual = plaintextMorseConverter.convert("IT IS 10 AM");
        std::string expected("..x-xxx..x...xxx.----x-----xxx.-x--");
        QCOMPARE(expected, actual);
    }

    void convert_valid_plaintext_to_morse_last_char_should_not_have_char_delimiter()
    {
        PlaintextMorseConverter plaintextMorseConverter;
        std::string actual = plaintextMorseConverter.convert("AB");
        std::string expected(".-x-..."); // no 'x' at the last
        QCOMPARE(expected, actual);
    }

    void convert_valid_plaintext_to_morse_consecutive_spaces_should_not_have_char_delimiter_in_between_them()
    {
        PlaintextMorseConverter plaintextMorseConverter;
        std::string actual = plaintextMorseConverter.convert("  "); // 2 spaces
        std::string expected("xxxx"); // should not be "xxxxx"
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

    void convert_valid_morse_with_spaces_and_nos_to_plaintext()
    {
        PlaintextMorseConverter plaintextMorseConverter;
        std::string actual = plaintextMorseConverter.inverseConvert("..x-xxx..x...xxx.----x-----xxx.-x--");
        std::string expected("IT IS 10 AM");
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
