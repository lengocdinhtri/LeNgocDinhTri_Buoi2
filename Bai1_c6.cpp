#include <stdio.h>
#define SIZE 15

void SelectionSort(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int min_idx = i;
		for (int j = i + 1; j < size; j++) {
			if (arr[j] < arr[min_idx]) {
				min_idx = j;
			}
		}
		int temp = arr[min_idx];
		arr[min_idx] = arr[i];
		arr[i] = temp;
	}
}

int main() {
	int arr[SIZE] = { 30, 32, 24, 22, 20, 18, 16, 50, 12, 10, 8, 6, 4, 2, 40 };
	SelectionSort(arr, SIZE);

	printf("Mang da sap xep theo kieu SelectionSort: ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}
