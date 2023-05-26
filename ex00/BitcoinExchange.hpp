/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:08:11 by akouame           #+#    #+#             */
/*   Updated: 2023/05/26 18:44:38 by akouame          ###   ########.fr       */
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
};


#endif