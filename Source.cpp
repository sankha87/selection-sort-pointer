// C program for implementation of selection sort 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <conio.h>
#include <stdlib.h>

void selectionSort(int *arr, int n)
{
	int i, j, min_idx;

	for (i = 0; i < n - 1; i++)				// One by one move boundary of unsorted subarray 
	{
		min_idx = i;						// Find the minimum element in unsorted array 
		for (j = i + 1; j < n; j++)
		{
			if (*(arr+j) < *(arr+min_idx))
				min_idx = j;
		}

		int temp = *(arr + min_idx);
		*(arr + min_idx) = *(arr + i);
		*(arr + i) = temp;
	}
}

void printArray(int *arr, int size)		// Function to print an array 
{
	for (int i = 0; i < size; i++)
		printf("%d ", *(arr+i));
	printf("\n");
}

int main()
{
	int n, *arr;
	printf("How many numbers : ");
	scanf("%d", &n);
	arr = (int *)malloc(n*sizeof(int));
	printf("\nEnter elements : \n");
	for(int i=0; i<n; i++)
		scanf("%d", arr+i);

	selectionSort(arr, n);
	printf("Sorted array: \n");
	printArray(arr, n);
	_getch();
}

// Worst, Average, Best case Time Complexity = O(n^2)
// Space Complexity = O(1)