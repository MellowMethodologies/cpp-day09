#include "BitcoinExchange.hpp"
#include <algorithm>

int main (int ac, char **av){
    if (ac != 2)
    {
        std::cout << "wrong number of arguments" << std::endl;
        return 0;
    }
    std::ifstream a(av[1]);
    std::ifstream db("data.csv");
    std::string tmp;
    std::pair<std::string, std::string> tmp1;
    std::vector <std::pair<std::string, std::string> >v_db;
    std::vector <std::pair<std::string, std::string> >::iterator it;

    if (!a)
    {
        std::cerr << "error can't open file" << av[1] << std::endl;
        return 0;
    }
    else if (!db)
    {
        std::cerr << "an error occured with the data base" << av[1] << std::endl;
        return 0;
    }
    while (std::getline(db, tmp))
        v_db.push_back(BitcoinExchange::split_it(tmp, ','));
    while (std::getline(a, tmp))
    {
        tmp1 = BitcoinExchange::split_it(tmp, '|');
        if (!BitcoinExchange::parse_input(tmp1))
            continue;
        else
        {
            it = std::lower_bound(v_db.begin(), v_db.end(), tmp1);
            std::cout << tmp1.first << " => " << tmp1.second << " = " << std::atof(it->second.c_str()) * std::atof(tmp1.second.c_str()) << std::endl;
        }
    }
    a.close();
    db.close();
}