#include <iostream>
#include <string.h>
#include <fstream>
#include <map>
#include <sstream>
#include <cstdlib>
#include <iomanip>
#include <string>


class BitcoinExchange
{
	private:
		std::map<std::string, double>	map;
		std::string						database;
		std::string						filename;
	public:
		BitcoinExchange();
		BitcoinExchange(std::string database, std::string filename);
		BitcoinExchange operator=(const BitcoinExchange& other);
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		void processInput();
		void loadExchangeRates();
};