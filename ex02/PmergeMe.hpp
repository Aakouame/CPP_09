/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:07:46 by akouame           #+#    #+#             */
/*   Updated: 2023/05/31 19:05:20 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <ctime>
#include <cstring>

class   PmergeMe
{
    std::vector<int>	_vec;
	double				_duration_vec;
    std::deque<int>		_deq;
	double				_duration_deq;
	public:
		PmergeMe();
		~PmergeMe();
		PmergeMe(PmergeMe const &cpy);
		//-
		PmergeMe	&operator=(PmergeMe const &equal);
		void	parse(char **av);
		void	display();
		void	sorting_vec();
		void	sorting_deq();
		void	sort_insert_vec();
		void	sort_insert_deq();
		void	sort_merge_vec(int l, int r);
		void	merge_vec(int l, int mid, int r);
};

#endif