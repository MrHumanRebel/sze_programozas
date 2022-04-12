#include <iostream>

int main()
{
  int num = 0;
  std::cout << "Adjon meg egy számot!" << std::endl;
  std::cin >> num;
  if (num > 10)
  {
    std::cout << "A szám nagyobb mint 10." << std::endl;
  }
  return 0;
}
