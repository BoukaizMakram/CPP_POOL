#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span bigSpan(11000);
    std::vector<int> numbers;

    for (int i = 0; i < 11000; ++i)
        numbers.push_back(i * 3);

    bigSpan.addNumbers(numbers.begin(), numbers.end());

    std::cout << "Big Span - Shortest Span: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "Big Span - Longest Span: " << bigSpan.longestSpan() << std::endl;

    return 0;
}