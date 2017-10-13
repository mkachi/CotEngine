#pragma once

#include <codecvt>
#include <algorithm>
#include <vector>
#include <string>
#include "CotDefine.h"

inline std::string ReplaceAll(const std::string& str, const std::string& beforeStr, const std::string& newStr) 
{
    std::string result = str;
    std::string::size_type position = 0;
    while ((position = result.find(beforeStr, position)) != std::string::npos)
    {
        result.replace(position, beforeStr.length(), newStr);
        position += newStr.length();
    }
    return result;
}

inline std::vector<std::string> Split(const std::string& str, const std::string& delimiter)
{
    std::string::size_type begin = 0;
    std::string::size_type end = str.find_first_of(delimiter);

    std::vector<std::string> result;

    while (1)
    {
        std::string token = str.substr(begin, end - begin);
        if (!token.empty())
        {
            result.push_back(token);
        }

        if (end == std::string::npos)
        {
            break;
        }

        begin = end + 1;
        end = str.find_first_of(delimiter, begin);
    }
    return result;
}
inline std::vector<std::string> Split(const std::string& str, const std::initializer_list<std::string>& delimiters)
{
    std::string original = str;
    std::string delimiter = "";
    for (auto& data : delimiters)
    {
        if (delimiter == "")
        {
            delimiter = "[@#" + data + "#@]";
        }
        original = ReplaceAll(original, data, delimiter);
    }

    std::string::size_type begin = 0;
    std::string::size_type end = original.find_first_of(delimiter);

    std::vector<std::string> result;

    while (1)
    {
        std::string token = original.substr(begin, end - begin);
        if (!token.empty())
        {
            result.push_back(token);
        }

        if (end == std::string::npos)
        {
            break;
        }

        begin = end + 1;
        end = original.find_first_of(delimiter, begin);
    }
    return result;
}

template<typename T>
inline std::string ToString(const T& value)
{
    return std::to_string(value);
}
inline std::string ToString(const std::wstring& value)
{
	const wchar_t* str = value.c_str();
	size_t size = value.capacity();

	char* buffer = new char[size];
	wcstombs_s(&size, buffer, size, str, size);

	std::string result = buffer;
	Cot::SafeDelete(buffer);

	return result;
}

template<typename T>
inline std::string ToWString(const T& value)
{
    return std::to_wstring(value);
}
inline std::wstring ToWString(const std::string& value)
{
	const char* str = value.c_str();
	size_t size = value.capacity();

	wchar_t* buffer = new wchar_t[size];
	mbstowcs_s(&size, buffer, size, str, size);

	std::wstring result = buffer;
	Cot::SafeDelete(buffer);

	return result;
}