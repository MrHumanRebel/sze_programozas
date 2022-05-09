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
*  Debreczeni Kálmán
*/

using namespace std;
#include <iostream>
#include <fstream> // Base
#include <string>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h> // For testing
#include <crtdbg.h>

#define say cout << 
#define ask cin >> // QOL Macros
#define creturn say endl;


void QuickSort(int* unsortedArray, int length, int left = 0, int right = -1);
void CountSort(int* unsortedArray, int length);
int ConvertToInt(string str);
template<class T> void Swap(T& left, T& right);
template<class T> void Reverse(T* arr, int length);
string ReverseString(string str);
template<class T> int IndexOf(T* arr, int length, T searchedElement);
template<class T> int LastIndex(T* arr, int length, T searchedElement);
char** ReadAllLines(string fileName, int* length);
template <class T>
class LinkedListNode;
template<class T>
class DLinkedList;
// TODO: Improve
// TODO: Expand
// TODO: Intensive and extensive testing


int main()
{
	DLinkedList<int>* test = new DLinkedList<int>;

	for (int i = 0; i < 100000; i++)
	{
		test->PushAt((test->Count() == 0) ? 0 : rand() % test->Count(), i);
	}
	creturn;
	test->Swap(5, 7);
	for (int i = 0; i < test->Count() - 1; i++)
	{
		test->Swap(i, i + 1);

	}
	delete (test);
	int leaks = _CrtDumpMemoryLeaks();
	say leaks;
}


/// <summary>
/// The elements of which the DLinkedList is made up
/// </summary>
/// <typeparam name="T">Any</typeparam>
template <class T>
class LinkedListNode
{
public:
	/// <summary>
	/// The stored data
	/// </summary>
	T data;

	/// <summary>
	/// The next element in the list
	/// </summary>
	LinkedListNode<T>* nextElement;

	/// <summary>
	/// The previous element in the list
	/// </summary>
	LinkedListNode<T>* previousElement;

	/// <summary>
	/// Default constructor
	/// </summary>
	LinkedListNode()
	{
		data = NULL;
		nextElement = nullptr;
		previousElement = nullptr;
	}

	/// <summary>
	/// Constructor with definable data as parameter
	/// </summary>
	/// <param name="data">Data to be stored</param>
	LinkedListNode(T data)
	{
		this->data = data;
		nextElement = nullptr;
		previousElement = nullptr;
	}
	~LinkedListNode()
	{

	}

private:

};

/// <summary>
/// Two way linked list made possible by Debreczeni, Kálmán
/// </summary>
/// <typeparam name="T">Any</typeparam>
template<class T>
class DLinkedList
{

public:

	/// <summary>
	/// The first element of the linked list
	/// </summary>
	LinkedListNode<T>* firstElement;

	/// <summary>
	/// The last element of the list
	/// </summary>
	LinkedListNode<T>* lastElement;

	/// <summary>
	/// The currently active element of the list
	/// </summary>
	LinkedListNode<T>* currentElement;

	/// <summary>
	/// Constructor
	/// </summary>
	DLinkedList()
	{

	}

	/// <summary>
	/// Count of the elements in the list
	/// </summary>
	/// <returns>Count of the elements in the list</returns>
	int Count()
	{
		return count;
	}

	/// <summary>
	/// The index of the currently active node
	/// </summary>
	/// <returns>The index of the currently active node</returns>
	int CurrentIndex()
	{
		return currentIndex;
	}

	// Need help in this one. Doesn't recognize [] as an operator
	/*LinkedListNode<T>* operator[](int index)
	{
		SeekToIndex(index);
		return currentElement;
	}*/

	/// <summary>
	/// Seeks to the specified index in the list, making the nth element active
	/// </summary>
	/// <param name="newIndex">The index to seek to</param>
	void SeekToIndex(int newIndex)
	{
		if (currentIndex == newIndex)
		{
			return;
		}
		else
		{
			if (currentIndex > newIndex)
			{
				if (currentIndex - newIndex > newIndex)
				{
					currentElement = firstElement;
					currentIndex = 0;
					for (int i = 0; i < newIndex; i++)
					{
						StepForward();
					}
				}
				else
				{
					for (int i = 0; i < currentIndex - newIndex; i++)
					{
						StepBackward();
					}
				}
			}
			else
			{
				if (newIndex - currentIndex > count - newIndex)
				{
					currentElement = lastElement;
					currentIndex = count - 1;
					for (int i = 0; i < count - newIndex; i++)
					{
						StepBackward();
					}
				}
				else
				{
					for (int i = 0; i < newIndex - currentIndex; i++)
					{
						StepForward();
					}
				}
			}
		}
		currentIndex = newIndex;
	}

	/// <summary>
	/// Steps to the next element of the list
	/// </summary>
	/// <returns>Whether the step was possible</returns>
	bool StepForward()
	{
		if (currentIndex == count - 1)
		{
			return false;
		}
		else
		{
			currentElement = currentElement->nextElement;
		}
		return true;
	}

	/// <summary>
	/// Steps to the previous element of the list
	/// </summary>
	/// <returns>Whether the step was possible</returns>
	bool StepBackward()
	{
		if (currentIndex == 0)
		{
			return false;
		}
		else
		{
			currentElement = currentElement->previousElement;
		}
		return true;
	}

	/// <summary>
	/// Pushes data to the list, behind the active element
	/// </summary>
	/// <param name="data">Data to be stored</param>
	/// <returns>Whether the push was sucessful</returns>
	bool Push(T data)
	{
		if (count == 0)
		{
			LinkedListNode<T>* n = new LinkedListNode<T>(data);
			if (n != nullptr)
			{
				firstElement = n;
				currentElement = n;
				lastElement = n;
				currentIndex = 0;
				count = 1;
				return true;
			}
			else return false;
		}
		else
		{
			if (currentIndex == count - 1)
			{
				currentIndex++;
				bool tmp = PushLast(data);
				currentElement = lastElement;
				return tmp;
			}
			else
			{
				LinkedListNode<T>* n = new LinkedListNode<T>(data);
				if (n != nullptr)
				{
					currentElement->nextElement->previousElement = n;
					n->nextElement = currentElement->nextElement;
					currentElement->nextElement = n;
					n->previousElement = currentElement;
					currentElement = n;
					count++;
					currentIndex++;
					return true;
				}
				else return false;
			}
		}
	}

	/// <summary>
	/// Pushes data to the head of the list
	/// </summary>
	/// <param name="data">Data to be stored</param>
	/// <returns>Whether the push was sucessful</returns>
	bool PushFirst(T data)
	{
		LinkedListNode<T>* n = new LinkedListNode<T>(data);
		if (n != nullptr)
		{
			firstElement->previousElement = n;
			n->nextElement = firstElement;
			firstElement = n;
			count++;
		}
		else return false;
	}

	/// <summary>
	/// Pushes data to the tail of the list
	/// </summary>
	/// <param name="data">Data to be stored</param>
	/// <returns>Whether the push was sucessful</returns>
	bool PushLast(T data)
	{
		LinkedListNode<T>* n = new LinkedListNode<T>(data);
		if (n != nullptr)
		{
			lastElement->nextElement = n;
			n->previousElement = lastElement;
			lastElement = n;
			count++;
		}
		else return false;
	}

	/// <summary>
	/// Pushes data to the specified index, moving the rest of the list backwards
	/// </summary>
	/// <param name="index">The index of the new element</param>
	/// <param name="data">Data to be stored</param>
	/// <returns>Whether the push was sucessful</returns>
	bool PushAt(int index, T data)
	{
		int revert = currentIndex;
		SeekToIndex(index);
		bool tmp = Push(data);
		SeekToIndex(revert);
		return tmp;

	}

	/// <summary>
	/// Removes the element at the specified index
	/// </summary>
	/// <param name="index">The index of the element</param>
	void RemoveAt(int index)
	{
		int revert = currentIndex;
		SeekToIndex(index);
		if (index == 0) // first element
		{
			currentElement = currentElement->nextElement;
			delete (firstElement);
			firstElement = currentElement;
			currentElement->previousElement = nullptr;
		}
		else if (index == count - 1)
		{
			currentElement = currentElement->previousElement;
			delete lastElement;
			lastElement = currentElement;
			currentElement->nextElement = nullptr;
			currentIndex--;
		}
		else
		{
			currentElement = currentElement->previousElement;
			currentElement->nextElement = currentElement->nextElement->nextElement;
			delete (currentElement->nextElement->previousElement);
			currentElement->nextElement->previousElement = currentElement;
		}
		count--;
		SeekToIndex(revert);
	}

	/// <summary>
	/// Reads the data of the given index
	/// </summary>
	/// <param name="index">The index of the requested element</param>
	/// <returns>The data of teh element</returns>
	T GetDataAt(int index)
	{
		int revert = currentIndex;
		SeekToIndex(index);
		T tmp = currentElement->data;
		SeekToIndex(revert);
		return tmp;
	}

	void Swap(int leftIndex, int rightIndex)
	{
		int revert = currentIndex;
		SeekToIndex(leftIndex);
		T left = currentElement->data;
		SeekToIndex(rightIndex);
		T right = currentElement->data;
		SeekToIndex(leftIndex);
		currentElement->data = right;
		SeekToIndex(rightIndex);
		currentElement->data = left;
		SeekToIndex(revert);
	}


	/// <summary>
	/// Empties the list and sets it up to be reused
	/// </summary>
	void Empty()
	{
		LinkedListNode<T>* tmp;
		while (firstElement != nullptr)
		{
			tmp = firstElement->nextElement;
			delete(firstElement);
			firstElement = tmp;
		}
		currentIndex = -1;
		count = 0;
	}

	~DLinkedList()
	{
		Empty();
	}

private:
	int currentIndex;
	unsigned int count;

};


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
/// <typeparam name="T">Any non-pointer type</typeparam>
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
/// <returns>All lines for the file as a char**</returns>
char** ReadAllLines(string fileName, int* length)
{
	ifstream ifs(fileName);
	*length = 1;
	int count = -1;
	char** arr = (char**)calloc(*length, sizeof(char*));
	string line;
	char* lineChar;

	while (getline(ifs, line))
	{
		lineChar = (char*)malloc(line.length() * sizeof(char) + 1);
		for (int i = 0; i < line.length(); i++)
		{
			lineChar[i] = line[i];
		}
		lineChar[line.length()] = '\0';
		count++;
		arr[count] = lineChar;
		if (count + 1 == *length)
		{
			*length *= 2;
			char** tmp = (char**)malloc(*length * sizeof(char*));
			for (int i = 0; i < count + 1; i++)
			{
				tmp[i] = arr[i];
			}
			free(arr);
			arr = (char**)malloc(*length * sizeof(char*));
			for (int i = 0; i < count + 1; i++)
			{
				arr[i] = tmp[i];
			}
			free(tmp);
		}

	}

	*length = count + 1;
	ifs.close();
	return arr;
}
// TODO: Improve