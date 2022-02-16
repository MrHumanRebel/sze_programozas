#include <iostream>

int main() {
    std::cout << "Adjon meg számokat /SPACE/-el elválasztva majd nyomjon /CTRL + D/-t a befejezéshez!\n";
  int currVal = 0, val = 0;
  if (std::cin >> currVal){
    int cnt = 1;
    while (std::cin >> val) {
       if (val == currVal) {
            ++cnt;
       }
      else {
        std::cout << currVal << " előfordul " << cnt << " alkalommal\n" << std::endl;
        currVal = val;
        cnt = 1;
      }
    }
    std::cout << currVal << " előfordul " << cnt << " alkalommal\n" << std::endl;
  }

  return 0;
}
