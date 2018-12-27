// Cazim Hysi 14-731-939

#include <stdio.h>
#include <math.h>

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
	for (int i = n/2; i >= 0; i--)
	{
		heapify(A, i, n);
	}
}

void printHeapRec(int *heap, int idx, size_t n)
{
	if (left(idx) > n-1) {
		return;
	} else if (left(idx) == n-1) {
		printf("%d -- %d\n", heap[idx], heap[left(idx)]);
		return;
	} else {
		printf("%d -- %d\n", heap[idx], heap[left(idx)]);
		printf("%d -- %d\n", heap[idx], heap[right(idx)]);
		printHeapRec(heap, left(idx), n);
		printHeapRec(heap, right(idx), n);
	}
}

void printHeap(int *heap, size_t n)
{
	printf("graph g {\n");
	printHeapRec(heap, 0, n);
	printf("}\n");
}

int read_array(int *arr)
{
	int i = 0;
	while(scanf("%d", &arr[i]) == 1)
		i++;
	scanf("%*s");
	return i;
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

void heapSort(int *A, size_t n)
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

int main(int argc, const char *argv[])
{
	int len_a;
	int A[100] = {0};

	printf("Type elements of A separated by spaces (type 'end' to stop): ");
	len_a = read_array(A);

	buildMaxHeap(A, len_a);
	printf("Array as max heap:\n");
	printHeap(A, len_a);

	heapSort(A, len_a);
	printf("Array after heapsort:\n");
	printArray(A, len_a);
}
