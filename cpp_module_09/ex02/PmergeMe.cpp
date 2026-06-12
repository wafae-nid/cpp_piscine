// #include "PmergeMe.hpp"


// template<typename Container>
// struct InfoContainerFor;

// template<>
// struct InfoContainerFor<std::vector<int> >
// {
//     typedef std::vector<PendInfo> type;
// };

// template<>
// struct InfoContainerFor<std::deque<int> >
// {
//     typedef std::deque<PendInfo> type;
// };
// PmergeMe::PmergeMe()
// {

// }
// PmergeMe::~PmergeMe()
// {

// }
// template<typename Container>
// void PmergeMe::print(const Container &c)
// {
//      for(size_t i = 0; i < c.size();i++)
//     {
//         std::cout<< c[i] << " ";
//     }
//     std::cout << std::endl;
// }

// template <typename Container>
// void PmergeMe::sort_pairs(Container& c, size_t block_size)
// {
//     size_t pair_size = block_size * 2;

//     if (pair_size > c.size())
//         return;

//     for (size_t i = 0; i + pair_size <= c.size(); i += pair_size)
//     {
//         size_t left_max  = i + block_size - 1;
//         size_t right_max = i + pair_size - 1;

//         if (c[left_max] > c[right_max])
//         {
//             for (size_t j = 0; j < block_size; j++)
//                 std::swap(c[i + j], c[i + block_size + j]);
//         }
//     }

//     sort_pairs(c, block_size * 2);

//     Container main_chain;
//     Container pend;
//     typename InfoContainerFor<Container>::type pend_cont;
//     build_chains(c, main_chain, pend,pend_cont ,block_size);
//     binary_insertion(main_chain,pend_cont,pend,block_size);
   
//     c = main_chain;
// }
// template<typename Container>
// void PmergeMe::build_insertion_order(const Container& jacob,
//                            Container& order)
// {
//     size_t prev = 1;

//     for (size_t i = 0; i < jacob.size(); i++)
//     {
//         size_t current = jacob[i];

//         for (size_t j = current; j > prev; --j)
//             order.push_back(static_cast<int>(j));

//         prev = current;
//     }

// }
// template<typename Container>
// void PmergeMe::Jacobsthal_numbers(Container& c,
//                                   size_t size,
//                                   size_t block_size)
// {
//     c.clear();

//     size_t pend_blocks = size / block_size;

//     if (pend_blocks == 0)
//         return;

//     size_t max_label = pend_blocks + 1;

//     size_t j0 = 1;
//     size_t j1 = 3;

//     while (j1 <= max_label)
//     {
//         c.push_back(static_cast<int>(j1));

//         size_t next = j1 + 2 * j0;
//         j0 = j1;
//         j1 = next;
//     }

//     if (c.empty() || static_cast<size_t>(c.back()) != max_label)
//         c.push_back(static_cast<int>(max_label));
// }

// std::deque<int> PmergeMe::fordJohnsonDeque(std::deque<int> d)
// {
//     std::deque<int> main_chain;
//     std::deque<int> pend;

//     sort_pairs(d, 1);
//     print(d);
    
//     return(d);
// }
// template<typename Container, typename InfoContainer>
// size_t PmergeMe::member_position(
//         const Container& main,
//         const Container& pend,
//         const InfoContainer& pend_cont,
//         size_t pend_idx,
//         size_t block_size)
// {
//     size_t upper_block = main.size() / block_size;
//     int pend_max = pend[pend_idx * block_size + (block_size - 1)];
//     if (pend_cont[pend_idx].has_pair)
//         upper_block = pend_cont[pend_idx].pair_pos + 1;

//     size_t left = 0;
//     size_t right = upper_block;

//     while (left < right)
//     {
//         size_t mid = left + (right - left) / 2;

//         int main_max =
//             main[mid * block_size + (block_size - 1)];

//         if (main_max < pend_max)
//             left = mid + 1;
//         else
//             right= mid;
//     }

//     return left * block_size;
// }

// template<typename Container, typename InfoContainer>
// void PmergeMe::binary_insertion(Container& main,
//             InfoContainer& pend_cont, Container& pend, size_t block_size)
// {
//     Container jacob;
//     Jacobsthal_numbers(jacob, pend.size(), block_size);
//     Container order;
//     build_insertion_order(jacob, order);

//     for (size_t i = 0; i < order.size(); i++)
//     {
//         size_t index = static_cast<size_t>(order[i]) - 1;

//         if (pend_cont[index].has_pair)
//         {
//             size_t shifts = 0;
//             for (size_t j = 0; j < i; j++)
//             {
//                 size_t prev = static_cast<size_t>(order[j]) - 1;
//                 if (prev < index)
//                     shifts++;
//             }
//             pend_cont[index].pair_pos = (index + 1) + shifts;
//         }

//         size_t pos = member_position(main, pend, pend_cont, index, block_size);
//         main.insert(main.begin() + pos,
//                     pend.begin() + index * block_size,
//                     pend.begin() + index * block_size + block_size);
//     }
// }

// template<typename Container, typename InfoContainer>
// void PmergeMe::build_chains(const Container& v,
//                             Container& main,
//                             Container& pend,
//                             InfoContainer& pend_cont,
//                             size_t block_size)
// {
//     main.clear();
//     pend.clear();
//     pend_cont.clear();

//     if (v.empty())
//         return;

//     size_t pair_size = block_size * 2;
//     bool first_pair = true;
//     size_t i;

//     for (i = 0; i + pair_size <= v.size(); i += pair_size)
//     {
//         size_t b_start = i;
//         size_t a_start = i + block_size;

//         if (first_pair)
//         {
//             for (size_t j = 0; j < block_size; j++)
//                 main.push_back(v[b_start + j]);

//             for (size_t j = 0; j < block_size; j++)
//                 main.push_back(v[a_start + j]);

//             first_pair = false;
//         }
//         else
//         {
//             for (size_t j = 0; j < block_size; j++)
//                 pend.push_back(v[b_start + j]);

//             PendInfo pend_;
//             pend_.pend = b_start;
//             pend_.has_pair = true;
//             pend_.pair_pos = a_start;
//             pend_cont.push_back(pend_);

//             for (size_t j = 0; j < block_size; j++)
//                 main.push_back(v[a_start + j]);
//         }
//     }

//     if (i + block_size <= v.size())
//     {
//         for (size_t j = 0; j < block_size; j++)
//             pend.push_back(v[i + j]);

//         PendInfo pend_;
//         pend_.pend = i;
//         pend_.has_pair = false;
//         pend_cont.push_back(pend_);
//     }
// }
// std::vector<int> PmergeMe::fordJohnsonVector(std::vector<int> v)
// {
//     std::vector<int> main_chain;
//     std::vector<int> pend;

//     sort_pairs(v, 1);
//     std::cout << "\n";
//     return(v);
// }
// bool PmergeMe::parse_input(std::string str)
// {
//     if (str.empty())
//      return false;
//     for(size_t i = 0; i < str.size(); i++)
//     {
//         if (!std::isdigit(static_cast<unsigned char>(str[i])))
//             return(false);
//     }
//     return(true);
// }
// bool PmergeMe::setup(char **argv, int argc)
// {
//     for(int i = 1; i < argc; i++)
//     {
//         if(!parse_input(argv[i]))
//         {
//             std::cerr << "ERROR \n";
//             return(false); 
//         }
//         char *end;
//         long nbr = strtol(argv[i], &end, 10);
//         if(*end !='\0' ||nbr >INT_MAX )
//         {
//             std::cerr << "ERROR \n";
//             return(false); 
//         }
//         vec.push_back(static_cast<int>(nbr));
//         deq.push_back(static_cast<int>(nbr));
//     }
//     return(true);
// }
//  void PmergeMe::run(char **argv, int argc)
//  {
//     if(!setup(argv,argc))
//         return;
//     std::cout << "Before: ";
//     print(vec);
//     clock_t start1 = clock();

//     std::vector<int> sorted_vec = fordJohnsonVector(vec);

//     clock_t end1 = clock();

//     clock_t start2 = clock();

//    std::deque<int> sorted_deq = fordJohnsonDeque(deq);

//     clock_t end2 = clock();

//     std::cout << "After: ";
//     print(sorted_vec);

//     double time_vec = (double)(end1 - start1)/ CLOCKS_PER_SEC;
//     double time_deq = (double)(end2 - start2)/ CLOCKS_PER_SEC;

//     std::cout << "Time vector: " << time_vec << " us\n";
//     std::cout << "Time deque : " << time_deq << " us\n";
//  }
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

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

template<typename Container>
void PmergeMe::print(const Container &c)
{
    for (size_t i = 0; i < c.size(); i++)
        std::cout << c[i] << " ";
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

    build_chains(c, main_chain, pend, pend_cont, block_size);
    binary_insertion(main_chain, pend_cont, pend, block_size);

    c = main_chain;
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

template<typename Container, typename InfoContainer>
size_t PmergeMe::member_position(
        const Container& main,
        const Container& pend,
        const InfoContainer& pend_cont,
        size_t pend_idx,
        size_t block_size)
{
    int pend_max =
        pend[pend_idx * block_size + (block_size - 1)];

    size_t upper_block = main.size() / block_size;

    if (pend_idx < pend_cont.size() && pend_cont[pend_idx].has_pair)
        upper_block = pend_cont[pend_idx].pair_pos + 1;

    if (upper_block > main.size() / block_size)
        upper_block = main.size() / block_size;

    size_t left = 0;
    size_t right = upper_block;

    while (left < right)
    {
        size_t mid = left + (right - left) / 2;

        int main_max =
            main[mid * block_size + (block_size - 1)];

        if (main_max < pend_max)
            left = mid + 1;
        else
            right = mid;
    }

    return left * block_size;
}


template<typename Container, typename InfoContainer>
void PmergeMe::binary_insertion(Container& main,
                                InfoContainer& pend_cont,
                                Container& pend,
                                size_t block_size)
{
    Container jacob;
    Jacobsthal_numbers(jacob, pend.size(), block_size);

    Container order;
    build_insertion_order(jacob, order);

    for (size_t i = 0; i < order.size(); i++)
    {
        size_t index = static_cast<size_t>(order[i]) - 2;

        if (index * block_size >= pend.size())
            continue;

        size_t pos =
            member_position(main, pend, pend_cont, index, block_size);

        main.insert(main.begin() + pos,
                    pend.begin() + index * block_size,
                    pend.begin() + index * block_size + block_size);
        size_t inserted_block_idx = pos / block_size;
        for (size_t k = 0; k < pend_cont.size(); k++)
        {
            if (pend_cont[k].has_pair && static_cast<size_t>(pend_cont[k].pair_pos) >= inserted_block_idx)
                pend_cont[k].pair_pos++;
        }
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
    size_t i = 0;

    if (v.size() >= pair_size)
    {
        for (size_t j = 0; j < block_size; j++)
            main.push_back(v[j]);

        for (size_t j = 0; j < block_size; j++)
            main.push_back(v[block_size + j]);

        i = pair_size;
    }

    for (; i + pair_size <= v.size(); i += pair_size)
    {
        for (size_t j = 0; j < block_size; j++)
            pend.push_back(v[i + j]);

        PendInfo p;
        p.pend = i;
        p.has_pair = true;
        p.pair_pos = main.size() / block_size;

        pend_cont.push_back(p);

        for (size_t j = 0; j < block_size; j++)
            main.push_back(v[i + block_size + j]);
    }

    if (i + block_size <= v.size())
    {
        for (size_t j = 0; j < block_size; j++)
            pend.push_back(v[i + j]);

        PendInfo p;
        p.pend = i;
        p.has_pair = false;
        p.pair_pos = 0;

        pend_cont.push_back(p);
        i += block_size;
    }

    for (; i < v.size(); i++)
        main.push_back(v[i]);
}

std::deque<int> PmergeMe::fordJohnsonDeque(std::deque<int> d)
{
    sort_pairs(d, 1);
    return d;
}

std::vector<int> PmergeMe::fordJohnsonVector(std::vector<int> v)
{
    sort_pairs(v, 1);
    return v;
}

bool PmergeMe::parse_input(std::string str)
{
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.size(); i++)
        if (!std::isdigit(static_cast<unsigned char>(str[i])))
            return false;

    return true;
}

bool PmergeMe::setup(char **argv, int argc)
{
    for (int i = 1; i < argc; i++)
    {
        if (!parse_input(argv[i]))
        {
            std::cerr << "ERROR\n";
            return false;
        }

        char *end;
        long nbr = strtol(argv[i], &end, 10);

        if (*end != '\0' || nbr > INT_MAX)
        {
            std::cerr << "ERROR\n";
            return false;
        }

        vec.push_back((int)nbr);
        deq.push_back((int)nbr);
    }
    return true;
}

void PmergeMe::run(char **argv, int argc)
{
    if (!setup(argv, argc))
        return;

    std::cout << "Before: ";
    print(vec);

    clock_t start1 = clock();
    std::vector<int> sorted_vec = fordJohnsonVector(vec);
    clock_t end1 = clock();

    clock_t start2 = clock();
    std::deque<int> sorted_deq = fordJohnsonDeque(deq);
    clock_t end2 = clock();

    std::cout << "After: ";
    print(sorted_vec);

    std::cout << "Time vector: "
              << (double)(end1 - start1) / CLOCKS_PER_SEC
              << " us\n";

    std::cout << "Time deque : "
              << (double)(end2 - start2) / CLOCKS_PER_SEC
              << " us\n";
}