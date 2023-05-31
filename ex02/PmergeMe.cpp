/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:07:49 by akouame           #+#    #+#             */
/*   Updated: 2023/05/31 17:09:22 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
    // std::cout << "PmergeMe, default constructor called !" << std::endl;
}

PmergeMe::~PmergeMe(){
    // std::cout << "PmergeMe, default destructor called !" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const &cpy){
    // std::cout << "PmergeMe, copy constructor called !" << std::endl;
    *this = cpy;
}
//--
PmergeMe    &PmergeMe::operator=(PmergeMe const &equal){
    // std::cout << "PmergeMe, assignement operator '=' called !" << std::endl;
    _first_containr.clear();
    _second_container.clear();
    _first_containr = equal._first_containr;
    _second_container = equal._second_container;
    return (*this);
}
//--
void	PmergeMe::display()
{
	for (size_t i = 0; i < _first_containr.size(); i++){
		std::cout << _first_containr[i] << " ";
	}
	std::cout << std::endl;
}
//--
void    PmergeMe::sort_insertion()
{
    
}

void    PmergeMe::sort_merge()
{
    
}
//--
void    PmergeMe::sorting_first()
{
    if (_first_containr.size() > 10)
	{
		sort_merge();
	}
    else
        sort_insertion();
	
}
//--
void    PmergeMe::sorting_second()
{
    
}
//--
void    PmergeMe::parse(char **av)
{
    int i = 1;
    int j;
    long long	n;
	
    while (av[i])
    {
        j = 0;
        while (av[i][j])
        {
			// std::cout << "av[" << i << "][" << j << "] = " << av[i][j] << std::endl;
			if (!isdigit(av[i][j]))
				throw std::runtime_error("Error: Bad input !");
			j++;
        }
        i++;
    }
	i = 1;
	while (av[i])
	{
		n = atoi(av[i]);
		if (n < 0 || n > 2147483647 || (strlen(av[i]) > 10))
			throw std::runtime_error("Error : To high !");
		_first_containr.push_back(atoi(av[i]));
		_second_container.push_back(atoi(av[i]));
		i++;
	}
	std::cout << "Before:\t";
	display();
	// sorting();
}