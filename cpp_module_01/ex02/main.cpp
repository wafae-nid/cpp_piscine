/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 11:44:20 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/26 12:28:26 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string* stringPTR = &str;
    std::string& stringREF = str;
    
    std::cout << &str << "\n";
    std::cout << &stringPTR << "\n";
    std::cout << &stringREF << "\n";
    
    std::cout << str << "\n";
    std::cout << *stringPTR << "\n";
    std::cout << stringREF << "\n";
    
    
}