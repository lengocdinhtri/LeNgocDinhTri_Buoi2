#include <stdio.h>
#define SIZE 15

void InterchangeSort(int arr[], int size, int tang) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if ((tang && arr[i] > arr[j]) || (!tang && arr[i] < arr[j])) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main() {
	int arr[SIZE] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28 };
	int tang = 1;  // 1 để sắp xếp tăng dần, 0 để sắp xếp giảm dần

	InterchangeSort(arr, SIZE, tang);

	printf("Mang da sap xep theo kieu InterchangeSort: ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
