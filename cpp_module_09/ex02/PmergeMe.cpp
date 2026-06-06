#include "PmergeMe.hpp"

PmergeMe::PmergeMe():has_leftover(false),leftover(-1)
{

}
PmergeMe::~PmergeMe()
{

}
template<typename Container>
void PmergeMe::print(const Container &c)
{
     for(size_t i = 0; i < c.size();i++)
    {
        std::cout<< c[i] << " ";
    }
    std::cout << std::endl;
}

std::deque<pair> PmergeMe::make_pairs_deq(std::deque<int> d)
{
    pair p;
    std::deque<pair> pairs;

    size_t i = 0;
    while((i + 1)< d.size())
    {
        int a = d[i];
        int b = d[i+1];
        if(a > b)
        {
            p.big = a;
            p.small = b;
        }
        else
        {
            p.big = b;
            p.small = a;
        }
        pairs.push_back(p);
        i+=2;
    }
     if (i < vec.size())
    {
        leftover = vec[i];
        has_leftover = true;
    }
    return(pairs);
   
}
std::vector<pair> PmergeMe::make_pairs_vec(std::vector<int> d)
{
    pair p;
    std::vector<pair> pairs;

    size_t i = 0;
    while((i + 1)< d.size())
    {
        int a = d[i];
        int b = d[i+1];
        if(a > b)
        {
            p.big = a;
            p.small = b;
        }
        else
        {
            p.big = b;
            p.small = a;
        }
        pairs.push_back(p);
        i+=2;
    }
     if (i < vec.size())
    {
        leftover = vec[i];
        has_leftover = true;
    }
    return(pairs);
   
}
std::deque<int> PmergeMe::fordJohnsonDeque(std::deque<int> d)
{
    std::deque<pair> pairs = make_pairs_deq(d);
    return(d);
} 
std::vector<int> PmergeMe::fordJohnsonVector(std::vector<int> v)
{
    std::vector<pair> pairs = make_pairs_vec(v);
    return(v);
}
bool PmergeMe::parse_input(std::string str)
{
    if (str.empty())
     return false;
    for(size_t i = 0; i < str.size(); i++)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return(false);
    }
    return(true);
}
bool PmergeMe::setup(char **argv, int argc)
{
    for(int i = 1; i < argc; i++)
    {
        if(!parse_input(argv[i]))
        {
            std::cerr << "ERROR \n";
            return(false); 
        }
        char *end;
        long nbr = strtol(argv[i], &end, 10);
        if(*end !='\0' ||nbr >INT_MAX )
        {
            std::cerr << "ERROR \n";
            return(false); 
        }
        vec.push_back(static_cast<int>(nbr));
        deq.push_back(static_cast<int>(nbr));
    }
    return(true);
}
 void PmergeMe::run(char **argv, int argc)
 {
    if(!setup(argv,argc))
        return;
    std::cout << "Before: ";
    print(vec);
    clock_t start1 = clock();

    std::vector<int> sorted_vec = fordJohnsonVector(vec);

    clock_t end1 = clock();

    clock_t start2 = clock();

   std::deque<int> sorted_deq = fordJohnsonDeque(deq);

    clock_t end2 = clock();

    //std::cout << "After: ";
    //print(sorted_vec);

    double time_vec = (double)(end1 - start1)/ CLOCKS_PER_SEC;
    double time_deq = (double)(end2 - start2)/ CLOCKS_PER_SEC;

    std::cout << "Time vector: " << time_vec << " us\n";
    std::cout << "Time deque : " << time_deq << " us\n";
 }