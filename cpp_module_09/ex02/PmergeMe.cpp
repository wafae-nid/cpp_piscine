#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
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

template <typename Container>
void PmergeMe::sort_pairs(Container& c, size_t block_size)
{
    size_t pair_size = block_size * 2;

    if (pair_size > c.size())
        return;

    for (size_t i = 0; i + pair_size <= c.size(); i += pair_size)
    {
        size_t left_max  = i + block_size - 1;
        size_t right_max = i + pair_size - 1;

        if (c[left_max] > c[right_max])
        {
            for (size_t j = 0; j < block_size; j++)
                std::swap(c[i + j], c[i + block_size + j]);
        }
    }

    sort_pairs(c, block_size * 2);
}


std::deque<int> PmergeMe::fordJohnsonDeque(std::deque<int> d)
{
    sort_pairs(d, 1);
    print(d);
    std::cout << "\n";
    return(d);
} 
void PmergeMe::build_chains(std::vector<int> v, std::vector<int> & main, std::vector<int>& pend)
{
    
    if (v.size() == 0)
        return;
        
    main.push_back(v[0]);

    if (v.size() == 1)
        return;

    main.push_back(v[1]);
    
    for(size_t i =2; i< v.size(); i++)
    {
        if(i %2 != 0)
            main.push_back(v[i]);
        else
            pend.push_back(v[i]);
        
    }
}
std::vector<int> PmergeMe::fordJohnsonVector(std::vector<int> v)
{
    std::vector<int> main_chain;
    std::vector<int> pend;

    sort_pairs(v, 1);
    print(v);
    std::cout << "\n";
    build_chains(v, main_chain, pend);
    std::cout << "*********\n";
    print(main_chain);
    std::cout << "\n";
     std::cout << "*********\n";
    print(pend);
    std::cout << "\n";
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