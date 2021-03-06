/* Töreky Zsombor (tzsombi01) */

#include <iostream>

#define CHAR1 ".,-?!1"
#define CHAR2 "ABC2"
#define CHAR3 "DEF3"
#define CHAR4 "GHI4"
#define CHAR5 "JKL5"
#define CHAR6 "MNO6"
#define CHAR7 "PQRS7"
#define CHAR8 "TUV8"
#define CHAR9 "WXYZ9"
#define CHAR0 "+0"
#define SCHAR1 "lu*"
/*l=Lowercase, u=uppercase*/
#define SCHAR2 " #"

char decCurr(char inpChar, int appearances)
{
  char outpChar;
  static bool isItLowerCase;
  switch (inpChar)
  {
  case '1':
    if (not isItLowerCase)
      outpChar = CHAR1[appearances];
    else
      outpChar = tolower(CHAR1[appearances]);
    break;
  case '2':
    if (not isItLowerCase)
      outpChar = CHAR2[appearances];
    else
      outpChar = tolower(CHAR2[appearances]);
    break;
  case '3':
    if (not isItLowerCase)
      outpChar = CHAR3[appearances];
    else
      outpChar = tolower(CHAR3[appearances]);
    break;
  case '4':
    if (not isItLowerCase)
      outpChar = CHAR4[appearances];
    else
      outpChar = tolower(CHAR4[appearances]);
    break;
  case '5':
    if (not isItLowerCase)
      outpChar = CHAR5[appearances];
    else
      outpChar = tolower(CHAR5[appearances]);
    break;
  case '6':
    if (not isItLowerCase)
      outpChar = CHAR6[appearances];
    else
      outpChar = tolower(CHAR6[appearances]);
    break;
  case '7':
    if (not isItLowerCase)
      outpChar = CHAR7[appearances];
    else
      outpChar = tolower(CHAR7[appearances]);
    break;
  case '8':
    if (not isItLowerCase)
      outpChar = CHAR8[appearances];
    else
      outpChar = tolower(CHAR8[appearances]);
    break;
  case '9':
    if (not isItLowerCase)
      outpChar = CHAR9[appearances];
    else
      outpChar = tolower(CHAR9[appearances]);
    break;
  case '0':
    if (not isItLowerCase)
      outpChar = CHAR0[appearances];
    else
      outpChar = tolower(CHAR0[appearances]);
    break;
  case '*':
    if (appearances == 2)
    {
      outpChar = SCHAR1[appearances];
    }
    else if (appearances == 0)
    {
      outpChar = '\0'; // Empty char
      isItLowerCase = true;
    }
    else if (appearances == 1)
    {
      outpChar = '\0'; // Empty char
      isItLowerCase = false;
    }
    break;
  case '#':
    outpChar = SCHAR2[appearances];
    break;
  default: // undefined character appears
    outpChar = ' ';
    break;
  }
  return outpChar;
}

std::string decode(std::string inputS)
{
  std::string answer = "";
  int appearances = 0;
  int i, k = 0;
  for (i = 0; i < inputS.length(); i++)
  {
    appearances = 0;
    if (k == i)
    {
      while (k < inputS.length())
      {
        if (inputS[k] == inputS[k + 1])
        {
          appearances += 1;
          k++;
        }
        else
        {
          answer += decCurr(inputS[i], appearances);
          k++;
          break;
        }
      }
    }
  }
  return answer;
}

int main()
{
  std::string inp;
  std::cout << "Enter a messsage: " << std::endl;
  std::getline(std::cin, inp);
  std::string answer = decode(inp);
  std::cout << "The decoded string:" << answer << std::endl;
  return 0;
}
