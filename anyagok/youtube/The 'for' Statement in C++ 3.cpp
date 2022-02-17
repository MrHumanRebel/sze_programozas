#include <iostream>

int main()
{
  int sum = 0, val;
  std::cout << "Adja meg a számot ameddig szummázni akar!\n";
  std::cin >> val;
  for (int i = 1; i <= val; i++)
  {
    sum += i; // ugyan az mintha sum = sum + i -t írnánk, ez kompaktabb
  }
  std::cout << " A szumma 1-től " << val << "-ig = " << sum << std::endl;
  return 0;
}
