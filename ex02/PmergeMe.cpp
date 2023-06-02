/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:07:49 by akouame           #+#    #+#             */
/*   Updated: 2023/06/02 01:08:05 by akouame          ###   ########.fr       */
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
    _vec.clear();
    _deq.clear();
    _vec = equal._vec;
    _deq = equal._deq;
    _duration_vec = equal._duration_vec;
    _duration_deq = equal._duration_deq;
    return (*this);
}
//--
void	PmergeMe::display(std::vector<int> &c)
{
	for (size_t i = 0; i < c.size(); i++){
		std::cout << c[i] << " ";
	}
	std::cout << std::endl;
}

long long current_timestamp()
{
    timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000LL + tv.tv_usec;
}

//--
void    PmergeMe::sort_insert_vec(std::vector<int> &c)
{
    int tmp;
    int j;
    
    for (size_t i = 1; i < c.size(); i++)
    {
        tmp = c[i];
        j = i - 1;
        while (j >= 0 && c[j] > tmp)
        {
            c[j + 1] = c[j];
            j--;
        }
        c[j + 1] = tmp;
    }
}
//---
void    PmergeMe::sort_insert_deq(std::deque<int> &c)
{
    int tmp;
    int j;
    
    for (size_t i = 1; i < c.size(); i++)
    {
        tmp = c[i];
        j = i - 1;
        while (j >= 0 && c[j] > tmp)
        {
            c[j + 1] = c[j];
            j--;
        }
        c[j + 1] = tmp;
    }
}

//--

void    PmergeMe::sort_merge_vec(std::vector<int> &c, size_t start, size_t end, size_t mid)
{
    std::vector<int>    it;
    size_t i = start;
    size_t j = mid + 1;
    
    while (i <= mid && j <= end)
    {
        if (c[i] <= c[j])
            it.push_back(c[i++]);
        else
            it.push_back(c[j++]);
    }
    while (i <= mid)
        it.push_back(c[i++]);
    while (j <= end)
        it.push_back(c[j++]);
   for (size_t k = start; k <= end; k++)
        c[k] = it[k - start];
}

void    PmergeMe::sorting_vec(std::vector<int> &c, size_t start, size_t end)
{
    if (c.size() <= 100)
    {
        sort_insert_vec(c);
        return ;
    }
    if (end > start)
    {
        int mid = start + (end - start) / 2;
        sorting_vec(c, start, mid);
        sorting_vec(c, mid + 1, end);
        sort_merge_vec(c, start, end, mid);
    }
}
//--
void    PmergeMe::sort_merge_deq(std::deque<int> &c, size_t start, size_t end, size_t mid)
{
    std::deque<int>    it;
    size_t i = start;
    size_t j = mid + 1;
    
    while (i <= mid && j <= end)
    {
        if (c[i] <= c[j])
            it.push_back(c[i++]);
        else
            it.push_back(c[j++]);
    }
    while (i <= mid)
        it.push_back(c[i++]);
    while (j <= end)
        it.push_back(c[j++]);
   for (size_t k = start; k <= end; k++)
        c[k] = it[k - start];
}

void    PmergeMe::sorting_deq(std::deque<int> &c, size_t start, size_t end)
{
    if (c.size() <= 100)
    {
        sort_insert_deq(c);
        return ;
    }
    if (end > start)
    {
        int mid = start + (end - start) / 2;
        sorting_deq(c, start, mid);
        sorting_deq(c, mid + 1, end);
        sort_merge_deq(c, start, end, mid);
    }
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
		_vec.push_back(atoi(av[i]));
		_deq.push_back(atoi(av[i]));
		i++;
	}
	std::cout << "Before:\t";
	display(_vec);
	std::clock_t start_vc = std::clock();
    sorting_vec(_vec, 0, (_vec.size() - 1));
    std::clock_t end_vc = std::clock();
    _duration_vec = (end_vc - start_vc) / (double)CLOCKS_PER_SEC;
    std::cout << "After:\t";
    display(_vec);
    std::cout << "Time to process a range of 5 elements with std::vector :    " << _duration_vec << " us" << std::endl;
    std::clock_t    start_dq = std::clock();
    sorting_deq(_deq, 0, (_deq.size() - 1));
    std::clock_t    end_dq = std::clock();
    _duration_deq = ((end_dq - start_dq) / (double)CLOCKS_PER_SEC) * 1000000;
    std::cout << "Time to process a range of 5 elements with std::deque :    " << _duration_deq << " us" << std::endl;
}