#pragma once
#include <vector>
#include <iostream>

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
        Span& operator=(const Span &other);
        void addNumber(int number);
};