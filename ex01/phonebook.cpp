/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:22:02 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/17 17:17:15 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

void Contact::set_first_name(const std::string &value)
{
    first_name = value;
}
const std::string& Contact::get_first_name() const
{
    return(first_name);
}
void Contact::set_last_name(const std::string &value)
{
    last_name = value;
}
const std::string& Contact::get_last_name() const
{
    return(last_name);
}
void Contact::set_phone_nbr(const std::string &value)
{
    phone_number = value;
}
const std::string& Contact::get_phone_nbr() const
{
    return(phone_number);
}
void Contact::set_dark_sec(const std::string &value)
{
    darkest_sec = value;
}
const std::string& Contact::get_dark_sec() const
{
    return(darkest_sec);
}