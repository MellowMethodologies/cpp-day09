#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <algorithm>

class RPN{
public:
    RPN(){}
    RPN(const RPN& other){
        *this = other;
    }
    ~RPN();
    RPN& operator=(const RPN& other){
        if (this != &other){
        }
        return *this;
    }

};

#endif // RPN_HPP
