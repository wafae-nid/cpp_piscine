#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <stdlib.h>
#include <limits.h>
#include <ctime>

struct pair
{
    int big ;
    int small;

};

class PmergeMe
{
    public:
       PmergeMe();
       ~PmergeMe();
      bool parse_input(std::string str);
      void run(char **argv, int argc);

      

      template<typename Container>
      void print(const Container &c);

      std::vector<int> fordJohnsonVector(std::vector<int> v);
      std::deque<int> fordJohnsonDeque(std::deque<int> d);
      //std::deque<pair> make_pairs_deq(std::deque<int> d);
      //std::vector<pair> make_pairs_vec(std::vector<int> d);
      //void build_chain_deq(std::vector<pair> const &pairs);
      //std::vector<int> build_chain_vec(std::vector<int> vec);
      template<typename Container>
      void Jacobsthal_numbers(Container &c,size_t size, size_t block_size);
      template<typename Container>
      void build_chains(const Container& ,Container& main,
                            Container& pend,size_t block_size);
      template <typename Container>
      void sort_pairs(Container& c, size_t block_size);
      bool setup(char **argv, int argc); 
      template<typename Container>
       void build_insertion_order(const Container& jacob,Container& order);

    private:
        std::vector<int> vec;
        std::deque<int> deq; 

       
        //std::vector<int> main_chain_vec;
        //std::vector<int> pend_vec;

        std::deque<int> main_chain_deq;
        std::deque<int> pend_deq;

};

#endif