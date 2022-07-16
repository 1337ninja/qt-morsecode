#include "plaintext_morse_converter.h"
#include "constants.h"
#include <sstream>

PlaintextMorseConverter::PlaintextMorseConverter() : spaces(0) {}

const std::string PlaintextMorseConverter::convert(const std::string& plainText)
{
    std::string morse;
    for (int i = 0; i < plainText.size(); i++) {
        auto it = Constants::plainTextToMorse.find(plainText[i]);
        morse += (it != Constants::plainTextToMorse.end() ? it->second : "#");
        if (i != plainText.size() - 1) {
            if (plainText[i+1] != ' ')
                morse += Constants::morseCharDelimiter;
        }
    }
    return morse;
}

const std::string PlaintextMorseConverter::inverseConvert(const std::string& morseText)
{
    std::istringstream morse(morseText);
    std::string morseCode, plainText;
    while (std::getline(morse, morseCode, Constants::morseCharDelimiter)) {
        if (morseCode.empty()) {
            ++spaces;
            if (spaces % 2 != 0) {
                morseCode = Constants::morseWordDelimiter;
            }
            else {
                continue;
            }
        }
        else {
            spaces = 0;
        }
        auto it = Constants::morseToPlainText.find(morseCode);
        plainText +=  ( it != Constants::morseToPlainText.end() ? it->second : '#');
    }
    return plainText;
}
