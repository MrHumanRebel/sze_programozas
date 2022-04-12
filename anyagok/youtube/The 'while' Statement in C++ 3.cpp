#include <iostream>

int main()
{
  int count = 1, sum = 0, val;
  std::cout << "Adjon meg egy számot ameddig ki akarja számolni a szummát!\n";
  std::cin >> val;
  while (count <= val)
  {
    sum += count;
    count = count + 1;
  }
  std::cout << "A szumma 1-től " << val << "-ig = " << sum << std::endl;
  return 0;
}
