#include "RPN.hpp"

bool isoperation(int c)
{
    if ( c == '+' || c == '-' || c == '*' || c == '/')
        return true;
    return false;
}

std::stack <double> split_it(char *str)
{
    std::stack <double> s;
    int i = 0;
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            s.push(str[i] - '0');
            i++;
        }
        else if (str[i] == ' ')
        {
            i++;
            continue;
        }
        else if (isoperation(str[i]))
        {
            if (s.size() < 2)
            {
                std::cout << "wrong input" << std::endl;
                std::exit(0);
            }
            double a = s.top();
            s.pop();
            double b = s.top();
            s.pop();
            if (str[i] == '+')
                s.push(b + a);
            else if (str[i] == '-')
                s.push(b - a);
            else if (str[i] == '*')
                s.push(b * a);
            else if (str[i] == '/')
            {
                if (a == 0)
                {
                    std::cout << "wrong input" << std::endl;
                    std::exit(0);
                }
                s.push(b / a);
            }
        }
        else if (str[i] == '\0')
            break;
        else
        {
            std::cout << "wrong input : " << str[i]<< std::endl;
            std::exit(0);
        }
        i++;
    }
    return s;
}

int main(int ac, char **av){
    if (ac != 2){
        std::cout << "wrong number of arguments" << std::endl;
        return 0;
    }
    std::stack <double> s;

    s = split_it(av[1]);
    if (s.size() != 1)
    {
        std::cout << "wrong input" << std::endl;
        return 0;
    }
    else
        std::cout << static_cast<double>(s.top()) << std::endl;
}