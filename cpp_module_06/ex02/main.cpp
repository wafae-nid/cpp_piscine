#include "Functions.hpp"

int main()
{
  std::srand(std::time(NULL));
  Base* obj = generate();
  std::cout << "Pointer identify: ";
  identify(obj);

  std::cout << "Reference identify: ";
  identify(*obj);

  std::cout << "----------------------\n";

  delete obj; 

    return 0;
}
