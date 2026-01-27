/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:28:43 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/27 22:10:23 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP


#include <iostream>

class Harl
{
    private:
        void debug( void );
        void info( void );
        void warning( void ); 
        void error( void );
        
    public:
        void complain(std::string level);
};

#endif