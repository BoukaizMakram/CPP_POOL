#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN& other) { (void)other; }
RPN& RPN::operator=(const RPN& other) { (void)other; return *this; }
RPN::~RPN() {}

void RPN::evaluate(const std::string& expression)
{
    std::stack<int> stack;
    std::stringstream ss(expression);
    std::string token;

    while(ss >> token)
    {
        if (std::isdigit(token[0]))
            stack.push(std::atoi(token.c_str()));
        else if (token.length() == 1 && std::string("+-*/").find(token) != std::string::npos)
        {
            if (stack.size() < 2)
            {
                std::cerr << "Error: Not enough operands for operation '" << token << "'." << std::endl;
                return ;
            }
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            int result;
            switch(token[0])
            {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/':
                    if (b == 0)
                    {
                        std::cerr << "Error: Division by zero." << std::endl;
                        return ;
                    }
                    result = a / b;
                    break;
                default:
                    std::cerr << "Error: Invalid operator '" << token << "'." << std::endl;
                    return ;
            }
            stack.push (result);
        }
        else {
            std::cerr << "Error: Invalid token '" << token << "'." << std::endl;
            return ;
        }
    }

    if (stack.size() != 1) 
    {
        std::cerr << "Error: Invalid RPN expression." << std::endl;
        return ;
    }

    std::cout << stack.top() << std::endl;
}