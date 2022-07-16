#ifndef CONVERTER_H
#define CONVERTER_H

#include "converter_interface.h"

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

#endif // CONVERTER_H
