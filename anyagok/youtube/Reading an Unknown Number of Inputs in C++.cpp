#include <iostream>

int main()
{
  int sum = 0, value = 0;
  std::cout << "Adjon meg számokat amiket szummázni akar, majd üssön le egy betű karaktert!\n";
  while (std::cin >> value)
  {
    sum += value;
  }
  std::cout << " A szumma " << sum << std::endl;
  return 0;
}
