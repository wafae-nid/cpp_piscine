/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:54:24 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/24 15:44:04 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <cctype>
#include <cstdlib>
#include <iostream>
#include <string>

class Contact
{
    private :
        std::string first_name;
        std::string last_name;
        std::string phone_number;
        std::string nickname;
        std::string darkest_secret;
        int     imprintable(std::string str);
    public :
        void set_first_name();
        void set_last_name();
        void set_nickname();
        void set_phone_number();
        void set_darkest_secret();
        const std::string get_first_name()const;
        const std::string get_last_name()const;
        const std::string get_nickname()const;
        const std::string get_phone_number()const;
        const std::string get_darkest_secret()const;
};
 
#endif