#ifndef CONVERTER_INTERFACE_H
#define CONVERTER_INTERFACE_H

#include <string>

template <typename A, typename B, typename C, typename D>
class IConverter
{
public:
    virtual A convert(B data) = 0;
    virtual C inverseConvert(D data) = 0;
    virtual ~IConverter() {}
};

#endif // CONVERTER_INTERFACE_H
