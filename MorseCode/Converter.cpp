#include "converter.h"
#include "constants.h"

const std::string Converter::plainTextToMorseCode(std::string plainText)
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

char Converter::morseToPlaintext(std::string morseCode)
{
    auto it = Constants::morseToPlainText.find(morseCode);
    if (it != Constants::morseToPlainText.end()) {
        return it->second;
    }
    return '#';
}
