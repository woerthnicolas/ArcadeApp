#include "String.h"

#include <utility>

String::String() = default;

String::String(std::string string)
{
    internalString = std::move(string);
}

String String::Concatenate(const String& firstString, const String& secondString)
{
    const std::string result = firstString.internalString + secondString.internalString;
    String final;
    final.internalString = result;
    return String(final);
}

size_t String::Length() const
{
    return internalString.length();
}

bool String::CharAtIndex(size_t index, char& character) const
{
    if (index > Length() - 1)
    {
        return false;
    }

    character = internalString.at(index);

    return true;
}

size_t String::IndexCharOfSubstring(const String& substring) const
{
    const std::size_t found = internalString.find(substring.internalString);
    if (found != std::string::npos)
    {
        return found;
    }

    return -1;
}

String String::Substring(size_t start, size_t length) const
{
    const std::string substring = internalString.substr(start, length);

    String outputString = String();
    outputString.internalString = substring;
    return outputString;
}

std::string String::ToStdString(const String& inputString)
{
    return inputString.internalString;
}

String String::FromStdString(const std::string& inputString)
{
    return String(inputString);
}

const char* String::ToConstCharPtr() const
{
    return internalString.c_str();
}

String operator+(const String& lhs, const char rhs)
{
    const std::string result = lhs.internalString + rhs;
    String final;
    final.internalString = result;
    return final;
}

bool operator<(const String& lhs, const String& rhs)
{
    return lhs.internalString < rhs.internalString;
}

bool operator<=(const String& lhs, const String& rhs)
{
    return !(rhs < lhs);
}

bool operator>(const String& lhs, const String& rhs)
{
    return rhs < lhs;
}

bool operator>=(const String& lhs, const String& rhs)
{
    return !(lhs < rhs);
}

bool operator==(const String& lhs, const String& rhs)
{
    return lhs.internalString == rhs.internalString;
}

std::ostream& operator<<(std::ostream& consoleOut, const String& string)
{
    std::cout << string.internalString << std::endl;
    return consoleOut;
}