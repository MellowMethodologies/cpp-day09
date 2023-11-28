#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <map>
#include <deque>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& other);
    static void ft_inserting(std::map <int , std::pair<int, int> > map);
    static bool is_digits(std::string str);
    static void swaper(std::map<int, std::pair <int, int> >*, int, int);
    static bool is_sorted( std::map<int, std::pair<int, int> >& map);
    static void ft_sort(std::map<int, std::pair<int, int> >& map);

    void set_straggler(int straggler);
    int get_straggler() const;
    void set_odd(bool odd);
    bool get_odd() const;

private:
    int straggler;
    bool odd;
};

#endif // PmergeMe_HPP
