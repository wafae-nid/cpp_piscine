#include "RPN.HPP"



int main(int argc,char **argv)
{
    if(argc != 2)
    {
        std::cerr << "please enter just your RPN \n";
        return(1);
    }
    RPN rpn;
    rpn.RPN_run(argv[1]);

}