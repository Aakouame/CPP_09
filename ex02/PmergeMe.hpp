/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:07:46 by akouame           #+#    #+#             */
/*   Updated: 2023/05/31 17:07:14 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>

class   PmergeMe
{
    std::vector<int>	_first_containr;
    std::deque<int>		_second_container;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &cpy);
		//-
		PmergeMe	&operator=(PmergeMe const &equal);
		void	parse(char **av);
		void	display();
		void	sorting_first();
		void	sorting_second();
		void	sort_insertion();
		void	sort_merge();
};

#endif