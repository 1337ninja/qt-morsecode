#ifndef CONVERTER_H
#define CONVERTER_H

#include "converter_interface.h"

class Converter : public IConverter
{
public:
    const std::string plainTextToMorseCode(std::string plainText);
    char morseToPlaintext(std::string morseCode);
};

#endif // CONVERTER_H
