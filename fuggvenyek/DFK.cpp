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
template<class T> void RotateArray(T* arr, int length, int steps);
template<class T> void ShiftArray(T* arr, int length, int steps, T filler = NULL);
char** ReadAllLines(string fileName, int* length);




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
		delete data;
	}

private:

};

/// <summary>
/// Two way linked list
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


	// LinkedListNode<T>* operator[](int index)     // nem ismeri fel []-t mint oerátort
	// {
	// 	int revert = index;
	// 	SeekToIndex(index);
	// 	LinkedListNode<T>* tmp = currentElement;
	// 	SeekToIndex(revert);
	// 	return tmp;
	// }

	/// <summary>
	/// Seeks to the specified index in the list, making the nth element active
	/// </summary>
	/// <param name="newIndex">The index to seek to</param>
	void SeekToIndex(int newIndex)
	{
		if (newIndex < 0 || newIndex >= count)
		{
			return;
		}
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
					int steps = currentIndex - newIndex;
					for (int i = 0; i < steps; i++)
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
					for (int i = 0; i < count - 1 - newIndex; i++)
					{
						StepBackward();
					}
				}
				else
				{
					int steps = newIndex - currentIndex;
					for (int i = 0; i < steps; i++)
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
			currentIndex++;
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
			currentIndex--;
			currentElement = currentElement->previousElement;
		}
		return true;
	}

#if false
	/// <summary>
	/// Pushes data to the list, before the active element
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
			if (currentIndex == 0)
			{
				LinkedListNode<T>* n = new LinkedListNode<T>(data);
				if (n != nullptr)
				{
					currentElement->previousElement = n;
					n->nextElement = currentElement;

					firstElement = n;

					count++;
					currentIndex++;

					return true;
				}
				else return false;
			}
			else
			{
				LinkedListNode<T>* n = new LinkedListNode<T>(data);
				if (n != nullptr)
				{
					n->nextElement = currentElement;
					n->previousElement = currentElement->previousElement;

					n->previousElement->nextElement = n;
					n->nextElement->previousElement = n;

					count++;
					currentIndex++;

					return true;
				}
				else return false;
			}
		}
	}

#endif // obsolete content

	/// <summary>
	/// Pushes data before the current element and remains positioned on the old one
	/// </summary>
	/// <param name="data">Data to be stored</param>
	/// <returns>Whether the push was sucessful</returns>
	bool PushBefore(T data)
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

		if (currentIndex == 0)
		{
			currentIndex -= 1;
			return PushFirst(data);
		}
		else
		{
			LinkedListNode<T>* n = new LinkedListNode<T>(data);
			if (n != nullptr)
			{
				n->nextElement = currentElement;
				n->previousElement = currentElement->previousElement;

				currentElement->previousElement->nextElement = n;
				currentElement->previousElement = n;

				count++;

				return true;
			}


			else return false;
		}
	}

	/// <summary>
	/// Pushes data after the current element and positions on the new element
	/// </summary>
	/// <param name="data">Data to be stored</param>
	/// <returns>Whether the push was sucessful</returns>
	bool PushAfter(T data)
	{
		if (currentIndex == count - 1 || count == 0)
		{
			currentIndex++;
			return PushLast(data);
		}
		else
		{
			LinkedListNode<T>* n = new LinkedListNode<T>(data);
			if (n != nullptr)
			{
				n->previousElement = currentElement;
				n->nextElement = currentElement->nextElement;

				currentElement->nextElement->previousElement = n;
				currentElement->nextElement = n;

				currentIndex++;
				count++;

				return true;
			}


			else return false;
		}
	}


	/// <summary>
	/// Pushes data to the head of the list
	/// </summary>
	/// <param name="data">Data to be stored</param>
	/// <returns>Whether the push was sucessful</returns>
	bool PushFirst(T data)
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
			LinkedListNode<T>* n = new LinkedListNode<T>(data);
			if (n != nullptr)
			{
				n->nextElement = firstElement;
				firstElement->previousElement = n;

				firstElement = n;

				count++;
				currentIndex++;
			}
			else return false;
		}
	}

	/// <summary>
	/// Pushes data to the tail of the list
	/// </summary>
	/// <param name="data">Data to be stored</param>
	/// <returns>Whether the push was sucessful</returns>
	bool PushLast(T data)
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
	}

	/// <summary>
	/// Pushes data to the specified index, moving the rest of the list forward
	/// </summary>
	/// <param name="index">The index of the new element</param>
	/// <param name="data">Data to be stored</param>
	/// <returns>Whether the push was sucessful</returns>
	bool PushAt(int index, T data)
	{
		int revert = currentIndex;
		SeekToIndex(index);
		bool tmp = PushAfter(data);
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
		if (index < revert)
		{
			revert--;
		}
		SeekToIndex(index);
		if (index == 0) // first element
		{
			currentElement = currentElement->nextElement;
			delete (firstElement);
			firstElement = currentElement;
			currentElement->previousElement = nullptr;
		}
		else if (index == count - 1) // last element
		{
			currentElement = currentElement->previousElement;
			delete lastElement;
			lastElement = currentElement;
			currentElement->nextElement = nullptr;
			currentIndex--;
		}
		else // Any in between
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

	/// <summary>
	/// Swaps two elements' stored data
	/// </summary>
	/// <param name="leftIndex">The first element of swap</param>
	/// <param name="rightIndex">The second element of swap</param>
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
		currentIndex = 0;
		count = 0;
	}

	~DLinkedList()
	{
		Empty();
	}

private:
	unsigned int currentIndex;
	unsigned int count;

};
// TODO: Improve
// TODO: Expand
// TODO: Intensive and extensive testing


/// <summary>
/// Delegate action, containing the pointer to a function and other information
/// </summary>
/// <typeparam name="Return">Type of the function (void, int, char...)</typeparam>
/// <typeparam name="...Params">Flexible number of function parameter types</typeparam>
template<class Return, class... Params>
class DDelegateAction
{
public:
	DDelegateAction()
	{
		ID = 0;
		timesCalled = 0;
	}
	DDelegateAction(int ID)
	{
		this->ID = ID;
		timesCalled = 0;
	}
	DDelegateAction(int ID, Return(*function)(Params...))
	{
		this->functionPointer = function;
		this->ID = ID;
		timesCalled = 0;
	}
	DDelegateAction(Return(*function)(Params...))
	{
		this->functionPointer = function;
		this->ID = 0;
		timesCalled = 0;
	}
	~DDelegateAction()
	{

	}

	Return Fire(Params... p)
	{
		timesCalled++;
		return functionPointer(p...);
	}

	Return(*functionPointer)(Params...);
	int ID;
	int timesCalled;
	/*Anything more?*/

private:
};


/// <summary>
/// Delegate event handler
/// </summary>
/// <typeparam name="Return">Type of the function (void, int, char...)</typeparam>
/// <typeparam name="...Params">Flexible number of function parameter types</typeparam>
template <class Return, class... Params>
class DDelegate
{
public:

	DDelegate()
	{
		_CrtDumpMemoryLeaks();
		actionList = new DLinkedList<DDelegateAction<Return, Params...>*>();
		_CrtDumpMemoryLeaks();
	}
	~DDelegate()
	{
		_CrtDumpMemoryLeaks();
		delete actionList;
		_CrtDumpMemoryLeaks();

	}

	/// <summary>
	/// Fires every function in subscribe order but deletes their returned value
	/// </summary>
	/// <param name="...p">Parameters for the functions to use</param>
	void FireAllWithoutReturns(Params... p)
	{
		int length = actionList->Count();
		Return* retArray = new Return[length];
		for (int i = 0; i < length; i++)
		{
			retArray[i] = actionList->GetDataAt(i)->Fire(p...);
		}
		delete retArray;
	}

	/// <summary>
	/// Fires every function in subscribe order
	/// </summary>
	/// <param name="...p">Parameters for the functions to use</param>
	/// <returns>An array of the returned value of the functions</returns>
	Return* FireAll(Params... p)
	{
		if (typeid(Return) == typeid(void))
		{
			int length = actionList->Count();
			for (int i = 0; i < length; i++)
			{
				actionList->GetDataAt(i)->Fire(p...);
			}
			return NULL;
		}
		else
		{
			int length = actionList->Count();
			Return* retArray = new Return[length];
			for (int i = 0; i < length; i++)
			{
				retArray[i] = actionList->GetDataAt(i)->Fire(p...);
			}
			return retArray;
		}

	}

	/// <summary>
	/// Fires every function in subscribe order
	/// </summary>
	/// <param name="...p">An array of parameters for the functions to use</param>
	/// <returns>An array of the returned value of the functions</returns>
	Return* FireAll(Params... p[])
	{
		if (typeid(Return) == typeid(void))
		{
			int length = actionList->Count();
			for (int i = 0; i < length; i++)
			{
				actionList->GetDataAt(i)->Fire(p[i]...);
			}
			return NULL;
		}
		else
		{
			int length = actionList->Count();
			Return* retArray = new Return[length];
			for (int i = 0; i < length; i++)
			{
				retArray[i] = actionList->GetDataAt(i)->Fire(p[i]...);
			}
			return retArray;
		}
	}

	bool UnSubscribe(Return(*function)(Params...)) // TODO
	{
		
	}

	/// <summary>
	/// Subscribes a function to the delegate
	/// </summary>
	/// <param name="function">The pointer to the function</param>
	/// <returns>Whether the subscription was sucessful</returns>
	bool Subscribe(Return(*function)(Params...))
	{
		DDelegateAction<Return, Params...> tmp = new DDelegateAction<Return, Params...>(function);
		if (tmp != nullptr)
		{
			actionList->PushAfter(tmp);
			return true;
		}
		else return false;
	}


	DLinkedList<DDelegateAction<Return, Params...>*>* actionList;



private:
};




bool Test(bool asd, int dsa)
{
	say "Param1: " << asd;
	creturn;
	say "Param2: " << dsa;
	creturn;
	return true;
}


int main()
{
	_CrtDumpMemoryLeaks();
	{

		DDelegate<bool, bool, int>* a = new DDelegate<bool, bool, int>();
		a->Subscribe(&Test);
		a->Subscribe(&Test);
		//a->actionList->PushAfter(new DDelegateAction<bool, bool, int>(&Test));
		bool* tmp;
		bool arg1[] = { true, false };
		int arg2[] = { 0, 42 };
		tmp = a->FireAll(arg1, arg2);
		free(tmp);
		//DLinkedList<int>* asd = new DLinkedList<int>;
		//for (int i = 0; i < 1000; i++)
		//{
		//	asd->PushBefore(i); // (asd->Count() == 0) ? 0 : rand() % asd->Count()
		//}
		//say "full"; 
		//asd->operator[](32)->data;
		//creturn;
		////for (int i = 0; i < asd->Count(); i++)
		////{
		////	asd->SeekToIndex(i);
		////	say asd->currentElement->data;
		////	creturn;
		////}
		//for (int i = 0; i < asd->Count() / 2; i++)
		//{
		//	asd->Swap(i, asd->Count() - 1 - i);
		//}
		//say "reversed";
		//creturn;
		//for (int i = 0; i < asd->Count(); i++)
		//{
		//	asd->SeekToIndex(i);
		//	say asd->currentElement->data;
		//	creturn;
		//}
		//delete asd;
		delete a; // Persze, itt keresem 45 percen keresztül, hogy honnan jön a 8 byte leak
		// aztán delete helyett csak a destruktort hívtam meg...
		// Tanúlság? éjfél elõtt foglalkozzak ilyenekkel
	}
	int leaks = _CrtDumpMemoryLeaks();
	say "Leaks: " << leaks;
}

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
	short i;
	for (i = isNegative; i < str.length(); i++)
	{
		if ((int)str[i] >= 48 && (int)str[i] <= 57)
		{
			retNumber += ((int)str[i] - 48) * pow(10, str.length() - (i + 1));
		}
		else break;
	}
	retNumber = retNumber / (pow(10, str.length()) / pow(10, i));
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
/// <typeparam name="T">Any but string</typeparam>
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
/// <typeparam name="T">Any</typeparam>
/// <param name="arr">Array-like object</param>
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
/// Finds the first index in the array that matches the given search parameter
/// </summary>
/// <typeparam name="T">Any</typeparam>
/// <param name="arr">Array-like object</param>
/// <param name="length">Lenght of the array</param>
/// <param name="searchedElement">The element that needs to be found</param>
/// <returns>The first index of the searched element, otherwise -1</returns>
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
/// Moves array elements left or right the specified amount
/// </summary>
/// <typeparam name="T">Any</typeparam>
/// <param name="arr">Array-like object</param>
/// <param name="length">Length of the array</param>
/// <param name="steps">How much steps should the array be rotated</param>
template<class T> void RotateArray(T* arr, int length, int steps)
{
	bool toRight = steps >= 0;
	steps = steps % length;
	if (steps == 0)
	{
		return;
	}
	else if (toRight)
	{
		for (int i = 0; i < steps; i++)
		{
			int last = arr[length - 1];
			for (int j = length - 2; j >= 0; j--)
			{
				arr[j + 1] = arr[j];
			}
			arr[0] = last;
		}
	}
	else
	{
		steps *= -1;
		for (int i = 0; i < steps; i++)
		{
			int first = arr[0];
			for (int j = 0; j < length - 1; j++)
			{
				arr[j] = arr[j + 1];
			}
			arr[length - 1] = first;
		}
	}
	return;
}

/// <summary>
/// Shifts elements in the array the specified amount and fills in the empty space
/// </summary>
/// <typeparam name="T">Any</typeparam>
/// <param name="arr">Array-like object</param>
/// <param name="length">Length of the array</param>
/// <param name="steps">How much steps should the array be rotated</param>
/// <param name="filler">The data what fills in the new space</param>
template<class T> void ShiftArray(T* arr, int length, int steps, T filler)
{
	bool toRight = steps >= 0;
	steps = steps % length;
	if (steps == 0)
	{
		return;
	}
	else if (toRight)
	{
		for (int i = length - 1; i >= steps; i--)
		{
			arr[i] = arr[i - steps];
		}
		for (int i = 0; i < steps; i++)
		{
			arr[i] = filler;
		}
	}
	else
	{
		steps *= -1;
		for (int i = 0; i < length - steps; i++)
		{
			arr[i] = arr[i + steps];
		}
		for (int i = length - steps; i < length; i++)
		{
			arr[i] = filler;
		}
	}
	return;
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