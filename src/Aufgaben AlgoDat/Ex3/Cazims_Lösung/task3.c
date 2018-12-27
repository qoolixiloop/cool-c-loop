// Cazim Hysi 14-731-939

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int parent(int i)
{
	return i/2;
}

int left(int i)
{
	return (i+1)*2-1;
}

int right(int i)
{
	return (i+1)*2;
}

void heapify(int *A, int i, size_t s)
{
	int m = i;
	int l = left(i);
	int r = right(i);
	
	if ((l <= s-1) && (A[l] > A[m]))
		m = l;
	if ((r <= s-1) && (A[r] > A[m]))
		m = r;
	if (i != m) {
		int temp = A[m];
		A[m] = A[i];
		A[i] = temp;

		heapify(A,m,s);
	}
}

void buildMaxHeap(int *A, size_t n)
{
	int last_element = n-1;
	for (int i = last_element/2; i >= 0; i--)
	{
		heapify(A, i, last_element);
	}
}

void heapsort(int *A, size_t n)
{
	int s = n;
	buildMaxHeap(A, n);

	for (int i = n-1; i >= 1; i--)
	{
		int temp = A[i];
		A[i] = A[0];
		A[0] = temp;
		s = s - 1;
		heapify(A, 0, s);
	}
}

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
	if ((choice == 1) && ((high-low) <= 1))
			return;
	if (low < high) {
		int m = partitionHoare(A, low, high, choice);
		quicksort(A, low, m-1, choice);
		quicksort(A, m, high, choice);
	}
}

void bubblesort(int *a, size_t size)
{
	if(size < 2)
		return;
	for(int i = size; i > 1; i--)
	{
		for(int j = 1; j < i; j++)
		{
			if(a[j] < a[j-1])
			{
				int tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
			}
		}
	}
}

void readFile(char filename[], int output[], int *n) 
{
	FILE *f;
	int i;
	f = fopen(filename, "r");
	i = 0;

	while (fscanf(f, "%d", &output[i]) == 1)
		i++;

	*n=i-1;
	fclose(f);
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

int main(int argc, const char *argv[])
{
	clock_t start;
	clock_t end;
	float seconds;

	int algo;
	int file;

	char *fname;
	int read_ints;

	printf("Please type algorithm and file.\n");
	printf("Algo: 0 -- bubblesort 1 -- heapsort 2 -- quicksort (simple) 3 -- quicksort\n");
	printf("File: 0 -- random 1 -- ordered 2 -- reverse\n");
	printf("Example: 2 0\n");
	printf(">>> ");
	scanf("%d %d", &algo, &file);

	switch (file) {
		case 0: fname = "integer_datasets/random.txt";
			break;
		case 1: fname = "integer_datasets/ordered.txt";
			break;
		case 2: fname = "integer_datasets/inverse.txt";
			break;
	}

	int len_a = 120000;
	int *A = calloc(sizeof(int), len_a);
	readFile(fname, A, &read_ints);

	start = clock();
	switch (algo) {
		case 0: bubblesort(A, len_a);
			break;
		case 1: heapsort(A, len_a);
			break;
		case 2: quicksort(A, 0, len_a-1, 0);
			break;
		case 3: quicksort(A, 0, len_a-1, 1);
			break;
	}
	end = clock();
	seconds = (float)(end - start) / CLOCKS_PER_SEC;
	printf("secs: %f\n", seconds);
}
