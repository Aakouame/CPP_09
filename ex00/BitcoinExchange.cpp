/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:08:07 by akouame           #+#    #+#             */
/*   Updated: 2023/05/27 14:32:19 by akouame          ###   ########.fr       */
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
    _data.clear();
    _database.clear();
    _data = equal._data;
    _database = equal._database;
    return (*this);
}
//--

int	checkDate(std::string	str)
{
	for (int i = 0; i < 4; i++){
		if (str[i] < '0' || str[i] > '9')
			return (1);
	}
	if (str[4] != '-')
		return (2);
	for (int i = 5; i < 7; i++){
		if (str[i] < '0' || str[i] > '9')
			return (3);
	}
	if (str[7] != '-')
		return (4);
	for (int i= 8; i < 10; i++){
		if (str[i] < '0' || str[i] > '9')
			return (5);
	}
}

void    Bitcoinexchange::parse_map(std::string fileName, int i){
    std::ifstream   file(fileName);
    std::map<std::string, float>    *tmp;
    
    if (i == 0)
        tmp = &_database;
    else
        tmp = &_data;
    if (file.is_open())
    {
        std::string line;
        std::string date;
        std::string	value;
		
        while (std::getline(file, line)){
			if (i == 1)
			{
				date = line.substr(0, line.find(' '));
				checkDate(date);
				if (line.substr(10, 12) != " | ")
					throw std::runtime_error ("should be separated by \" | \"");
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
    
}