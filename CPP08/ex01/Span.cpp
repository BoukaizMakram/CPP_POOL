#include "Span.hpp"

Span::Span() {}

Span::Span(const Span &other)
{
    *this = other;
}

Span& Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->N = other.N;
        for (unsigned int i = 0; i < other.Number.size(); i++)
            this->Number[i] = other.Number[i];
    }
    return (*this);
}

Span::Span(unsigned int N)
{
    this->N = N;
}

void Span::addNumber(int Number)
{
    if (this->Number.size() < N)
        this->Number.push_back(Number);
    else
        throw std::out_of_range("Span is already full!");
}

Span::~Span() {}

int Span::shortestSpan() 
{
    int minSpan = 0;

    if (Number.size() < 2)
        throw std::out_of_range("it should be more than 2 numbers stored to find the shortest span!");
    else
    {
        std::vector<int> sorted = Number;
        std::sort(sorted.begin(), sorted.end());

        minSpan = sorted[1] - sorted[0];
        for (size_t i = 0; i < sorted.size() - 1; ++i)
        {
            int span = sorted[i + 1] - sorted[i];
            if (span < minSpan)
                minSpan = span;
        }
        return minSpan;
    }
}

int Span::longestSpan() 
{
   if (Number.size() < 2)
        throw std::runtime_error("it should be more than 2 numbers stored to find the longest span!");
    
    int minVal = *std::min_element(Number.begin(), Number.end());
    int maxVal = *std::max_element(Number.begin(), Number.end());

    return maxVal - minVal;
}

void    Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
    while(begin != end)
    {
        this->addNumber(*begin);
        begin++;
    }
}