/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    megaphone.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 10:10:36 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/17 10:30:37 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int i = 1;
char c;
int j;

int main(int argc , char **argv)
{
    if(argc >=2)
    {
        while(i<argc)
        {
            j = 0;
            while(argv[i][j])
            {
                if(argv[i][j]>='a' && argv[i][j]<='z')
                    c = std::toupper(argv[i][j]);
                else
                    c = argv[i][j];
                std::cout << c;
                j++;
            }
            std::cout << ' ';
            i++;
        }
    }
    else
       std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << '\n';
}