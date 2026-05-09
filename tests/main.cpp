
#include <cstdlib>
#include <iostream>
// int main()
// {
//    Bureaucrat bur;
//   std::cout <<  bur.getName() << "\n";
// //  try
// //     {
// //         bur.setGrade(1);
// //     }
// //     catch (std::exception & e)
// //     {
// //         std::cout << e.what() << "\n";
// //     }
//     try
//     {
//         bur.increment();
//     }
//     catch (std::exception & e)
//     {
//         std::cout << e.what() << "\n";
//     }
//   std::cout << bur;
  //   std::cout <<"got\n";
  // //  std::srand(); // fixed seed

  //   std::cout << std::rand() << "\n";
  //   std::cout << std::rand() << "\n";
  //   std::cout << std::rand() << "\n";
//  try{
//   new int[999999999999];
//  }
//  catch(std::exception& e)
//  {
//    std::cout<<e.what() << "\n";
//  }
//  std::cout << "rest of main happeneed\n";
#include <exception>
struct A {
    A(std::string name) : name(name) { std::cout << name << " constructed\n"; }
    ~A()                             { std::cout << name << " destroyed\n"; }
    std::string name;
};

void bar()
{
    A c("C");
    throw std::exception();
    A d("D");
}

void foo()
{
    A b("B");
    try
    {
        A r("R");
        bar();
    }
    catch (std::exception& e)
    {
        std::cout << "caught\n";
    }
    A e("E");
}

int main()
{
    A f("F");
    foo();
}
// int main()
// {
//     try
//     {
//         throw std::exception();
//     }
//     catch (const std::exception& e)
//     {
//         std::cout << "Caught std::exception:\n";
//         std::cout << "what(): [" << e.what() << "]\n";
//     }
// }
