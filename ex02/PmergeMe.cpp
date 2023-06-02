/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:07:49 by akouame           #+#    #+#             */
/*   Updated: 2023/06/02 04:37:24 by akouame          ###   ########.fr       */
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
    for (size_t i = 1; i < c.size(); i++)
    {
        int tmp = c[i];
        int j = i - 1;
        while (j >= 0 && c[j] > tmp)
        {
            c[j + 1] = c[j];
            j--;
        }
        c[j + 1] = tmp;
    }
}

//--

void PmergeMe::sort_merge_vec(std::vector<int>& c, size_t start, size_t end, size_t mid)
{
    int l1,l2;
    
    l1 = mid - start + 1;
    l2 = end - mid;
    int *lft = new int[l1];
    int *rgt = new int[l2];
    
    for (int i = 0; i < l1; i++)
        lft[i] = c[start + i];
    for (int i = 0; i < l2; i++)
        rgt[i] = c[mid + 1 + i];
    int i = 0;
    int j = 0;
    int k = start;
    while(i < l1 && j < l2){
        if (lft[i] <= rgt[j])
            c[k] = lft[i++];
        else
            c[k] = rgt[j++];
        k++;
    }
    while (i < l1)
    {
        c[k] = lft[i++];
        k++;
    }
    while (j < l2)
    {
        c[k] = rgt[j++];
        k++;
    }
    delete []lft;
    delete []rgt;
}

void    PmergeMe::sorting_vec(std::vector<int> &c, size_t start, size_t end)
{
    if (c.size() <= 15)
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
void PmergeMe::sort_merge_deq(std::deque<int>& c, size_t start, size_t end, size_t mid)
{
    
    int l1,l2;
    
    l1 = mid - start + 1;
    l2 = end - mid;
    int *lft = new int[l1];
    int *rgt = new int[l2];
    
    for (int i = 0; i < l1; i++)
        lft[i] = c[start + i];
    for (int i = 0; i < l2; i++)
        rgt[i] = c[mid + 1 + i];
    int i = 0;
    int j = 0;
    int k = start;
    while(i < l1 && j < l2){
        if (lft[i] <= rgt[j])
            c[k] = lft[i++];
        else
            c[k] = rgt[j++];
        k++;
    }
    while (i < l1)
    {
        c[k] = lft[i++];
        k++;
    }
    while (j < l2)
    {
        c[k] = rgt[j++];
        k++;
    }
    delete []lft;
    delete []rgt;
}

void    PmergeMe::sorting_deq(std::deque<int> &c, size_t start, size_t end)
{
    if (c.size() <= 5)
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
	std::vector<int>    _vec;
    std::deque<int>     _deq;
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
	while (av[i])
	{
		n = atoi(av[i]);
		if (n < 0 || n > 2147483647 || (strlen(av[i]) > 10))
			throw std::runtime_error("Error : To high !");
		_vec.push_back(atoi(av[i]));
		i++;
	}
    
	std::cout << "Before:\t";
	display(_vec);
    sorting_vec(_vec, 0, (_vec.size() - 1));
    std::cout << "After:\t";
    display(_vec);
    i = 0;
    _vec.clear();
    
	std::clock_t start_vc = std::clock();
	while (av[i])
		_vec.push_back(atoi(av[i++]));
    sorting_vec(_vec, 0, (_vec.size() - 1));
    std::clock_t end_vc = std::clock();
    _duration_vec = (end_vc - start_vc) / (double)CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of 5 elements with std::vector :    " << _duration_vec << " us" << std::endl;
	i = 0;
    std::clock_t    start_dq = std::clock();
	while (av[i])
		_deq.push_back(atoi(av[i++]));
    sorting_deq(_deq, 0, (_deq.size() - 1));
    std::clock_t    end_dq = std::clock();
    _duration_deq = ((end_dq - start_dq) / (double)CLOCKS_PER_SEC) * 1000000;
    std::cout << "Time to process a range of 5 elements with std::deque :    " << _duration_deq << " us" << std::endl;
}