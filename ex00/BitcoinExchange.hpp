/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:08:11 by akouame           #+#    #+#             */
/*   Updated: 2023/05/27 13:31:45 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <map>

class   Bitcoinexchange
{
	std::string	_inputFile;
	std::map<std::string, float>	_database;
	std::map<std::string, float>	_data;
	public:
		Bitcoinexchange();
		Bitcoinexchange(char *inFile);
		Bitcoinexchange(Bitcoinexchange const &copy);
		~Bitcoinexchange();
		//--
		Bitcoinexchange	&operator=(Bitcoinexchange const &equal);
		//--
		void	parse(const char *av);
		void	parse_map(std::string fileName, int i);
};


#endif