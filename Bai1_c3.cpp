#include <stdio.h>
#define SIZE 15

int LinearSearch(int arr[], int size, int x) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == x) {
			return i;  // Trả về vị trí của x trong mảng
		}
	}
	return -1;  // Trả về -1 nếu không tìm thấy
}

int main() {
	int arr[SIZE] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28 };
	int x = 18;
	int Ketqua = LinearSearch(arr, SIZE, x);

	if (Ketqua != -1) {
		printf("Tim thay %d tai vi tri %d\n", x, Ketqua);
	}
	else {
		printf("Khong tim thay so can tim %d\n", x);
	}
	return 0;
}
