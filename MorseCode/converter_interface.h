#ifndef CONVERTER_INTERFACE_H
#define CONVERTER_INTERFACE_H

#include <string>

class IConverter
{
public:
    virtual const std::string plainTextToMorseCode(const std::string& plainText) = 0;
    virtual const std::string morseToPlaintext(const std::string& morseCode) = 0;
    virtual ~IConverter() {}
};

#endif // CONVERTER_INTERFACE_H
