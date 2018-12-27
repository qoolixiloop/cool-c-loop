// Cazim Hysi 14-731-939

#include <stdio.h>
#include <math.h>

void swap(int *A, int i, int j)
{
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

int median(int *A, int low, int high)
{
    int mid = (low+high)/2;
    if (A[low] < A[mid])
    {
        if(A[low] >= A[high])
            return A[low];
        else if(A[mid] < A[high])
            return A[mid];
    }
    else
    {
        if(A[low] < A[high])
            return A[low];
        else if(A[mid] >= A[high])
            return A[mid];
    }
    return A[high];
}

int partitionHoare(int *A, int low, int high, int choice)
{
	int pivot;
	int i = low-1;
	int j = high+1;

	if (choice == 1)
	{
		pivot = median(A, low, high);
	} else {
		pivot = A[high];
	}
	while (1)
	{
		do j--; while (A[j] > pivot);
		do i++; while (A[i] < pivot);
		if (i<j) {
			swap(A, i, j);
		} else {
			return i;
		}
	}
}

void quicksort(int *A, int low, int high, int choice)
{
	if (((choice == 1)) && ((high-low) <= 1))
			return;
	if (low < high) {
		int m = partitionHoare(A, low, high, choice);
		quicksort(A, low, m-1, choice);
		quicksort(A, m, high, choice);
	}
}

void printArray(int *A, size_t n)
{
	printf("[ ");
	for (int i = 0; i < n-1; i++)
	{
		printf("%d, ", A[i]);
	}
	printf("%d ]\n", A[n-1]);
}

int read_array(int *arr)
{
	int i = 0;
	while(scanf("%d", &arr[i]) == 1)
		i++;
	scanf("%*s");
	return i;
}

int main(int argc, const char *argv[])
{
	
	int len_a;
	int choice;
	int A[100] = {0};

	printf("Type elements of A separated by spaces (type 'end' to stop): ");
	len_a = read_array(A);

	printf("Type pivoting mode (0: end of array 1: median): ");
	scanf("%d", &choice);

	quicksort(A, 0, len_a-1, choice);
	printf("Sorted: ");
	printArray(A, len_a);
}
