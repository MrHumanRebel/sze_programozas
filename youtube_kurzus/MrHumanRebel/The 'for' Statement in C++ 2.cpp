#include <iostream>

int main() {
  int sum = 0;
  for (int i=1; i<=10; i++)
  {sum += i; //ugyan az mintha sum = sum + i -t írnánk, ez kompaktabb
  }
  std::cout << " A szumma 1-től 10-ig = " << sum << std::endl;
  return 0;
}
