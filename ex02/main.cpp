#include "PmergeMe.hpp"

void printer(int a[])
{
    std::cout << "Before: " << a << std::endl;
    std::cout << "After: " << a << std::endl;
}

bool parser (char **av)
{
    int i = 1;

    while(av[i])
    {
        if (PmergeMe::is_digits(av[i]))
            i++;
        else
            return 0;
    }
    return 1;
}

std::vector <std::pair<int, int> > ft_pairing(std::vector<int> full_set)
{
    std::vector <std::pair<int, int> > vec;

    for (size_t i = 0, j = 0; i + 1 < full_set.size(); j++ , i += 2)
    {
        if (full_set[i + 1] < full_set[i])
        {
            vec[j].first = full_set[i];
            vec[j].second = full_set[i + 1];
        }
        else
        {
            vec[j].first = full_set[i + 1];
            vec[j].second = full_set[i];
        }
    }
    return vec;
}

int main(int ac, char** av)
{
    if (ac == 1) {
        std::cerr << "Usage: " << av[0] << " <number(s) at least 1>" << std::endl;
        return 1;
    }
    else if (!parser(av)) {
        std::cerr << "Usage: " << av[0] << " <number(s) at least 1>" << std::endl;
        return 1;
    }
    else
    {
        std::deque<int> deque;
        std::vector<int> vector;
        PmergeMe p;
        int i = 0;
        int j = 1;

        if ((ac - 1) % 2 != 0)
        {
            p.set_odd(true);
            p.set_straggler(std::atoi(av[ac - 1]));
        }
        else
        {
            p.set_odd(false);
            p.set_straggler(0);
        }
        while (av[j])
        {
            deque.push_back(std::atoi(av[j]));
            vector.push_back(std::atoi(av[j]));
            i++;
            j++;
        }
        p.ft_inserting(p, ft_pairing(vector));
        // p.print_mainchain();
    }
}