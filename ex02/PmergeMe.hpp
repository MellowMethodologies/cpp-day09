#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <iostream>
#include <deque>
#include <vector>

class PmergeMe {
public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    ~PmergeMe();
    PmergeMe& operator=(const PmergeMe& other);
    static void ft_inserting(PmergeMe &,std::vector < std::pair<int, int> > map);
    static bool is_digits(std::string str);
    static void swaper(std::vector<std::pair <int, int> >*, int index1, int index2);
    static bool is_sorted( std::vector<std::pair<int, int> >& map);
    static void ft_sort(std::vector<std::pair<int, int> >& map);
    static void buildJacobInsertionSequence(std::vector<int>& pend, std::vector<int>& jacobSeq);
    static void insertStraggler(std::vector<int>& S, int straggler);
    static void createS(PmergeMe &o, std::vector<int>& sortedPairs, std::vector<int>& pend);
    static std::vector <std::pair<int, int> > ft_pairing(std::vector<int> full_set);

    void set_straggler(int straggler);
    int get_straggler() const;
    void set_odd(bool odd);
    bool get_odd() const;
    void set_mainchain(std::vector <int> main_chain);
    void print_mainchain();
private:
    std::vector <int> main_chain;
    int straggler;
    bool odd;
};

int Jacobsthal(int n);


#endif // PmergeMe_HPP

