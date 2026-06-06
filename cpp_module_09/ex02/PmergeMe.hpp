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
      std::deque<pair> make_pairs_deq(std::deque<int> d);
      std::vector<pair> make_pairs_vec(std::vector<int> d);
      bool setup(char **argv, int argc);   
    private:
        std::vector<int> vec;
        std::deque<int> deq; 
        bool has_leftover;
        int leftover;

};

#endif