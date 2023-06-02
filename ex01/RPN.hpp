/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:58:21 by akouame           #+#    #+#             */
/*   Updated: 2023/06/01 02:51:40 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <cctype>
#include <string>

class   Rpn
{
	int _op;
	int _nb;
	std::stack<int>	_data;
	public:
		Rpn();
		~Rpn();
		Rpn(Rpn const &cpy);
		//--
		Rpn	&operator =(Rpn const &equal);
		//--
		void	parse(char	*av);
		void	calculate(char op);
};

#endif
