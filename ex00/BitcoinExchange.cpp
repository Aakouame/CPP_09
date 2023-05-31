/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:08:07 by akouame           #+#    #+#             */
/*   Updated: 2023/05/31 17:11:09 by akouame          ###   ########.fr       */
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
int	found(int *tab, int x, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (x == tab[i])
			return (1);
	}
	return (0);
}
//--
int	checkDate(std::string	date)
{
	for (int i = 0; i < 4; i++){
		if (date[i] < '0' || date[i] > '9')
			return (1);
	}
	int year = atoi(date.substr(0, 4).c_str());
	if (year < 2009)
		return (4);
	if (date[4] != '-')
		return (2);
	for (int i = 5; i < 7; i++){
		if (date[i] < '0' || date[i] > '9')
			return (3);
	}
	int month = atoi(date.substr(5, 7).c_str());
	if (month > 12 || month <= 0)
		return (4);
	if (date[7] != '-')
		return (4);
	for (int i= 8; i < 10; i++){
		if (date[i] < '0' || date[i] > '9')
			return (5);
	}
	int day = atoi(date.substr(8, 9).c_str());
	int arr[] = {1, 3, 5, 7, 8, 10, 12};
	if (found(arr, month, 7))
		if (day > 31 || day <= 0)
			return (6);
	if (month == 2)
	{
		if (year % 4 == 0){
			if (day > 29 || day <= 0)
				return (6);
		}
		else
			if (day > 28 || day <= 0)
				return (6);
	}
	int tab[] = {4, 6, 9, 11};
	if (found(tab, month, 4))
		if (day > 30 || day <= 0)
			return (6);
	return (0);
}

int	checkValue(std::string	value)
{
	int	counter = 0;
	long	nb;
	int	s = 0;
	size_t	j = 0;
	if(value == "")
		return (10);
	if (value[0] == '.')
		return (1);
	if (value[0] == '-')
	{
		s++;
		j++;	
	}
	for (size_t i = j; i < value.size(); i++){
		if (value[i] < '0' || value[i] > '9' )
		{
			if (value[i] == '.' && value[i+1])
				counter++;
			else
				return (2);
		}
	}
	if (counter > 1)
		return (3);
	nb = atof(value.c_str());
	if (s == 1)
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
				if (checkDate(date)){
					std::cout << "Error: bad input => " << date << std::endl;
					continue ;
				}
				if (line.substr(10, 3) != " | ")
				{
					std::cout << "Error: bad input => should be separated by \" | \"" << std::endl;
					continue;
				}
				value = line.substr(13, 5);
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
					if (it == _database.end())
					{
						it = _database.lower_bound(date);
						it--;
					}
					std::cout << date << " => " << value << " = " << (atof(value.c_str()) * it->second);
					std::cout << std::endl;
				}
			}
			else
			{
				date = line.substr(0, line.find(','));
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
}