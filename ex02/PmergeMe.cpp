#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe& other) {
}

PmergeMe::~PmergeMe() {
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
    }
    return *this;
}

void PmergeMe::swaper(std::map<int, std::pair <int, int> >*map, int index1, int index2)
{
    std::pair <int, int>tmp;

    tmp = (*map)[index1];
    (*map)[index1] = (*map)[index2];
    (*map)[index2] = tmp;
}


bool PmergeMe::is_digits(std::string str) {
    size_t i = 0;
    
    if (str[0] == '-' || str[0] == '+')
        i++;
    while ( i < str.length())
    {
        if (!isdigit(str[i]))
            return (false);
        i++;
    }
    return (true);
}

void PmergeMe::set_straggler(int straggler){
    straggler = straggler;
}

int PmergeMe::get_straggler() const{
    return straggler;
}

void PmergeMe::set_odd(bool odd){
    odd = odd;
}

bool PmergeMe::get_odd() const{
    return odd;
}
