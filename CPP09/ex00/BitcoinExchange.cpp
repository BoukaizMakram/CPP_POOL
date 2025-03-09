#include "BitcoinExchange.hpp"

bool isValidDate(const std::string& date)
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') return false;
    for (int i = 0; i < 10; ++i)
        if ((i != 4 && i != 7) && !std::isdigit(date[i])) return false;

    int year, month, day;
    std::stringstream ss(date);
    char dash1, dash2;
    ss >> year >> dash1 >> month >> dash2 >> day;

    if (dash1 != '-' || dash2 != '-') return false;
    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    return (true);
}

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(std::string database, std::string filename) 
{
    int first_line = 0;
    this->filename = filename;
    this->database = database;
    std::string line;
    std::ifstream file(database.c_str());

    if (!file)
    {
        std::cerr << "Error: could not open database file." << std::endl;
        exit(1);
    }
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, valueStr;
        double      value;
        first_line++;
        if (!std::getline(ss, date, ',') || !std::getline(ss, valueStr) ||((date == "date") && (first_line == 1)))
            continue;
        else if (first_line == 1 && date != "date") {
             std::cerr << "Error: First line detected, header doesn't contain the following format : date,exchange_rate in data.csv" << std::endl;
             continue;
        }
        if (!isValidDate(date) && date != "date")
        {
            std::cerr << date << " is invalid, please fix this date to be YYYY-MM-DD inside " << database << " file!" << std::endl;
            continue;
        }
        std::stringstream valueStream(valueStr);
        valueStream >> value;
        this->map[date] = value;
    }
    processInput();
};

void BitcoinExchange::processInput()
{
    std::ifstream   file(filename.c_str());
    std::string     line;

    if (!file)
    {
        std::cerr << "Error: could not open file: " << this->filename << std::endl;
        exit(1);
    }
    int first_line = 0; // increment this after reading a line, to skip date | value expression in first line.
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, valueStr;
        double      value;

        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        first_line++;
        if ((date == "date ") && (valueStr == " value") && first_line == 1)
        {
            continue ;
        }
        else if (first_line == 1)
        {
            std::cerr << "Error: header should be date | value" << std::endl;
            continue;
        }
        date.erase(date.find_last_not_of(" ") + 1);
        std::stringstream valueStream(valueStr);
        valueStream >> value;
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        if (value < 0) 
        {
            std::cerr << "Error: '" << value << "' is not a positive number.\n";
            continue;
        }

        if (value > 1000) 
        {
            std::cerr << "Error: '" << value << "' is a too large a number.\n";
            continue;
        }
        std::map<std::string, double>::iterator it = map.lower_bound(date);
        if (it == map.end() || it->first != date) 
        {
            if (it != map.begin()) 
            {
                --it;
            } 
            else
            {
                std::cerr << "Error: no available rate for " << date << "\n";
                continue;
            }
        }
        std::cout << date << " => " << value << " = " << (value * it->second) << "\n";
    }
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) 
{
    *this = other;
};


BitcoinExchange BitcoinExchange::operator=(const BitcoinExchange& other) 
{
    if (this != &other)
    {
        this->database = other.database;
        this->filename = other.filename;
    }
    return (*this);
};


void BitcoinExchange::loadExchangeRates()
{

}

BitcoinExchange::~BitcoinExchange() {};
