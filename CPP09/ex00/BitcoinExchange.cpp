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
    std::ifstream file(filename.c_str());
    std::string line;
    if (!file)
    {
        std::cerr << "Error: could not open file: " << this->filename << std::endl;
        exit(1);
    }
    
    // Check for valid header in the first non-empty line
    bool header_checked = false;
    
    while (std::getline(file, line))
    {
        // Skip empty lines at the beginning when looking for header
        if (!header_checked && line.empty())
            continue;
            
        // Check header only once from the first non-empty line
        if (!header_checked)
        {
            header_checked = true;
            if (line != "date | value")
            {
                std::cerr << "Error: header should be date | value" << std::endl;
                // Process this line as data if it's not empty
                if (line.empty())
                    continue;
            }
            else
            {
                // If proper header found, get next line and continue
                continue;
            }
        }
        
        // From here on, process all lines as data
        // Split the line by '|' and check proper format
        size_t pos = line.find('|');
        if (pos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Extract date and value strings, trimming whitespace
        std::string date = line.substr(0, pos);
        std::string valueStr = line.substr(pos + 1);
        
        // Trim trailing whitespace from date
        date.erase(date.find_last_not_of(" \t\r\n") + 1);
        // Trim leading and trailing whitespace from value
        valueStr.erase(0, valueStr.find_first_not_of(" \t\r\n"));
        valueStr.erase(valueStr.find_last_not_of(" \t\r\n") + 1);

        // Check for empty parts or additional pipe symbols
        if (date.empty() || valueStr.empty() || valueStr.find('|') != std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Validate date format
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }

        // Convert value to double and validate
        char* endptr;
        double value = strtod(valueStr.c_str(), &endptr);
        
        // Check if the conversion was successful and used the entire string
        if (*endptr != '\0')
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Check value range
        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        // Find the closest exchange rate
        std::map<std::string, double>::iterator it = map.lower_bound(date);
        if (it == map.end() || it->first != date)
        {
            if (it != map.begin())
            {
                --it;
            }
            else
            {
                std::cerr << "Error: no available rate for " << date << std::endl;
                continue;
            }
        }
        
        // Output the result
        std::cout << date << " => " << value << " = " << (value * it->second) << std::endl;
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
