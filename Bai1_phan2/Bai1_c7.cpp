#include <stdio.h>
#define SIZE 15

void Swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
			Swap(&arr[i], &arr[j]);
		}
	}
	Swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void QuickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = Partition(arr, low, high);
		QuickSort(arr, low, pi - 1);
		QuickSort(arr, pi + 1, high);
	}
}

int main() {
	int arr[SIZE] = { 100, 90, 80, 70, 60, 50, 40, 30, 20, 10, 8, 6, 4, 2, 0 };
	QuickSort(arr, 0, SIZE - 1);

	printf("Mang da sap xep: ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}
