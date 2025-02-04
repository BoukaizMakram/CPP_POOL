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
    else
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