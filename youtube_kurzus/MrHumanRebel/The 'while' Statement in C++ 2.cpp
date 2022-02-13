#include <iostream>

int main() {
  int count = 1, sum = 0;
  while (count <=10)
  {
    sum += count;
    count = count + 1;
  }
  std::cout << "A szumma 1-től 10-ig = " <<sum <<std::endl;
  return 0;
}
