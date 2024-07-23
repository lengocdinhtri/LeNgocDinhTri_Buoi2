#include <stdio.h>
#define SIZE 15

void Taomangchan(int arr[], int size) {
	int num = 0;
	for (int i = 0; i < size; i++) {
		arr[i] = num;
		num += 2;
	}
}

int main() {
	int arr[SIZE];
	Taomangchan(arr, SIZE);

	printf("Mang so chan: ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
