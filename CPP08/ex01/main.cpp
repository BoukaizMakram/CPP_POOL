#include "Span.hpp"

int main()
{
    Span sp(5);

    try
    {
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4);
        sp.addNumber(11);
        std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
        std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return (0);
}