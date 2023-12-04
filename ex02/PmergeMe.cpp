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

void PmergeMe::swaper(std::vector <std::pair<int, int> >*vec, int index1, int index2)
{
    std::pair <int, int>tmp;

    tmp = (*vec)[index1];
    (*vec)[index1] = (*vec)[index2];
    (*vec)[index2] = tmp;
}

bool PmergeMe::is_sorted(std::vector<std::pair<int, int> >& tmp)
{
    for (size_t i = 0; i + 1 < tmp.size() ; i++)
    {
        if (tmp[i].first > tmp[i + 1].first)
        {
            swaper(&tmp, i, i + 1);
            return false;
        }
    }
    return true;
}

void PmergeMe::ft_sort(std::vector<std::pair<int, int> >& vec)
{
    if (!is_sorted(vec))
        ft_sort(vec);
    else 
        return;
}

void createS(PmergeMe &o, std::vector <std::pair<int, int> >& sortedPairs, std::vector <std::pair<int, int> >& pend)
{

}


void PmergeMe::ft_inserting(PmergeMe &o, std::vector < std::pair<int, int> > vec)
{
    std::vector <int > chain;
    std::vector <int > pend;

    for(size_t i = 0; i < vec.size(); i++)
    {
        chain.push_back(vec[i].first);
        pend.push_back(vec[i].second);
    }
    PmergeMe::createS(o ,chain, pend);
}

void PmergeMe::print_mainchain()
{
    for (size_t i = 0; i < main_chain.size(); i++)
        std::cout << main_chain[i] << std::endl;
}

int jacobsthal(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return jacobsthal(n - 1) + 2 * jacobsthal(n - 2);
}

std::vector <int>fun(int a, int b){
    std::vector <int> v;
    std::cerr << "a: " << a << std::endl;
    std::cerr << "b: " << b << std::endl;
    while(--b > a)
        v.push_back(b); 
    return v;
}

std::vector <int> jacobsthal_sequence(std::vector <int, int> v){
    std::vector <int> v1;
    std::vector <int> v2;
    int i = 3;

    v1.push_back(jacobsthal(i - 1));
    while(i < v.size()){
        v1.push_back(jacobsthal(i));
        v2 = fun(jacobsthal(i - 1), jacobsthal(i));
        v1.insert(v1.end(), v2.begin(), v2.end());
        if (v1.size() > v.size()){
            v2.resize(v.size());
            break;
        }
        v2.clear();
        i++;
    }
    return v1;
}

void PmergeMe::set_mainchain(std::vector <int> main_chain){
    main_chain = main_chain;
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
