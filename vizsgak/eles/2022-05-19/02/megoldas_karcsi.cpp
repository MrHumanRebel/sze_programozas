#include <iostream>
#include <cstring>

using namespace std;

#define MAX_DB 50

int feltolt(char s_tb[])
{
  cin.getline(s_tb, MAX_DB);

  int karDb = 0;
  while (s_tb[karDb])
  {
    karDb++;
  }

  return karDb;
}

void torol(char s_tb[], int h)
{
  int ujIndex = 0;
  for (int i = 0; i < h; i += 2)
  {
    s_tb[ujIndex] = s_tb[i];
    ujIndex++;
  }

  for (int i = 0; i < ujIndex; i++)
  {
    cout << s_tb[i];
  }
  cout << endl;
}

int main()
{
  char s_tb[MAX_DB];
  int karDb = feltolt(s_tb);
  torol(s_tb, karDb);

  return 0;
}
