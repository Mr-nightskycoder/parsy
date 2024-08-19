#ifndef DIGIT_PARSER_HPP_INCLUDED
#define DIGIT_PARSER_HPP_INCLUDED


#include <string>
#include <optional>
#include <utility>
#include <cctype>


namespace parsy {
    // Template structures for parsing digits in different bases

    template <int Radix>
    struct _d;

    template<>
    struct _d<2> // Specialization for binary digits.
    {
        static constexpr const char* char_class_name() {
            return "digit.binary";
        }
        static constexpr const char* char_class_ascii() {
            return "01";
        }

        template <typename CharT>
        static constexpr unsigned digit_value(CharT c) {
            return static_cast<unsigned>(c) - '0';
        }

        template <typename CharT>
        static constexpr bool is_digit(CharT c) {
            return c == '0' || c == '1';
        }
    };

    template <>
    struct _d<8> // Specialization for octal digits.
    {
        static constexpr const char* char_class_name() {
            return "digit.octal";
        }
    
        static constexpr const char* char_class_ascii() {
            return "01234567";
        }

        template <typename CharT>
        static constexpr unsigned digit_value(CharT c) {
            return static_cast<unsigned>(c) - '0';
        }

        template <typename CharT>
        static constexpr bool is_digit(CharT c) {
            return c >= '0' && c <= '7';
        }
    };


    template <>
    struct _d<10> // Specialization for decimal digits
    {
        static constexpr const char* char_class_name() {
            return "digit.decimal";
        }

        static constexpr const char* char_class_ascii() {
            return "0123456789";
        }

        template <typename CharT>
        static constexpr unsigned digit_value(CharT c) {
            return static_cast<unsigned>(c)-'0';
        }

        template <typename CharT> 
        static constexpr bool is_digit(CharT c) {
            return c >= '0' && c <= '9';
        }
    };

    template <>
    struct _d<16> // Specialization for hexadecimal digits
    {
        static constexpr const char* char_class_name() {
            return "digit.hex";
        }

        static constexpr const char* char_class_ascii() {
            return "0123456789abcdefABCDEF";
        }

        template <typename CharT>
        static constexpr unsigned digit_value(CharT c) {
            if (c >= 'a' && c <= 'f') {
                return static_cast<unsigned>(c) - 'a' + 10;
            } else if (c >= 'A' && c <= 'F') {
                return static_cast<unsigned>(c) - 'A' + 10;
            } else if (c >= '0' && c <= '9') {
                return static_cast<unsigned>(c) - '0';
            } else {
                return unsigned(-1); // Invalid digit.
            }
        }

        template <typename CharT>
        static constexpr bool is_digit(CharT c) {
            return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
        }

    };
}

#endif // DIGIT_PARSER_HPP_INCLUDED
