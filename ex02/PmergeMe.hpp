/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:07:46 by akouame           #+#    #+#             */
/*   Updated: 2023/06/02 00:32:26 by akouame          ###   ########.fr       */
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
	// std::pair<std::vector<int>, std::vector<int> >	split;
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
		//--
		void	parse(char **av);
		void	display(std::vector<int> &c);
		//--
		void	sorting_vec(std::vector<int> &c, size_t start, size_t end);
		void	sort_insert_vec(std::vector<int> &c);
		void	sort_merge_vec(std::vector<int> &c, size_t start, size_t end, size_t mid);
		//--
		void	sorting_deq(std::deque<int> &c, size_t start, size_t end);
		void	sort_insert_deq(std::deque<int> &c);
		void	sort_merge_deq(std::deque<int> &c, size_t start, size_t end, size_t mid);
};

#endif