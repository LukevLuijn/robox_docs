//
// Created by luke on 15-05-22.
//

#ifndef TEMPLATE_STRING_H
#define TEMPLATE_STRING_H

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <typeinfo>
#include <vector>

namespace Utils
{
    enum class Color_e : uint8_t
    {
        NORMAL_BLACK = 30,
        NORMAL_RED = 31,
        NORMAL_GREEN = 32,
        NORMAL_YELLOW = 33,
        NORMAL_BLUE = 34,
        NORMAL_MAGENTA = 35,
        NORMAL_CYAN = 36,
        NORMAL_WHITE = 37,

        BRIGHT_BLACK = 90,
        BRIGHT_RED = 91,
        BRIGHT_GREEN = 92,
        BRIGHT_YELLOW = 93,
        BRIGHT_BLUE = 94,
        BRIGHT_MAGENTA = 95,
        BRIGHT_CYAN = 96,
        BRIGHT_WHITE = 97,

        NONE = 0,
    };

    class String
    {
    public:
        static bool ValidateNumber(float& value, const std::string& reading, float min, float max)
        {
            try
            {
                value = std::stof(std::string(reading));
                value = std::max(min, std::min(max, value));
                return true;
            }
            catch (std::invalid_argument& e)
            {
                std::cerr << "Exception caught " << e.what() << " [" << __PRETTY_FUNCTION__  << "]" << std::endl;
            }
            catch (std::out_of_range& e)
            {
                std::cerr << "Exception caught " << e.what()<< " [" << __PRETTY_FUNCTION__  << "]" << std::endl;
            }
            return false;
        }
        static std::vector<std::string> Divide(const std::string& str, char target)
        {
            std::stringstream ss(str);
            std::string token;
            std::vector<std::string> words;

            while (std::getline(ss, token, target))
            {
                words.emplace_back(token);
            }
            return words;
        }
        static std::vector<std::string> Divide(const std::string& str, char start, char stop)
        {
            std::vector<std::string> words = Divide(str, stop);
            for(std::string& word : words)
            {
                Remove(word, start);
            }
            return words;
        }
        template<typename T, uint32_t size>
        static std::array<std::string, size> ToString(std::array<T, size> list, uint8_t precision = 2)
        {
            std::array<std::string, size> newList;
            std::for_each(list.begin(), list.end(), [&precision, &newList](T number) {
                std::string element = ToString(number, precision);
                newList.template emplace_back(element);
            });
            return newList;
        }
        template<typename T>
        static std::vector<std::string> ToString(std::vector<T> list, uint8_t precision = 2)
        {
            std::vector<std::string> newList;
            std::for_each(list.begin(), list.end(), [&precision, &newList](T number) {
                std::string element = ToString(number, precision);
                newList.template emplace_back(element);
            });
            return newList;
        }
        template<typename T>
        static std::string ToString(T number, uint8_t precision = 2)
        {
            std::ostringstream os;
            os << std::fixed;
            os << std::setprecision(precision);
            os << number;

            return os.str();
        }
        static void Remove(std::string& str, char target)
        {
            str.erase(std::remove(str.begin(), str.end(), target), str.end());
        }
        static void Remove(std::string& str, const std::vector<char>& targets)
        {
            for(char target : targets)
            {
                str.erase(std::remove(str.begin(), str.end(), target), str.end());
            }
        }
        static void Replace(std::string& str, char target, char replacement)
        {
            std::replace(str.begin(), str.end(), target, replacement);
        }
        static void Encase(std::string& str, char element, Color_e color = Color_e::NONE)
        {
            str = Color(element, color) + str + Color(element, color);
        }
        static void Encase(std::string& str, char start, char stop, Color_e color = Color_e::NONE)
        {
            str = Color(start, color) + str + Color(stop, color);
        }
        static void RemoveEncasement(std::string& str)
        {
            str = str.substr(1, str.size() -2);
        }
        static std::string Color(const std::string& str, Color_e color)
        {
            if (color == Color_e::NONE)
            {
                return str;
            }
            else
            {
                return "\x1B[" + std::to_string(static_cast<uint8_t>(color)) + "m" + str + "\033[0m";
            }
        }
        static std::string Color(char el, Color_e color)
        {
            if (color == Color_e::NONE)
            {
                return std::string(1, el);
            }
            else
            {
                return "\x1B[" + std::to_string(static_cast<uint8_t>(color)) + "m" + el + "\033[0m";
            }
        }
    };
}// namespace Utils

#endif//TEMPLATE_STRING_H
