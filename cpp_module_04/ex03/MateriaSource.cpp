#include "MateriaSource.hpp"


MateriaSource::MateriaSource()
{
    for(int i =0; i<4; i++)
    {
        memory[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
   for(int i = 0 ; i < 4; i++)
   {
        if(copy.memory[i] == NULL)
            memory[i] = NULL;
        else
            memory[i] = copy.memory[i]->clone();
   }   
}
 
MateriaSource& MateriaSource::operator=(const MateriaSource& copy)
{
    if(this != &copy)
    {
        for(int i = 0 ; i < 4; i++)
        {
            if(memory[i])
                delete memory[i];
            if(copy.memory[i] == NULL)
                memory[i] = NULL;
            else
                memory[i] = copy.memory[i]->clone();
        }
    }
    return(*this);
}

MateriaSource::~MateriaSource()
{

    for(int i = 0; i < 4 ; i++)
    {
        if(memory[i])
            delete memory[i];
    }
}


void MateriaSource::learnMateria(AMateria* m)
{
    int i;

    if(!m)
        return;
    i = 0;
    while(i< 4 && memory[i])
    {
        i++;
    }
    if(i < 4)
    {
        memory[i] = m->clone();
    }
    delete m;// so i dont leak m 

}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    int i;

    i = 0;
    while(i< 4)
    {
        if(memory[i] && ((memory[i]->getType()).compare(type) == 0))
            return(memory[i]->clone());
        i++;
    }
    return(0);
}