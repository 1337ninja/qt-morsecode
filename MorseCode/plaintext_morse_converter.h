#ifndef PLAINTEXT_MORSE_CONVERTER_H
#define PLAINTEXT_MORSE_CONVERTER_H

#include "converter.h"
#include<string>

using IPlaintextMorseConverter = IConverter<const std::string, const std::string&,
                                            const std::string, const std::string&>;

class PlaintextMorseConverter : public IPlaintextMorseConverter
{
    int spaces;
public:
    PlaintextMorseConverter();
    /* Convert plaintext to morse */
    const std::string convert(const std::string& plainText);
    /* Convert morse to plaintext */
    const std::string inverseConvert(const std::string& morseCode);
};

#endif // PLAINTEXT_MORSE_CONVERTER_H
