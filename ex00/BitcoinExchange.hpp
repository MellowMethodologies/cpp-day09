#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <stdio.h>

class BitcoinExchange {
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& other);
        ~BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange& other);
        static bool is_digits(std::string str);
        static bool isleapyear(unsigned short year);
        static bool valid_date(unsigned short year, unsigned short month, unsigned short day);
        static std::string   strTrim(std::string str, std::string chars);
        static std::pair<std::string, std::string> split_it(std::string string, char sep);
        static int parse_input(std::pair<std::string, std::string>it);
};

#endif // BitcoinExchange_HPP
