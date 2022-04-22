/*
* Written by:
*
* '########:::::'#######:::'#######::
*  ##.....:::::'##.... ##:'##.... ##:
*  ##:::::::::: ##:::: ##: ##:::: ##:
*  ######::::::: ########:: #######::
*  ##...::::::::...... ##:'##.... ##:
*  ##::::::::::'##:::: ##: ##:::: ##:
*  ##::::::::::. #######::. #######::
* ..::::::::::::.......::::.......:::
* 
*/

#include <iostream>
#include <fstream>
#include <string>

#define say cout << 
#define read cin >>
#define creturn say endl;

using namespace std;

void QuickSort(int* unsortedArray, int length, int left = 0, int right = -1);
void CountSort(int* unsortedArray, int length);
int ConvertToInt(string str);
template<class T> void Swap(T& left, T& right);
template<class T> void Reverse(T* arr, int length);
string ReverseString(string str);
template<class T> int IndexOf(T* arr, int length, T searchedElement);
template<class T> int LastIndex(T* arr, int length, T searchedElement);
string* ReadAllLines(string fileName, int* length);
// TODO: Fix C6385 at ReadAllLines
// TODO: Expand
// TODO: Intensive and extensive testing

//int main()
//{
//	int a[] = { 7,6,5,4,3,2,1,0 };
//	QuickSort(a, 8);
//	string asd = "asd";
//	asd = ReverseString(asd);
//	say "asd";
//}


/// <summary>
/// Sorts array elements using Quicksort.
/// </summary>
/// <param name="unsortedArray">The reference to the unsorted array</param>
/// <param name="length">Length of the array</param>
/// <param name="left">Where the sorting should begin. By default, the entire array</param>
/// <param name="right">Where the sorting should end. By default, the entire array</param>
void QuickSort(int* unsortedArray, int length, int left, int right)
{
	if (right == -1)
	{
		right = length - 1;
	}
	int pivot = unsortedArray[left];
	int lhold = left;
	int rhold = right;
	while (left < right)
	{
		while (unsortedArray[right] >= pivot && left < right)
		{
			--right;
		}
		if (left != right)
		{
			unsortedArray[left] = unsortedArray[right];
			++left;
		}
		while (unsortedArray[left] <= pivot && left < right)
		{
			++left;
		}
		if (left != right)
		{
			unsortedArray[right] = unsortedArray[left];
			--right;
		}
	}
	unsortedArray[left] = pivot;
	pivot = left;
	left = lhold;
	right = rhold;
	if (left < pivot)
	{
		QuickSort(unsortedArray, length, left, pivot - 1);
	}
	if (right > pivot)
	{
		QuickSort(unsortedArray, length, pivot + 1, right);
	}
}

/// <summary>
/// Sorts array elements using Counting sort. Best for repeating elements
/// </summary>
/// <param name="unsortedArray">The reference to the unsorted array</param>
/// <param name="length">Length of the array</param>
void CountSort(int* unsortedArray, int length)
{
	int max = INT16_MIN;
	int min = INT16_MAX;
	for (int i = 0; i < length; i++)
	{
		if (unsortedArray[i] > max)
		{
			max = unsortedArray[i];
		}
		if (unsortedArray[i] < min)
		{
			min = unsortedArray[i];
		}
	}
	int shift = 0 - min;
	int helpLen = abs(max) + shift;
	int* helper = (int*)calloc(helpLen + (int)1, sizeof(int));
	for (int i = 0; i < length; i++)
	{
		helper[unsortedArray[i] + shift]++;
	}
	int index = 0;
	for (int i = 0; i < helpLen + 1; i++)
	{
		while (helper[i] != 0)
		{
			helper[i]--;
			unsortedArray[index] = i + min;
			index++;
		}
	}
}

/// <summary>
/// Converts the given string to an integer
/// </summary>
/// <param name="str">String containing the number</param>
/// <returns>The number extracted from the string. If failed, returns 0</returns>
int ConvertToInt(string str)
{
	bool isNegative = (str[0] == '-');
	int retNumber = 0;
	for (short i = isNegative; i < str.length(); i++)
	{
		if ((int)(str[i]) - 48 >= 0 && (int)(str[i]) - 48 <= 9)
		{
			retNumber += (int)(((int)(str[i])) - (int)48) * pow(10, str.length() - i - (int)1);
		}
		else
		{
			retNumber = 0;
			break;
		}
	}
	retNumber -= (int)isNegative * retNumber * 2;
	return retNumber;
}

/// <summary>
/// Swaps two variables
/// </summary>
/// <typeparam name="T">Anything</typeparam>
/// <param name="left">First variable</param>
/// <param name="right">Second variable</param>
template<class T> void Swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
	return;
}

/// <summary>
/// Reverses the given array
/// </summary>
/// <typeparam name="T">Anything but string</typeparam>
/// <param name="arr">The array to be reversed</param>
/// <param name="length">Length of the array</param>
template<class T> void Reverse(T* arr, int length)
{
	for (int i = 0; i < length / 2; i++)
	{
		Swap(arr[i], arr[length - i - 1]);
	}
}

/// <summary>
/// Reverses a string
/// </summary>
/// <param name="str">String to be reversed</param>
/// <returns>The reversed string</returns>
string ReverseString(string str)
{
	for (int i = 0; i < str.length() / 2; i++)
	{
		Swap(str[i], str[str.length() - i - 1]);
	}
	return str;
}

/// <summary>
/// Finds the first index in the array that matches the given search parameter
/// </summary>
/// <typeparam name="T">Array-like structure</typeparam>
/// <param name="arr">The search array</param>
/// <param name="length">Lenght of the array</param>
/// <param name="searchedElement">The element that needs to be found</param>
/// <returns>The first index of the searched element, otherwise -1</returns>
template<class T> int IndexOf(T* arr, int length, T searchedElement)
{
	for (int i = 0; i < length; i++)
	{
		if (arr[i] == searchedElement)
		{
			return i;
		}
	}
	return -1;
}

/// <summary>
/// Finds the last index in the array that matches the given search parameter
/// </summary>
/// <typeparam name="T">Array-like structure</typeparam>
/// <param name="arr">The search array</param>
/// <param name="length">Lenght of the array</param>
/// <param name="searchedElement">The element that needs to be found</param>
/// <returns>The last index of the searched element, otherwise -1</returns>
template<class T> int LastIndex(T* arr, int length, T searchedElement)
{
	for (int i = length - 1; i >= 0; i--)
	{
		if (arr[i] == searchedElement)
		{
			return i;
		}
	}
	return -1;
}

/// <summary>
/// Reads all lines of a file and stores them in the memory
/// </summary>
/// <param name="fileName">The name of the file</param>
/// <param name="length">Output parameter: the length of the returned array</param>
/// <returns>All lines for the file as a string*</returns>
string* ReadAllLines(string fileName, int* length)
{
	ifstream ifs(fileName);
	*length = 1;
	int count = 0;
	string* arr = (string*)calloc(*length, sizeof(string));
	string line;
	while (getline(ifs, line))
	{
		arr[count] = line;
		count++;
		if (count == *length)
		{
			*length *= 2;
			string* tmp = (string*)realloc(arr, *length);
			arr = (tmp == nullptr) ? throw new exception("Out of memory") : tmp;
		}
	}
	string* tmp = (string*)realloc(arr, *length);
	arr = (tmp == nullptr) ? throw new exception("Out of memory") : tmp;
	*length = count;
	ifs.close();
	return arr;
}