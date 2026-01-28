/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnid-hsa <wnid-hsa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 21:55:52 by wnid-hsa          #+#    #+#             */
/*   Updated: 2026/01/28 17:40:13 by wnid-hsa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

void replace(std::string str, size_t pos, std::ofstream& out_file, std::string s2, std::string s1)
{
     while(pos != std::string::npos)
    {
        out_file << str.substr(0,pos);
        out_file << s2 ;
        str = str.substr((pos+s1.length()));
        pos = str.find(s1);
    }
    out_file << str << "\n";
}
std::string replace_name(char *s1)
{
    std::string s1_;
    std::string ext = ".replace";
    s1_= s1;
    return(s1_+ext);
}
int main(int argc, char **argv)
{
    std::string in_line;
    std::string str;
    std::string str2;
    size_t pos;
    
    if(argc != 4 || argv[1][0] == '\0' ||argv[2][0] == '\0')
    {
        std::cerr << "invalid number of parameters \n";
        return(1);
    }
    str = argv[1];
    std::ifstream in_File(str);
    if(!in_File)
    {
        std::cerr << "failed to open the file " << str << "\n";
        return(1);
    }
    std::ofstream out_File(replace_name(argv[1]));
    if(!out_File)
    {
        std::cerr << "failed to open the file " << replace_name(argv[1]) << "\n";
        return(1);
    }
    while(std::getline(in_File, in_line))
    {
        str = argv[2];
        pos = 0;
        str2 = argv[3];
        pos = in_line.find(str);
        if (pos == std::string::npos)
            out_File << in_line << "\n";
        else
        {
            str2 = argv[3];
            replace(in_line, pos, out_File,str2, str);
        }
    }
}