#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h>

bool LaSoNguyenTo(int n) {
	if (n < 2) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void LietKeSoNguyenTo(int a[], int n) {
	bool coSoNguyenTo = false;
	printf("Cac so nguyen to nho hon %d: ", n);
	for (int i = 0; i < n; i++) {
		if (LaSoNguyenTo(a[i]) && a[i] < n) {
			printf("%d ", a[i]);
			coSoNguyenTo = true;
		}
	}
	if (!coSoNguyenTo) {
		printf("Khong co so nguyen to nho hon %d.\n", n);
	}
	else {
		printf("\n");
	}
}

int ChuSoDauTien(int n) {
	while (n >= 10) {
		n /= 10;
	}
	return n;
}

int TongChuSoDauLe(int a[], int n) {
	int tong = 0;
	for (int i = 0; i < n; i++) {
		if (ChuSoDauTien(a[i]) % 2 != 0) {
			tong += a[i];
		}
	}
	return tong;
}

void LietKeSoLanXuatHien(int a[], int n) {
	int *dem = (int*)malloc(n * sizeof(int));
	memset(dem, 0, n * sizeof(int));

	for (int i = 0; i < n; i++) {
		dem[a[i]]++;
	}

	for (int i = 0; i < n; i++) {
		if (dem[a[i]] != 0) {
			printf("Phan tu %d xuat hien %d lan.\n", a[i], dem[a[i]]);
			dem[a[i]] = 0;
		}
	}
	free(dem);
}

void SapXepChanTangLeGiam(int a[], int n) {
	int *chan = (int*)malloc(n * sizeof(int));
	int *le = (int*)malloc(n * sizeof(int));
	int soChan = 0, soLe = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			chan[soChan++] = a[i];
		}
		else {
			le[soLe++] = a[i];
		}
	}

	for (int i = 0; i < soChan - 1; i++) {
		for (int j = i + 1; j < soChan; j++) {
			if (chan[i] > chan[j]) {
				int temp = chan[i];
				chan[i] = chan[j];
				chan[j] = temp;
			}
		}
	}

	for (int i = 0; i < soLe - 1; i++) {
		for (int j = i + 1; j < soLe; j++) {
			if (le[i] < le[j]) {
				int temp = le[i];
				le[i] = le[j];
				le[j] = temp;
			}
		}
	}

	int k = 0;
	for (int i = 0; i < soLe; i++) {
		a[k++] = le[i];
	}
	for (int i = 0; i < soChan; i++) {
		a[k++] = chan[i];
	}

	free(chan);
	free(le);
}

int TimDayConGiamDaiNhat(int a[], int n) {
	int max = 1, len = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] < a[i - 1]) {
			len++;
		}
		else {
			if (len > max) max = len;
			len = 1;
		}
	}
	if (len > max) max = len;
	return max;
}

int TimSoNhoThuHai(int a[], int n) {
	int min1 = INT_MAX, min2 = INT_MAX;
	for (int i = 0; i < n; i++) {
		if (a[i] < min1) {
			min2 = min1;
			min1 = a[i];
		}
		else if (a[i] < min2 && a[i] != min1) {
			min2 = a[i];
		}
	}
	return (min2 == INT_MAX) ? -1 : min2;
}

bool ChuaChuSo(int n, int x) {
	char strN[10], strX[10];
	sprintf(strN, "%d", n);
	sprintf(strX, "%d", x);

	int lenX = strlen(strX);
	for (int i = 0; i < lenX; i++) {
		if (strchr(strN, strX[i]) == NULL) {
			return false;
		}
	}
	return true;
}

void TimPhanTuChuaChuSoX(int a[], int n, int x) {
	printf("Cac phan tu chua cac chu so cua %d: ", x);
	bool coPhanTu = false;
	for (int i = 0; i < n; i++) {
		if (ChuaChuSo(a[i], x)) {
			printf("%d ", a[i]);
			coPhanTu = true;
		}
	}
	if (!coPhanTu) {
		printf("Khong co phan tu nao.\n");
	}
	else {
		printf("\n");
	}
}

void SapXepChanTangViTriLe(int a[], int n) {
	int *chan = (int*)malloc(n * sizeof(int));
	int soChan = 0;

	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			chan[soChan++] = a[i];
		}
	}

	for (int i = 0; i < soChan - 1; i++) {
		for (int j = i + 1; j < soChan; j++) {
			if (chan[i] > chan[j]) {
				int temp = chan[i];
				chan[i] = chan[j];
				chan[j] = temp;
			}
		}
	}

	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			a[i] = chan[k++];
		}
	}

	free(chan);
}

void SapXepLeTruocChanSau(int a[], int n) {
	int *b = (int*)malloc(n * sizeof(int));
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 != 0) {
			b[k++] = a[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			b[k++] = a[i];
		}
	}
	for (int i = 0; i < n; i++) {
		a[i] = b[i];
	}
	free(b);
}

int main() {
	int n;
	printf("Nhap so phan tu cua mang: ");
	scanf("%d", &n);

	int *a = (int*)malloc(n * sizeof(int));
	printf("Nhap cac phan tu cua mang: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	int luaChon;
	do {
		printf("\nMenu:\n");
		printf("1. Liet ke cac so nguyen to nho hon n\n");
		printf("2. Tinh tong cac phan tu co chu so dau la chu so le\n");
		printf("3. Liet ke so lan xuat hien cua cac phan tu trong mang\n");
		printf("4. Sap xep mang co so chan tang dan, so le giam dan\n");
		printf("5. Tim day con giam dai nhat trong a\n");
		printf("6. Tim so nho thu 2 trong mang\n");
		printf("7. Tim cac phan tu chua chu so cua x\n");
		printf("8. Sap xep mang sao cho cac phan tu chan tang dan, le giu nguyen vi tri\n");
		printf("9. Sap xep mang: so le o dau mang, so chan o cuoi mang\n");
		printf("10. Thoat\n");
		printf("Nhap lua chon cua ban: ");
		scanf("%d", &luaChon);

		switch (luaChon) {
		case 1: {
					int m;
					printf("Nhap n: ");
					scanf("%d", &m);
					LietKeSoNguyenTo(a, m);
					break;
		}
		case 2: {
					int tong = TongChuSoDauLe(a, n);
					printf("Tong cac phan tu co chu so dau la chu so le: %d\n", tong);
					break;
		}
		case 3: {
					LietKeSoLanXuatHien(a, n);
					break;
		}
		case 4: {
					SapXepChanTangLeGiam(a, n);
					printf("Mang sau khi sap xep: ");
					for (int i = 0; i < n; i++) {
						printf("%d ", a[i]);
					}
					printf("\n");
					break;
		}
		case 5: {
					int dayConGiam = TimDayConGiamDaiNhat(a, n);
					printf("Do dai day con giam dai nhat: %d\n", dayConGiam);
					break;
		}
		case 6: {
					int soNhoThuHai = TimSoNhoThuHai(a, n);
					if (soNhoThuHai == -1) {
						printf("Khong co so nho thu 2 trong mang.\n");
					}
					else {
						printf("So nho thu 2 trong mang: %d\n", soNhoThuHai);
					}
					break;
		}
		case 7: {
					int x;
					printf("Nhap x (so co 2 chu so): ");
					scanf("%d", &x);
					TimPhanTuChuaChuSoX(a, n, x);
					break;
		}
		case 8: {
					SapXepChanTangViTriLe(a, n);
					printf("Mang sau khi sap xep: ");
					for (int i = 0; i < n; i++) {
						printf("%d ", a[i]);
					}
					printf("\n");
					break;
		}
		case 9: {
					SapXepLeTruocChanSau(a, n);
					printf("Mang sau khi sap xep: ");
					for (int i = 0; i < n; i++) {
						printf("%d ", a[i]);
					}
					printf("\n");
					break;
		}
		case 10:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le.\n");
		}
	} while (luaChon != 10);

	free(a);
	return 0;
}
