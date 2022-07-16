#ifndef PLAINTEXT_MORSE_CONVERTER_H
#define PLAINTEXT_MORSE_CONVERTER_H

#include "converter.h"
#include<string>
#include <map>

using IPlaintextMorseConverter = IConverter<const std::string, const std::string&,
                                            const std::string, const std::string&>;

class PlaintextMorseConverter : public IPlaintextMorseConverter
{
private:
    int spaces;
    const char morseCharDelimiter;
    const std::string morseWordDelimiter;
    const std::map<char, std::string> plainTextToMorse;
    const std::map<std::string, char> morseToPlainText;

public:
    PlaintextMorseConverter();
    /* Convert plaintext to morse */
    const std::string convert(const std::string& plainText);
    /* Convert morse to plaintext */
    const std::string inverseConvert(const std::string& morseCode);
};

#endif // PLAINTEXT_MORSE_CONVERTER_H
