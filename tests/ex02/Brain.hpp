#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
    private :
        std::string ideas[100];
    public :
        Brain();
        // Brain(const std::string name);
        Brain(const Brain& copy);
        Brain& operator=(const Brain& copy);
        ~Brain(); 

        std::string getidea(int index)const;
        void  setidea(int index, const std::string& str);

};


#endif