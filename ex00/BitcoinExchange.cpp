/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:08:07 by akouame           #+#    #+#             */
/*   Updated: 2023/05/26 18:45:40 by akouame          ###   ########.fr       */
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
    _data = equal._data;
    return (*this);
}
//--
void    Bitcoinexchange::parse(const char *av)
{
    _inputFile = av;
    std::ifstream   file(_inputFile);
    
    if (file.is_open())
    {
        std::string line;
        while (std::getline(file, line));
        file.close();
    }
    else
        throw std::runtime_error("Cannot open the file !");
}