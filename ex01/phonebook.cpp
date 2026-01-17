/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:22:02 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/17 13:57:50 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class contact
{
    private :
        std::string first_name;
        std::string last_name;
        std::string phone_number;
        std::string darkest_sec;
    public :
        void set_first_name(std::string value)
        {
            first_name = value;
        }
        void set_last_name(std::string value)
        {
            last_name = value;
        }
        void set_phone_nbr(std::string value)
        {
            phone_number = value;
        }
        void set_dark_sec(std::string value)
        {
            darkest_sec = value;
        }
};