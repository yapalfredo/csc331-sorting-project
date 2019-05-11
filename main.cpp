#include <iostream>
#include <time.h>
using namespace std; 

//global variables needed for 
//showing the numbers of swaps
//and compares
int swapCounter;
int compareCounter;
//----------------------------------------------------------

void Swap(int *a, int *b)  
{  
    int temp = *a;  
    *a = *b;  
    *b = temp;  
    swapCounter++;
}  

//-------------------------------------------------
//-------------------------------------------------
// Selection Sort implementation  
void SelectionSort(int _Array[], int size)  
{  
  swapCounter=0;
  compareCounter=0;
  int minimumIndex, x, y;  
  // Move the boundary of unsorted array
  // one index at a time
  for (x = 0; x < size-1; x++)  
  {  
    // locate the smallest value in the
    //unsorted array
    minimumIndex = x;  
    for (y = x+1; y < size; y++)  
    {
      if (_Array[y] < _Array[minimumIndex])  
        {
          minimumIndex = y;  
          compareCounter++;
        }              
    }       
    // Swap the found minimum element with the first element  
    Swap(&_Array[minimumIndex], &_Array[x]);  
  }  
}  
//-------------------------------------------------

//-------------------------------------------------
//-------------------------------------------------  
// Insertion Sort Implementation
void InsertionSort(int _Array[], int size)  
{  
  swapCounter=0;
  compareCounter=0;
  int x, y, key; 
  for (x = 1; x < size; x++) 
  {  
    key = _Array[x];  
    y = x - 1;  
    // Move elements of arr[0.....x-1] if  
    // greater than key, to an index forward  
    // of current index 
    while (y >= 0 && _Array[y] > key) 
    {  
      Swap(&_Array[y+1], &_Array[y]);
      y = y - 1;  
      compareCounter++;
    }  
    Swap(&_Array[y+1], &key); 
  }  
}
//-------------------------------------------------

//-------------------------------------------------
//-------------------------------------------------
// Heap Sort implementation  
void Heapify(int _Array[], int size, int index) 
{ 
	int largest = index;
	int left = 2*index + 1;
	int right = 2*index + 2;
  // Do this if the left child
	// is greater than root 
	if (left < size && _Array[left] > _Array[largest]) 
  {
    largest = left; 
    compareCounter++;
  }		
  // Do this if the right child
	// is greater than the largest 
	if (right < size && _Array[right] > _Array[largest]) 
  {
    largest = right; 
    compareCounter++;
  }		
	// Do this if largest
  // is not the root
	if (largest != index) 
	{ 
    compareCounter++;
		Swap(&_Array[index], &_Array[largest]);   
    // Recursion call 
		Heapify(_Array, size, largest); 
	} 
} 
void HeapSort(int _Array[], int size) 
{ 
  swapCounter=0;
  compareCounter=0;
	// Build the heap
	for (int i = size / 2 - 1; i >= 0; i--) 
  {
    Heapify(_Array, size, i); 
  }
	// Extract the element from the heap
  // one at a time
	for (int i=size-1; i>=0; i--) 
	{ 
		// swap current to end
		Swap(&_Array[0], &_Array[i]); 
		// call on the reduced heap
		Heapify(_Array, i, 0); 
	} 
} 
//-------------------------------------------------

//-------------------------------------------------
//-------------------------------------------------
// Merge Sort Implementation
void Merge(int _Array[], int left, int middle, int right) 
{ 	
  // Merges two subarrays:
  // The first subarray is _Array[left..middle] 
  // and the second subarray is _Array[middle+1..right] 
	int h1 = middle - left + 1; 
	int h2 = right - middle; 
  int a, b, c; 
	// Temporary arrays
	int Left[h1], Right[h2]; 
	// populate values to temporary arrays
	for (a = 0; a < h1; a++)
  {
    Left[a] = _Array[left + a]; 
  } 		
	for (b = 0; b < h2; b++) 
  {
    Right[b] = _Array[middle + 1+ b]; 
  }		
	// Merge the temporary arrays back into _Array[left..right]
	a = 0; //first subarray index 
	b = 0; //second subarray index
	c = left; //merged subarray index
	while (a < h1 && b < h2) 
	{ 
		if (Left[a] <= Right[b]) 
		{ 
			_Array[c] = Left[a]; 
			a++; 
      compareCounter++;
		} 
		else
		{ 
			_Array[c] = Right[b]; 
			b++; 
      compareCounter++;
		} 
		c++; 
	} 
	//Copy the remaining elements of Left[] 
	//if there are any 
	while (a < h1) 
	{ 
		_Array[c] = Left[a]; 
		a++; 
		c++; 
	}
	// Copy the remaining elements of Right[] 
	//  if there are any
	while (b < h2) 
	{ 
		_Array[c] = Right[b]; 
		b++; 
		c++; 
	} 
} 

void MergeSort(int _Array[], int left, int right) 
{ 
	if (left < right) 
	{ 
    compareCounter++;
		//This avoids oveflow
		int middle = left+(right-left)/2; 
		// Sort first and second halves 
		MergeSort(_Array, left, middle); 
		MergeSort(_Array, middle+1, right); 
		Merge(_Array, left, middle, right); 
	} 
} 
//-------------------------------------------------

//-------------------------------------------------
//-------------------------------------------------
// Quick Sort Implementation
int Partition(int _Array[], int low, int high) 
{ 
  //pivot 
	int p = _Array[high];
  //smaller element index 
	int a = (low - 1); 
	for (int i = low; i <= high-1; i++) 
	{ 
		//If current element is smaller 
		//than or equal to pivot 
		if (_Array[i] <= p) 
		{ 
      compareCounter++;
      //increment the index
      //of smaller element 
			a++;
			Swap(&_Array[a], &_Array[i]); 
		} 
	} 
	Swap(&_Array[a + 1], &_Array[high]); 
	return (a + 1); 
} 

void QuickSort(int _Array[], int low, int high) 
{ 
  //low is the starting index, 
  //high is the ending index 
	if (low < high) 
	{ 
    compareCounter++;
		int partioningIndex = Partition(_Array, low, high); 

		// One by one sort the elements before 
		// partition and after partition 
		QuickSort(_Array, low, partioningIndex - 1); 
		QuickSort(_Array, partioningIndex + 1, high); 
	} 
} 
//-------------------------------------------------
//-------------------------------------------------

const int FIRST_SIZE = 100; //size of the first array
const int SECOND_SIZE = 1000; //size of the second array
//---------------------------------------
//Headers for All Option Functions
//---------------------------------------
void FirstOption(int[], int[]);
void SecondOption(int[],int[]);
void ThirdOption(int[], int[]);

//This gets called to show all results
//for all algorithms
void AlgorithmsResult(int[], int[]);

//This will just create a temporary copy of
//the original array everytime an algorithm
//is called to perform its operation
int * MakeATempCopyArray(int[], int);

//For Unit Testing
void PrintArray(int[], int);
//---------------------------------------
//---------------------------------------

int main()  
{  
  srand(time(NULL));
  int firstArray[FIRST_SIZE]; //array with size of 100
  int secondArray[SECOND_SIZE]; //array with size of 1000
  
  short int option;
  do
  {
    cout << "----------------------------------------------------" << endl;
    cout << "PLEASE SELECT FROM THE OPTIONS BELOW:" << endl;
    cout << "1 - Completely Random" << endl;
    cout << "2 - 90% sorted in ascending order and 10% random" << endl;
    cout << "3 - Almost the same as 2 but reversed" << endl;
    cout << "5 - To close the program" << endl;

    cin >> option;
    cout << "----------------------------------------------------" << endl << endl;
    switch (option)
    {
      case 1: 
        FirstOption(firstArray, secondArray);
        break;
      case 2:
        SecondOption(firstArray, secondArray);
        break;
      case 3:
        ThirdOption(firstArray, secondArray);
        break;
      default:
        break;
    }
  }while (option != 5);

  return 0;  
}  

void FirstOption(int firstArr[], int secondArr[])
{
  for (int i = 0; i < FIRST_SIZE; i++)
    firstArr[i] = (rand() % (100 + 1));

  for (int i = 0; i < SECOND_SIZE; i++)
    secondArr[i] = (rand() % (100 + 1));  

  AlgorithmsResult(firstArr, secondArr);
}

void SecondOption(int firstArr[], int secondArr[])
{
  int i;
//------------------------------------------------
// SMALLER ARRAY (size 100)
//------------------------------------------------
  //Populate the first 90% in Ascending order
  for (i=0 ; i < (FIRST_SIZE*90)/100 ;i++)
    firstArr[i] = i+1;
  //Populate the remaining 10% in random
  for(int j = 0; j < (FIRST_SIZE*10)/100; j++)
    firstArr[i + j] = (rand() % (100 + 1)) ;
//------------------------------------------------
// BIGGER ARRAY (size 1000)
//------------------------------------------------
 //Populate the first 90% in Ascending order
  for (i = 0; i < (SECOND_SIZE*90)/100; i++)
  {
    if (i >= 100)
      secondArr[i] = (i/10)+1;
    else
      secondArr[i] = i + 1;
  }
  //Populate the remaining 10% in random
  for(int j = 0; j < (SECOND_SIZE*10)/100; j++)
    secondArr[i + j] = (rand() % (100 + 1));

  AlgorithmsResult(firstArr, secondArr);
}

void ThirdOption(int firstArr[], int secondArr[])
{
  int i;
//------------------------------------------------
// SMALLER ARRAY (size 100)
//------------------------------------------------
  //Populate the first 10% in random
  for(i = 0; i < (FIRST_SIZE*10)/100; i++)
    firstArr[i] = (rand() % (100 + 1)) ;
  //Populate the remaining 90% in Ascending order
  for (int j = 0; j < (FIRST_SIZE*90)/100; j++)
    firstArr[i + j] = (i+j+1);
//------------------------------------------------
// BIGGER ARRAY (size 1000)
//------------------------------------------------
  //Populate the first 10% in random
  for(i = 0; i < (SECOND_SIZE*10)/100; i++)
    secondArr[i] = (rand() % (100 + 1)) ;
  //Populate the remaining 90% in Ascending order
  for (int j = 0; j < (SECOND_SIZE*90)/100; j++)
  {
    secondArr[i + j] = ((i + j)/10) + 1;
  }
    
  AlgorithmsResult(firstArr, secondArr);
}

void AlgorithmsResult(int firstArr[], int secondArr[])
{
  cout << "-----SELECTION SORT RESULT-----" <<endl;
  SelectionSort(MakeATempCopyArray(firstArr,FIRST_SIZE),FIRST_SIZE);
  cout << "ARRAY SIZE: " << FIRST_SIZE << endl;
  cout <<"Total number of compare: " << compareCounter << endl;
  cout <<"Total number of swaps: " << swapCounter << endl;
  cout <<"ARRAY SIZE: " << SECOND_SIZE << endl;
  SelectionSort(MakeATempCopyArray(secondArr,SECOND_SIZE), SECOND_SIZE);
  cout <<"Total number of compare: " << compareCounter << endl;
  cout <<"Total number of swaps: " << swapCounter << endl;
  cout << "-----END OF SELECTION SORT-----" << endl << endl;

  cout << "-----INSERTION SORT RESULT-----" <<endl;
  InsertionSort(MakeATempCopyArray(firstArr,FIRST_SIZE),FIRST_SIZE);
  cout << "ARRAY SIZE: " << FIRST_SIZE << endl;
  cout <<"Total number of compare: " << compareCounter << endl;
  cout <<"Total number of swaps: " << swapCounter << endl;
  cout <<"ARRAY SIZE: " << SECOND_SIZE << endl;
  InsertionSort(MakeATempCopyArray(secondArr,SECOND_SIZE), SECOND_SIZE);
  cout <<"Total number of compare: " << compareCounter << endl;
  cout <<"Total number of swaps: " << swapCounter << endl;
  cout << "-----END OF INSERTION SORT-----" << endl << endl;

  cout << "-----HEAP SORT RESULT-----" <<endl;
  HeapSort(MakeATempCopyArray(firstArr,FIRST_SIZE),FIRST_SIZE);
  cout << "ARRAY SIZE: " << FIRST_SIZE << endl;
  cout <<"Total number of compare: " << compareCounter << endl;
  cout <<"Total number of swaps: " << swapCounter << endl;
  cout <<"ARRAY SIZE: " << SECOND_SIZE << endl;
  HeapSort(MakeATempCopyArray(secondArr,SECOND_SIZE), SECOND_SIZE);
  cout <<"Total number of compare: " << compareCounter << endl;
  cout <<"Total number of swaps: " << swapCounter << endl;
  cout << "-----END OF HEAP SORT-----" << endl << endl;

  cout << "-----MERGE SORT RESULT-----" <<endl;
  compareCounter=0;
  MergeSort(MakeATempCopyArray(firstArr,FIRST_SIZE), 0, FIRST_SIZE-1);
  cout << "ARRAY SIZE: " << FIRST_SIZE << endl;
  cout <<"Total number of compare: " << compareCounter << endl;
  cout <<"ARRAY SIZE: " << SECOND_SIZE << endl;
  compareCounter=0;
  MergeSort(MakeATempCopyArray(secondArr,SECOND_SIZE), 0, SECOND_SIZE-1);
  cout <<"Total number of compare: " << compareCounter << endl;
  cout << "-----END OF MERGE SORT-----" << endl << endl;

  cout << "-----QUICK SORT RESULT-----" <<endl;
  compareCounter = 0;
  swapCounter = 0;
  QuickSort(MakeATempCopyArray(firstArr,FIRST_SIZE), 0, FIRST_SIZE-1);
  cout << "ARRAY SIZE: " << FIRST_SIZE << endl;
  cout <<"Total number of compare: " << compareCounter << endl;
  cout <<"Total number of swaps: " << swapCounter << endl;
  cout <<"ARRAY SIZE: " << SECOND_SIZE << endl;
  compareCounter = 0;
  swapCounter = 0;
  QuickSort(MakeATempCopyArray(secondArr,SECOND_SIZE), 0, SECOND_SIZE-1);
  cout <<"Total number of compare: " << compareCounter << endl;
  cout <<"Total number of swaps: " << swapCounter << endl;
  cout << "-----END OF QUICK SORT-----" << endl << endl;
}

int * MakeATempCopyArray(int _Arr[], int size)
{
  int *result = new int[size];
  for (int i = 0; i < size; i++)
  {
    result[i] = _Arr[i];
  }
  return result;
  delete [] result;
}

void PrintArray(int _Arr[], int size)
{
  cout <<"Array Values" << endl;
  for (int i = 0; i < size; i++)
  {
    cout << _Arr[i] << endl;
  }
}
