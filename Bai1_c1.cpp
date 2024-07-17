#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

void TaoMangNgauNhien(int arr[], int size) {
	srand(time(0));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 100;  // Tạo số ngẫu nhiên từ 0 đến 99
	}
}

int main() {
	int arr[SIZE];
	TaoMangNgauNhien(arr, SIZE);

	printf("Mang ngau nhien: ");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}
