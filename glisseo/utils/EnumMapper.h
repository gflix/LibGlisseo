#ifndef GLISSEO_UTILS_ENUMMAPPER_H_
#define GLISSEO_UTILS_ENUMMAPPER_H_

#include <map>
#include <stdexcept>
#include <string>

namespace Glisseo
{

template<typename T>
T identifierToEnum(const std::map<std::string, T>& mapping,
                   const std::string& identifier)
{
    auto value = mapping.find(identifier);
    if (value == mapping.cend())
    {
        throw std::out_of_range("\"" + identifier + "\" is an invalid identifier");
    }
    return value->second;
}

template<typename T>
T identifierToEnumWithDefault(const std::map<std::string, T>& mapping,
                              const std::string& identifier,
                              T defaultValue)
{
    try
    {
        return identifierToEnum(mapping, identifier);
    }
    catch (std::out_of_range)
    {
        return defaultValue;
    }
}

template<typename T>
const std::string& enumToIdentifier(const std::map<std::string, T>& mapping,
                                    T value)
{
    std::string identifier;
    auto entry = mapping.cbegin();
    for (; entry != mapping.cend(); ++entry)
    {
        if (entry->second == value)
        {
            return entry->first;
        }
    }

    throw std::out_of_range("no identifier for given enum value found");
}

template<typename T>
const std::string& enumToIdentifierWithDefault(const std::map<std::string, T>& mapping, 
                                               T value,
                                               const std::string& defaultIdentifier)
{
    try
    {
        return enumToIdentifier(mapping, value);
    }
    catch (std::out_of_range)
    {
        return defaultIdentifier;
    }
}

} /* namespace Glisseo */

#endif /* GLISSEO_UTILS_ENUMMAPPER_H_ */
