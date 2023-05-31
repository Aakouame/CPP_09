/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 11:27:21 by akouame           #+#    #+#             */
/*   Updated: 2023/05/31 18:36:11 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main (int ac, char **av)
{
    if (ac > 1)
    {
        try
        {
            PmergeMe	pmerge;

			pmerge.parse(av);
        }
        catch(const std::exception& e)
        {
            std::cout << e.what() << std::endl;
        }
        
    }
    else
        std::cout << "Error: You should have at least one argument !" << std::endl;
}