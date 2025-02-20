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
        
        if (!std::getline(ss, date, ',') || !std::getline(ss, valueStr) || date == "date")
            continue;
        if (!isValidDate(date) && date != "date")
        {
            std::cerr << date << " is invalid, please fix this date to be YYYY-MM-DD inside " << database << " file!" << std::endl;
            exit(1);
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
    while (std::getline(file, line))
    {
        std::stringstream ss(line);
        std::string date, valueStr;
        double      value;

        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
            continue;
        if (date == "date ")
            continue ;
        std::stringstream valueStream(valueStr);
        valueStream >> value;
        date.erase(date.find_last_not_of(" ") + 1);
        if (!isValidDate(date))
        {
            std::cerr << date << " is invalid, please fix this date to be YYYY-MM-DD inside " << filename << " file!" << std::endl;
            exit(1);
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
        if (it == map.end() || it->first != date) {
            if (it != map.begin()) {
                --it;
            } else {
                std::cerr << "Error: no available rate for " << date << "\n";
                continue;
            }
        }
        std::cout << date << " found in db: " << it->first << " => " << value << " = " << (value * it->second) << "\n";
    }
    exit(0);
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
