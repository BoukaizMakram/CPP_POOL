#include "easyfind.hpp"

int main()
{
    std::vector<int> values;
    values.push_back(1);
    values.push_back(2);
    values.push_back(2);
    values.push_back(2);
    values.push_back(2);
    values.push_back(10);
    values.push_back(2);
    values.push_back(2);
    try 
    {
        std::cout << "value found is: " << *(easyfind(values, 10)) << std::endl;
        easyfind(values, 12);
    }
    catch (const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    std::cout << "value found is: " << *(easyfind(values, 1)) << std::endl;
    return (0);
}