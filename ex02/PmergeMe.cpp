/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:07:49 by akouame           #+#    #+#             */
/*   Updated: 2023/05/31 19:51:26 by akouame          ###   ########.fr       */
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
void	PmergeMe::display()
{
	for (size_t i = 0; i < _vec.size(); i++){
		std::cout << _vec[i] << " ";
	}
	std::cout << std::endl;
}
//--
void    PmergeMe::sort_insert_vec()
{
    int tmp;
    int j;
    
    for (size_t i = 1; i < _vec.size(); i++)
    {
        tmp = _vec[i];
        j = i - 1;
        while (j >= 0 && _vec[j] > tmp)
        {
            _vec[j + 1] = _vec[j];
            j--;
        }
        _vec[j + 1] = tmp;
    }
}

void    PmergeMe::merge_vec(int l, int mid, int r)
{
    int l_size = mid - l + 1;
    int r_size = r - mid;
    int i = -1;
    int j = 0;

    std::vector<int>    it_l;
    std::vector<int>    it_r;
    
    while (++i < l_size)
        it_l[i] = _vec[l+i];
    i = 0;
    while (i < r_size)
        it_r[i] = _vec[mid+i+1];
    i = 0;
    _vec.clear();
    while (i < l_size && j < r_size)
    {
        if (it_l[i] <= it_r[j])
            _vec.push_back(it_l[i++]);
        else
            _vec.push_back(it_r[j++]);
    }
    while (i < l_size)
        _vec.push_back(it_l[i++]);
    while (j < r_size)
        _vec.push_back(it_r[j++]);
}

void	PmergeMe::sort_merge_vec(int l, int r)
{
    int mid;

    mid = l + (r - l) / 2;
    sort_merge_vec(l, mid);
    sort_merge_vec((mid + 1), r);
    merge_vec(l, mid, r);
}

//--
void    PmergeMe::sorting_vec()
{
    if (_vec.size() <= 10)
        sort_insert_vec();
    else
        sort_merge_vec(0, _vec.size() - 1);
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
		_vec.push_back(atoi(av[i]));
		_deq.push_back(atoi(av[i]));
		i++;
	}
	std::cout << "Before:\t";
	display();
	std::clock_t start = std::clock();
    sorting_vec();
    std::clock_t end = std::clock();
    _duration_vec = (start - end) / (double)CLOCKS_PER_SEC;
    std::cout << "After:\t";
    display();
}