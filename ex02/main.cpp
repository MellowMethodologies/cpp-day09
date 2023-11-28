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

bool PmergeMe::is_sorted(std::map<int, std::pair<int, int> >& map)
{
    for (size_t i = 0; i + 1 < map.size() ; i++)
    {
        if (map[i].first > map[i + 1].first)
        {
            swaper(&map, i, i + 1);
            return false;
        }
    }
    return true;
}

void PmergeMe::ft_sort(std::map<int, std::pair<int, int> >& map)
{
    if (!is_sorted(map))
        ft_sort(map);
    else 
        return;
}

void PmergeMe::ft_inserting(std::map <int , std::pair<int, int> > map)
{
    std::map <int, int> chain;
    std::map <int, int> pend;

    for(size_t i = 0; i < map.size(); i++)
    {
        chain[i] = map[i].first;
        pend[i] = map[i].second;
    }

}

int jacob_gen(std::map<int, int> map)
{

}

std::map <int , std::pair<int, int> > ft_pairing(std::map<int, int> full_set)
{
    std::map <int , std::pair<int, int> > map;

    for (size_t i = 0, j = 0; i + 1 < full_set.size(); j++ , i += 2)
    {
        if (full_set[i + 1] < full_set[i])
        {
            map[j].first = full_set[i];
            map[j].second = full_set[i + 1];
        }
        else
        {
            map[j].first = full_set[i + 1];
            map[j].second = full_set[i];
        }
    }
    PmergeMe::ft_sort(map);
    for (size_t i = 0; i < map.size(); i++)
    {
        std::cout << map[i].first << " " << map[i].second << std::endl;
    }
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
        std::map<int, int> map;
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
            map[i] = std::atoi(av[j]);
            i++;
            j++;
        }
        PmergeMe::ft_inserting(ft_pairing(map));
    }
}