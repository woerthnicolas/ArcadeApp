#pragma once
#include <cstring>
#include <iostream>
#include <string>

class String
{
public:
    String(const String& other) = default;

    String(String&& other) noexcept : internalString(std::move(other.internalString))
    {
    }

    String& operator=(const String& other)
    {
        if (this == &other)
            return *this;
        internalString = other.internalString;
        return *this;
    }

    String& operator=(String&& other) noexcept
    {
        if (this == &other)
            return *this;
        internalString = std::move(other.internalString);
        return *this;
    }

    // Have a default constructor that is the empty string
    String();

    ~String() = default;

    // Have a constructor that takes in a string literal (ie. String("Hello"))
    explicit String(std::string string);

    // concatenate two Strings together and returns a new String object
    static String Concatenate(const String& firstString, const String& secondString);

    // return the length of the String object
    size_t Length() const;

    // return the character at an index
    bool CharAtIndex(size_t index, char& character) const;

    // find a substring and return the index of the first character of that substring
    size_t IndexCharOfSubstring(const String& substring) const;

    // return a String that is substring from a starting position and a length
    String Substring(size_t start, size_t length) const;

    // copy String types from one  to  another either through functions or assignment
    static std::string ToStdString(const String& inputString);
    static String FromStdString(const std::string& inputString);

    // Append a character to the string using operator+ (this should change the length of the String object)
    friend String operator+(const String& lhs, const char rhs);

    // return a const char* version of the string
    const char* ToConstCharPtr() const;

    friend bool operator<(const String& lhs, const String& rhs);

    friend bool operator<=(const String& lhs, const String& rhs);

    friend bool operator>(const String& lhs, const String& rhs);

    friend bool operator>=(const String& lhs, const String& rhs);

    // Check if two String objects are equal
    friend bool operator==(const String& lhs, const String& rhs);

    // Be displayed with cout (from <iostream>)
    friend std::ostream& operator<<(std::ostream& consoleOut, const String& string);

private:
    std::string internalString;
};
