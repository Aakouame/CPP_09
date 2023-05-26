/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 08:08:11 by akouame           #+#    #+#             */
/*   Updated: 2023/05/26 10:17:07 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>


class   Bitcoinexchange
{
	std::string	_inputFile;
	
	public:
		Bitcoinexchange();
		Bitcoinexchange(Bitcoinexchange const &copy);
		~Bitcoinexchange();
		//--
		Bitcoinexchange	&operator=(Bitcoinexchange const &equal);
		//--
		void	parse();
};


#endif