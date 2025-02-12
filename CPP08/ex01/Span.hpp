#pragma once
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>

class Span
{
    private:
        unsigned int N;
        std::vector<int> Number;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        ~Span();

        Span&   operator=(const Span &other);
        void    addNumber(int number);
        void    addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        int     shortestSpan() ;
        int     longestSpan() ;
};