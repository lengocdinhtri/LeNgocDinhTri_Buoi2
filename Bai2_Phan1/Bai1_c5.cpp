#include <stdio.h>
#define SIZE 15

int BinarySearch(int arr[], int size, int x) {
	int left = 0;
	int right = size - 1;

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == x) {
			return mid;  // Trả về vị trí của x trong mảng
		}
		if (arr[mid] < x) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	return -1;  // Trả về -1 nếu không tìm thấy
}

int main() {
	int arr[SIZE] = { 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28 };
	int x = 14;
	int ketqua = BinarySearch(arr, SIZE, x);
	if (ketqua != -1) {
		printf("Tim thay %d tai vi tri %d\n", x, ketqua);
	}
	else {
		printf("Khong tim thay gia tri do %d\n", x);
	}
	return 0;
}
