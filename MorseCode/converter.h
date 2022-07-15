#ifndef CONVERTER_H
#define CONVERTER_H

#include "converter_interface.h"

class Converter : public IConverter
{
    int spaces;
public:
    Converter();
    const std::string plainTextToMorseCode(const std::string& plainText);
    const std::string morseToPlaintext(const std::string& morseCode);
};

#endif // CONVERTER_H
