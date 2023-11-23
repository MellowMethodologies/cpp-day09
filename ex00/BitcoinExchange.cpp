#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
    *this = other;
}

BitcoinExchange::~BitcoinExchange() {
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
    }
    return *this;
}

bool BitcoinExchange::is_digits(std::string str) {
    for (size_t i = 0; i < str.length(); i++)

        if (!isdigit(str[i]))
            return (false);
    return (true);
}

bool BitcoinExchange::isleapyear(unsigned short year) {
    return (!(year % 4) && (year % 100) || !(year % 400));
}
bool BitcoinExchange::valid_date(unsigned short year, unsigned short month, unsigned short day) {
    unsigned int monthlen[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if (year <= 2008 || month <= 0 ||  day > 31 || day <= 0 || month > 12)
        return 0;
    if (isleapyear(year) && month == 2)
        monthlen[1]++;
    if (day > monthlen[month-1])
        return 0;
    return 1;
}

std::string BitcoinExchange::strTrim(std::string str, std::string chars)
{
    std::string::size_type pos = str.find_last_not_of(chars);
    if (pos != std::string::npos)
        str.erase(pos + 1);
    else
        str.clear();
    pos = str.find_first_not_of(chars);
    if (pos != std::string::npos)
        str.erase(0, pos);
    return (str);
}

std::pair<std::string, std::string>BitcoinExchange:: split_it(std::string string, char sep)
{
    std::pair<std::string, std::string > m;
    size_t t = string.find(sep);
    if (t == std::string::npos)
    {
        m.first = "err";
        m.second = "Bad Input " + strTrim(string.substr(0, t), "\n\v ");
        return m;
    }
    m.first = strTrim(string.substr(0, t), "\n\v ");
    m.second = strTrim(string.substr(t + 1), "\n\v ");
    
    return m;
}

int BitcoinExchange::parse_input(std::pair<std::string, std::string>it)
{
    if (it.first.length() > 10 || it.first[4] != '-' || it.first[7] != '-' || it.first.length() < 10)
    {
        std::cerr <<"Error: " << "Bad INPUT :" << it.first << " | " << it.second<< std::endl;
        return (0);
    }
    else if (!is_digits(it.first.substr(0, 4)) || !is_digits(it.first.substr(5, 2)) || !is_digits(it.first.substr(8, 2)))
    {
        std::cerr <<"Error: " << "Bad INPUT :" << it.first << " | " << it.second<< std::endl;
        return (0);
    }
    else if (
    !valid_date(std::atoi(it.first.substr(0, 4).c_str()), std::atoi(it.first.substr(5, 2).c_str()), std::atoi(it.first.substr(8, 2).c_str())))
    {
        std::cerr <<"Error: " << "Bad INPUT :" << it.first << " | " << it.second<< std::endl;
        return (0);
    }
    else if (std::atof(it.second.c_str()) <= 0)
    {
        std::cerr <<"Error: " << " not a positive number." << std::endl;
        return (0);
    }
    else if (std::atof(it.second.c_str()) > 1000)
    {
        std::cerr << "Error: too large a number." << std::endl;
        return (0);
    }
    else if (it.first == "err")
    {
        std::cout << "Error: " << it.second << std::endl;
        return (0);
    }
    return 1;
}