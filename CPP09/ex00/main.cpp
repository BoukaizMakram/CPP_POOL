#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " database_file.csv "<< "input_file" << std::endl;
        return (1);
    }

    BitcoinExchange btc(argv[1], argv[2]);
    return (0);
}