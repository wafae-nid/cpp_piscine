#include "MutantStack.hpp"

int main()
{
    {
        std::cout << ">> my MutantStack result << \n";

        MutantStack<int> mstack;

        mstack.push(10);
        mstack.push(20);
        mstack.push(30);
        mstack.push(40);

        // Test inherited stack functions
        std::cout << "Top element: " << mstack.top() << "\n";
        std::cout << "Size: " << mstack.size() << "\n";

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        // Test ++ and --
        ++it;
        --it;

        while (it != ite)
        {
            *it = 50 + *it;
            ++it;
        }

        it = mstack.begin();

        std::cout << "Modified values:\n";
        while (it != ite)
        {
            std::cout << *it << "\n";
            ++it;
        }

        std::cout << "Const iterator test\n";

        const MutantStack<int> c_mstack(mstack);
        MutantStack<int>::const_iterator c_it = c_mstack.begin();
        MutantStack<int>::const_iterator c_ite = c_mstack.end();

        while (c_it != c_ite)
        {
            std::cout << *c_it << "\n";
            ++c_it;
        }

        // Test copy constructor
        std::cout << "\nCopy constructor test\n";
        MutantStack<int> copy(mstack);

        for (MutantStack<int>::iterator it = copy.begin(); it != copy.end(); ++it)
            std::cout << *it << "\n";

        // Test assignment operator
        std::cout << "\nAssignment operator test\n";
        MutantStack<int> assign;
        assign = mstack;

        for (MutantStack<int>::iterator it = assign.begin(); it != assign.end(); ++it)
            std::cout << *it << "\n";

        // Test compatibility with std::stack
        std::cout << "\nstd::stack compatibility test\n";
        std::stack<int> s(mstack);

        std::cout << "Top of std::stack: " << s.top() << "\n";

        s.pop();
        std::cout << "Top after pop: " << s.top() << "\n";
        std::cout << "Size after pop: " << s.size() << "\n";
    }

    {
        std::cout << "\n>> same input but with list << \n";

        std::list<int> lst;

        lst.push_back(10);
        lst.push_back(20);
        lst.push_back(30);
        lst.push_back(40);

        std::cout << "Back element: " << lst.back() << "\n";
        std::cout << "Size: " << lst.size() << "\n";

        std::list<int>::iterator it = lst.begin();
        std::list<int>::iterator ite = lst.end();

        ++it;
        --it;

        while (it != ite)
        {
            *it = 50 + *it;
            ++it;
        }

        it = lst.begin();

        std::cout << "Modified values:\n";
        while (it != ite)
        {
            std::cout << *it << "\n";
            ++it;
        }

        std::cout << "Const iterator test\n";

        const std::list<int> c_lst(lst);

        std::list<int>::const_iterator c_it = c_lst.begin();
        std::list<int>::const_iterator c_ite = c_lst.end();

        while (c_it != c_ite)
        {
            std::cout << *c_it << "\n";
            ++c_it;
        }
    }

    return 0;
}