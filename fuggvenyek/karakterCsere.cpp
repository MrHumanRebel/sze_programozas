#include <iostream>
#include <cstring>

using namespace std;
// C++: You just can not change/delete the space chars from a string to manage all the signs in it. This is illegal..

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
