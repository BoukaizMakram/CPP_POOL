#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2) 
    {
        std::cerr << "Error: Provide a single RPN expression as an argument." << std::endl;
        return (1);
    }

    RPN::evaluate(av[1]);
    return (0);
}