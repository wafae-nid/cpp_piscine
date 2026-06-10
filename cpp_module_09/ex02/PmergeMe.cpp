#include "PmergeMe.hpp"


template<typename Container>
struct InfoContainerFor;

template<>
struct InfoContainerFor<std::vector<int> >
{
    typedef std::vector<PendInfo> type;
};

template<>
struct InfoContainerFor<std::deque<int> >
{
    typedef std::deque<PendInfo> type;
};
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

    Container main_chain;
    Container pend;
    typename InfoContainerFor<Container>::type pend_cont;
    build_chains(c, main_chain, pend, pend_cont,block_size);
    Container jacob ;
    Jacobsthal_numbers(jacob,pend.size(), block_size);
    Container order;
    build_insertion_order(jacob,order);
   
}
template<typename Container>
void PmergeMe::build_insertion_order(const Container& jacob,
                           Container& order)
{
    size_t prev = 1;

    for (size_t i = 0; i < jacob.size(); i++)
    {
        size_t current = jacob[i];

        for (size_t j = current; j > prev; --j)
            order.push_back(static_cast<int>(j));

        prev = current;
    }

}
template<typename Container>
void PmergeMe::Jacobsthal_numbers(Container& c,
                                  size_t size,
                                  size_t block_size)
{
    c.clear();

    size_t pend_blocks = size / block_size;

    if (pend_blocks == 0)
        return;

    size_t max_label = pend_blocks + 1;

    size_t j0 = 1;
    size_t j1 = 3;

    while (j1 <= max_label)
    {
        c.push_back(static_cast<int>(j1));

        size_t next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;
    }

    if (c.empty() || static_cast<size_t>(c.back()) != max_label)
        c.push_back(static_cast<int>(max_label));
}

std::deque<int> PmergeMe::fordJohnsonDeque(std::deque<int> d)
{
    std::deque<int> main_chain;
    std::deque<int> pend;

    sort_pairs(d, 1);
    print(d);
    
    return(d);
}
// template<typename Container>
// void PmergeMe::insert_member(int position, Container& main,Container& pend,size_t block_size)
// {
    
// } 
template<typename Container>
void PmergeMe::binary_insertion(const Container& order,Container& main,
                        Container& pend,size_t block_size)
{
    for(size_t i=0; i< order.size();i++)
    {
        insert_member(i, pend,main, block_size);
    }
}

template<typename Container, typename InfoContainer>
void PmergeMe::build_chains(const Container& v,
                            Container& main,
                            Container& pend,
                            InfoContainer& pend_cont,
                            size_t block_size)
{
    main.clear();
    pend.clear();
    pend_cont.clear();

    if (v.empty())
        return;

    size_t pair_size = block_size * 2;
    bool first_pair = true;
    size_t i;

    for (i = 0; i + pair_size <= v.size(); i += pair_size)
    {
        size_t b_start = i;
        size_t a_start = i + block_size;

        if (first_pair)
        {
            for (size_t j = 0; j < block_size; j++)
                main.push_back(v[b_start + j]);

            for (size_t j = 0; j < block_size; j++)
                main.push_back(v[a_start + j]);

            first_pair = false;
        }
        else
        {
            for (size_t j = 0; j < block_size; j++)
                pend.push_back(v[b_start + j]);

            PendInfo pend_;
            pend_.pend = b_start;
            pend_.has_pair = true;
            pend_cont.push_back(pend_);

            for (size_t j = 0; j < block_size; j++)
                main.push_back(v[a_start + j]);
        }
    }

    if (i + block_size <= v.size())
    {
        for (size_t j = 0; j < block_size; j++)
            pend.push_back(v[i + j]);

        PendInfo pend_;
        pend_.pend = i;
        pend_.has_pair = false;
        pend_cont.push_back(pend_);
    }
}
std::vector<int> PmergeMe::fordJohnsonVector(std::vector<int> v)
{
    std::vector<int> main_chain;
    std::vector<int> pend;

    sort_pairs(v, 1);
    print(v);
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