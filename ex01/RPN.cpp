/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:58:18 by akouame           #+#    #+#             */
/*   Updated: 2023/05/31 09:03:42 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

Rpn::Rpn(): _op(0), _nb(0){
    // std::cout << "Rpn, default constructor called !" << std::endl;
}

Rpn::~Rpn(){
    // std::cout << "Rpn, default destructor called !" << std::endl;
}

Rpn::Rpn(Rpn const &cpy): _op(cpy._op), _nb(cpy._nb){
    // std::cout << "Rpn, copy constructor called !" << std::endl;
}
//--
Rpn &Rpn::operator=(Rpn const &equal){
    // std::cout << "Rpn, assignement operator '=' called !" << std::endl;
	_op = equal._op;
	_nb = equal._nb;
    while(!_data.empty())
        _data.pop();
    _data = equal._data;
    return (*this);
}
//--
int	found(char *tab, int x, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (x == tab[i])
			return (1);
	}
	return (0);
}
//--
void	Rpn::parse(char	*av)
{
	if (!av)
		throw std::runtime_error("Error: empty input");
	int i = -1;
	while (av[++i] != '\0')
	{
		if (av[i] == ' ')
			continue;
		else if (av[i] >= '0' && av[i] <= '9')
		{
			_data.push(av[i] - '0');
			_nb++;
		}
		else
			calculate(av[i]);
	}
	if (_nb - _op != 1)
		throw std::runtime_error("Error: invalid argument !");
	std::cout << _data.top() << std::endl;
}

void	Rpn::calculate(char op)
{
	int first;
	int second;
	char	arr[4] = {'+', '-', '*', '/'};

	if (_data.size() > 1)
	{
		if (found(arr, op, 4))
		{
			second = _data.top();
			_data.pop();
			first = _data.top();
			_data.pop();
			_op++;	
			if (op == '+')
				_data.push(first + second);
			else if (op == '-')
				_data.push(first - second);
			else if (op == '*')
				_data.push(first * second);
			else if (op == '/')
			{
				if (second == 0)
					throw std::runtime_error("Error: You can't divide on 0 !");
				_data.push(first / second);
			}
		}
		else
			throw std::runtime_error("Error: invalid argument !!");
	}
	else
		throw std::runtime_error("Error: Bad input");
}