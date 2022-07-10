#ifndef CONVERTER_INTERFACE_H
#define CONVERTER_INTERFACE_H

#include <string>

class IConverter
{
public:
    virtual const std::string plainTextToMorseCode(char plainText) = 0;
    virtual char morseToPlaintext(std::string morseCode) = 0;
    virtual ~IConverter() {}
};

#endif // CONVERTER_INTERFACE_H
