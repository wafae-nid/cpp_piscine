/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:54:24 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/23 16:58:57 by wnid-hsa         ###   ########.fr       */
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
        std::string contact[5];
        int     imprintable(std::string str);
    public :
        void set_contact();
        const std::string* get_contact() const;
};
 
#endif