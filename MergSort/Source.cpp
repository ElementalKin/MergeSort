#include <iostream>
// merge
// This function accepts a range of elements to sort. Used as a part of the
// merge sort function to merge subsections of the array.
//
//   arr is the array being sorted by the merge operation
//   p is the first index to start merging and sorting from
//   q is the index between p and r
//   r is the last index to merge and sort through
//
//   indices p, q, r, are guaranteed to have these values: p ≤ q < r
//     p is less than or equal to q
//     q is less than r
void Merge(int * arr, size_t p, size_t q, size_t r)
{
	int i = 0;
	int j = 0;
	int leftEnd = q - p + 1;
	int rightEnd = r - q;

	// create an array that is size: leftEnd
	int* leftArray = new int[leftEnd];
	// create an array that is size: rightEnd
	int* rightArray = new int[rightEnd];

	// copy left elements into leftArray
	for (i = 0; i <leftEnd; i++) { leftArray[i] = arr[p + i]; }
	// copy right elements into rightArray
	for (j = 0; j < rightEnd; j++) { rightArray[j] = arr[q + j + 1]; }
	
	i = 0;
	j = 0;

	// for all values from p to r = k
	for(int k = p; k <=r; k++)
	{
		// if (j >= rightEnd) OR
	    //    (i < leftEnd AND leftArray[i] <= rightArray[j]) then
		if (j >= rightEnd || (i < leftEnd && leftArray[i] <= rightArray[j]))
		{
	    // set A[k] to the value of leftArray[i]
			arr[k] = leftArray[i];
	    // increase i by one
			i++;
		}
		// else
		else
		{
			// set A[k] = R[j]
			arr[k] = rightArray[j];
			// increase j by one
			j++;
		}
	}	
	delete[] leftArray;
	delete[] rightArray;
}

// merge sort
//   arr is the array being sorted
//   p is the first index to start sorting from
//   r is the last index to start sorting from
void MergeSort(int * arr, size_t p, size_t r)
{
	if (p < r)
	{
		std::cout << "" << std::endl;
		for (int i = 0; i < r; i++) { std::cout << arr[i]; }
		int q = (p + r) / 2;
		MergeSort(arr, p, q);
		MergeSort(arr, q + 1, r);
		Merge(arr, p, q, r);
	}
}

int main()
{
	bool EndGame = true;
	char leave;
	int arraySize = 0;
	while(EndGame)
	{
		arraySize = 7;
		std::cout << "Please enter how larg of an array you want to be sorted." << std::endl;
		std::cin >> arraySize;
		int* arr = new int[arraySize];
		std::cout << "please input the numbers to be sorted, any letters you input will be counted as 0." << std::endl;
		for(int i = 0; i < arraySize;i++){std::cin >> arr[i];}
		MergeSort(arr, 0, arraySize-1);
		std::cout << "" << std::endl;
		for (int i = 0; i < arraySize; i++) { std::cout << arr[i]; }
		std::cout << "" << std::endl;
		std::cout << "Do you want to exit the program [Y], if no then enter anything but y." << std::endl;
		std::cin >> leave;
		if (leave == 'Y' || 'y') { EndGame = false;}
	}
	return 0;
}