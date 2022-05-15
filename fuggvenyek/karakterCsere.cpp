#include <iostream>
#include <cstring>

using namespace std;


string replaceChar(string szoveg, char mit, char mire) {

	int n = szoveg.length();
	string modositottSzoveg = "";

	for (int i = 0; i < n; i++)
	{
		modositottSzoveg += szoveg[i] == mit ? mire : szoveg[i];
	}
	
	return modositottSzoveg;
}

int main()
{
	string s = "Haha gen";
	string vmi = replaceChar(s, ' ', '!');
	cout << vmi;


	return 0;
}
