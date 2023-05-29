/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:08:07 by akouame           #+#    #+#             */
/*   Updated: 2023/05/29 09:37:52 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Bitcoinexchange::Bitcoinexchange(){
    // std::cout << "Bitcoinexchange, default constructor called !" << std::endl;
}

Bitcoinexchange::~Bitcoinexchange(){
    // std::cout << "Bitcoinexchange, default destructor called !" << std::endl;
}

Bitcoinexchange::Bitcoinexchange(Bitcoinexchange const &cpy){
    // std::cout << "Bitcoinexchange, copy constructor called !" << std::endl;
    *this = cpy;
}

Bitcoinexchange::Bitcoinexchange(char *inFile):_inputFile(inFile){
    // std::cout << "Bitcoinexchange, parameter constructor called !" << std::endl;
}
//--
Bitcoinexchange &Bitcoinexchange::operator=(Bitcoinexchange const &equal){
    // std::cout << "Bitcoinexchange, assignement operator '=' called !" << std::endl;
    _inputFile = equal._inputFile;
    _database.clear();
    _database = equal._database;
    return (*this);
}
//--
int	checkDate(std::string	date)
{
	for (int i = 0; i < 4; i++){
		if (date[i] < '0' || date[i] > '9')
			return (1);
	}
	if (date[4] != '-')
		return (2);
	for (int i = 5; i < 7; i++){
		if (date[i] < '0' || date[i] > '9')
			return (3);
	}
	int tmp = atoi(date.substr(5, 6).c_str());
	if (tmp > 12)
		return (4);
	if (date[7] != '-')
		return (4);
	for (int i= 8; i < 10; i++){
		if (date[i] < '0' || date[i] > '9')
			return (5);
	}
	tmp = atoi(date.substr(8, 9).c_str());
	if (tmp > 30)
		return (6);
	return (0);
}

int	checkValue(std::string	value)
{
	int	counter = 0;
	int	nb;
	if (value[0] == '.')
		return (1);
	for (size_t i = 0; i < value.size(); i++){
		if (value[i] < '0' || value[i] > '9' )
		{
			if (value[i] == '.')
				counter++;
			else
				return (2);
		}
	}
	if (counter > 1)
		return (3);
	nb = atof(value.c_str());
	if (nb < 0)
		return (4);
	if (nb > 1000)
		return (5);
	return(0);
}
//--
std::string	cpyStr(std::string str, int start, int end)
{
	std::string	tmp;

	while (start != end)
	{
		tmp += str[start];
		start++;
	}
	tmp += str[end];
	return (str);
}
//--
void    Bitcoinexchange::parse_map(std::string fileName, int i){
    std::ifstream   file(fileName);

    if (file.is_open())
    {
        std::string line;
        std::string date;
        std::string	value;
		
		std::getline(file, line);
		if (i == 1)
			if (line != "date | value")
				throw std::runtime_error("Bad input: check if the first line == \"date | value\"");
        while (std::getline(file, line)){
			if (i == 1)
			{
				date = line.substr(0, line.find(' '));
				
				// std::cout << "date = " << date << std::endl;
				if (line.substr(10, 3) != " | ")
				{
					std::cout << "Error: bad input => should be separated by \" | \"" << std::endl;
					continue;
				}
				if (checkDate(date)){
					std::cout << "Error: bad input => " << date << std::endl;
					continue ;
				}
				value = line.substr(13, line.size() - 1);
				// std::cout << "Value = " << value << std::endl;
				if (checkValue(value))
				{
					if (checkValue(value) == 4)
						std::cout << "Error: not a positive number." << std::endl;
					else if (checkValue(value) == 5)
						std::cout << "Error: too large a number." << std::endl;
					else
						std::cout << "Bad input: check the value !" << std::endl;
				}
				if (!checkDate(date) && !checkValue(value))
				{
					std::map<std::string, float>::iterator	it = _database.find(date);
					if (it != _database.end())
						std::cout << date << " => " << value << " = " << (atof(value.c_str()) * it->second);
					std::cout << std::endl;
				}
			}
			else
			{
				date = line.substr(0, line.find(',') - 1);
				value = line.substr(line.find(',') + 1);
				_database.insert(std::make_pair(date,atof(value.c_str())));
			}
        }
        file.close();
    }
    else
        throw std::runtime_error("Cannot open the file !");
}

void    Bitcoinexchange::parse(const char *av)
{
    _inputFile = av;
    
	parse_map("data.csv", 0);
	parse_map(_inputFile, 1);
	std::map<std::string, float>::iterator it;
    // for (it = _database.begin(); it != _database.end(); ++it) {
    //     std::cout << it->first << ": " << it->second << std::endl;
    // }
}