#include "converter.h"
#include "constants.h"

const std::string Converter::plainTextToMorseCode(char plainText)
{
    auto it = Constants::plainTextToMorse.find(plainText);
    if (it != Constants::plainTextToMorse.end()) {
        return it->second;
    }
    return "#";
}

char Converter::morseToPlaintext(std::string morseCode)
{
    return '#'; // TODO
}
