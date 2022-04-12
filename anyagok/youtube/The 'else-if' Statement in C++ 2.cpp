#include <iostream>

int main()
{
  int num = 0;
  std::cout << "Adja meg, hogy kávét(1-es) vagy teát(2-es) szeretne inni!" << std::endl;
  std::cin >> num;
  if (num == 1)
  {
    std::cout << "Ön a kávét választotta, köszönjük a rendelést!" << std::endl;
  }
  else if (num == 2)
  {
    std::cout << "Ön a teát választotta, köszönjük a rendelést!" << std::endl;
  }
  else
  {
    std::cout << "Adjon meg egy valós terméket!" << std::endl;
  }
  return 0;
}
