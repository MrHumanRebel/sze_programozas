
#include <iostream>

#define MAXTOMBMERET 256

int beker(char be_tb[]);
void cserel(char s_tb[], int hossz, int *mgh, int *szk, int *msh, int *eb, int *tcs);
void kiir(char tomb[], int hossz, int *mgh, int *szk, int *msh, int *eb, int *tcs);
void kiir(char tomb[], int hossz, int *mgh, int *szk, int *msh, int *eb);

int main()
{
  char karaktertomb[MAXTOMBMERET] = {};
  int hanykarakter = beker(karaktertomb);
  int mgh = 0, szk = 0, msh = 0, eb = 0, tcs = 0;
  cserel(karaktertomb, hanykarakter, &mgh, &szk, &msh, &eb, &tcs);
  if (tcs > 0)
    kiir(karaktertomb, hanykarakter, &mgh, &szk, &msh, &eb, &tcs);
  else
    kiir(karaktertomb, hanykarakter, &mgh, &szk, &msh, &eb);
}

int beker(char be_tb[])
{
  std::string bekert;
  std::cout << "Kerem a szoveget " << std::endl;
  std::getline(std::cin, bekert);
  for (int i = 0; i < bekert.length(); i++)
  {
    be_tb[i] = bekert[i];
  }
  return bekert.std::string::length();
}

bool mgh_e(char keresett)
{
  std::string mgh = "aeiouAEIOU";
  bool found = false;
  int k = 0;
  while (k < mgh.length())
  {
    if (keresett == mgh[k])
    {
      found = true;
      break;
    }
    k++;
  }
  return found;
}

void cserel(char s_tb[], int hossz, int *mgh, int *szk, int *msh, int *eb, int *tcs)
{
  int i;
  for (i = 0; i < hossz; i++)
  {
    if (mgh_e(s_tb[i]))
    {
      ++*mgh;
      s_tb[i] = char(int(s_tb[i]) + 1);
    }
    else if ((int(s_tb[i]) <= 88 && int(s_tb[i]) >= 65) || (int(s_tb[i]) <= 120 && int(s_tb[i]) >= 97))
    {
      ++*msh;
      s_tb[i] = char(int(s_tb[i]) + 2);
    }
    else
    {
      switch (s_tb[i])
      {
      case ' ':
        ++*szk;
        s_tb[i] = '_';
        break;
      case 'y':
        ++*tcs;
        s_tb[i] = '!';
        break;
      case 'z':
        ++*tcs;
        s_tb[i] = '!';
        break;
      case 'Y':
        ++*tcs;
        s_tb[i] = '!';
        break;
      case 'Z':
        ++*tcs;
        s_tb[i] = '!';
        break;
      default:
        ++*eb;
        s_tb[i] = '*';
        break;
      }
    }
  }
}

void kiir(char tomb[], int hossz, int *mgh, int *szk, int *msh, int *eb, int *tcs)
{
  std::cout << "Átkódolt:";
  for (int i = 0; i <= hossz; i++)
  {
    std::cout << tomb[i];
  }
  std::cout << "\nAz összes karakter: " << hossz << "\nEbből:" << std::endl;
  std::cout << "Mgh: " << *mgh << "\nMsh: " << *msh << "\nszk: " << *szk << "\neb: " << *eb << "\n"
            << *tcs << " db túlcsordulás található" << std::endl;
}
void kiir(char tomb[], int hossz, int *mgh, int *szk, int *msh, int *eb)
{
  std::cout << "Átkódolt:";
  for (int i = 0; i <= hossz; i++)
  {
    std::cout << tomb[i];
  }
  std::cout << "\nAz összes karakter: " << hossz << "\nEbből:" << std::endl;
  std::cout << "Mgh: " << *mgh << "\nMsh: " << *msh << "\nszk: " << *szk << "\neb: " << *eb << "\nNincsen túlcsordulás!" << std::endl;
}
