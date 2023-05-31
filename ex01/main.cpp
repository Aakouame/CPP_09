/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akouame <akouame@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 11:58:13 by akouame           #+#    #+#             */
/*   Updated: 2023/05/30 12:30:34 by akouame          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        try{
            Rpn stck;
            
            stck.parse(av[1]);
        }
        catch (std::exception &e){
            std::cerr << e.what() << std::endl;
        }
    }
    else
        std::cerr << "Invalide argument, this is an example to run this program: {./RPN \"7 7 * 7 -\"}" << std::endl;
    return (0);
}