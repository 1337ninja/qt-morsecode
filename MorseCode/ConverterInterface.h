#ifndef CONVERTERINTERFACE_H
#define CONVERTERINTERFACE_H

#include <string>

class IConverter
{
public:
    virtual std::string plainTextToMorseCode(char plainText) = 0;
    virtual char morseToPlaintext(std::string morseCode) = 0;
    virtual ~IConverter() {}
};

#endif // CONVERTERINTERFACE_H
