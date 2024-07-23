#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int PhanNguyen;
	int TuSo;
	int MauSo;
} HonSo;

typedef struct {
	int TuSo;
	int MauSo;
} PhanSo;

#define SIZE 20
HonSo taoHonSoNgauNhien();
void taoMangHonSoNgauNhien(HonSo b[], int size);
void xuatMangHonSo(HonSo b[], int size);
int soSanhHonSo(HonSo hs1, HonSo hs2);
PhanSo chuyenHonSoSangPhanSo(HonSo hs);
HonSo chuyenPhanSoSangHonSo(PhanSo ps);
PhanSo tongHonSo(HonSo hs1, HonSo hs2);
PhanSo hieuHonSo(HonSo hs1, HonSo hs2);
PhanSo tichHonSo(HonSo hs1, HonSo hs2);
PhanSo thuongHonSo(HonSo hs1, HonSo hs2);
void interchangeSort(HonSo b[], int size, int tang);
void selectionSort(HonSo b[], int size);
void quickSort(HonSo b[], int low, int high);


HonSo taoHonSoNgauNhien() {
	HonSo hs;
	hs.PhanNguyen = rand() % 10;
	hs.TuSo = rand() % 10;
	hs.MauSo = (rand() % 9) + 1; // mẫu số khác 0
	return hs;
}

void taoMangHonSoNgauNhien(HonSo b[], int size) {
	srand(time(0));
	for (int i = 0; i < size; i++) {
		b[i] = taoHonSoNgauNhien();
	}
}

void xuatMangHonSo(HonSo b[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d %d/%d ", b[i].PhanNguyen, b[i].TuSo, b[i].MauSo);
		if (i < size - 1) {
			printf(", ");
		}
	}
	printf("\n");
}

int soSanhHonSo(HonSo hs1, HonSo hs2) {
	PhanSo ps1 = chuyenHonSoSangPhanSo(hs1);
	PhanSo ps2 = chuyenHonSoSangPhanSo(hs2);

	int tuSo1 = ps1.TuSo * ps2.MauSo;
	int tuSo2 = ps2.TuSo * ps1.MauSo;

	if (tuSo1 < tuSo2) return -1;
	else if (tuSo1 > tuSo2) return 1;
	else return 0;
}

PhanSo chuyenHonSoSangPhanSo(HonSo hs) {
	PhanSo ps;
	ps.TuSo = hs.PhanNguyen * hs.MauSo + hs.TuSo;
	ps.MauSo = hs.MauSo;
	return ps;
}

HonSo chuyenPhanSoSangHonSo(PhanSo ps) {
	HonSo hs;
	hs.PhanNguyen = ps.TuSo / ps.MauSo;
	hs.TuSo = ps.TuSo % ps.MauSo;
	hs.MauSo = ps.MauSo;
	return hs;
}

int gcd(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

PhanSo rutGonPhanSo(PhanSo ps) {
	int gcdValue = gcd(ps.TuSo, ps.MauSo);  // Hàm tìm ước chung lớn nhất
	ps.TuSo /= gcdValue;
	ps.MauSo /= gcdValue;
	return ps;
}

PhanSo tongHonSo(HonSo hs1, HonSo hs2) {
	PhanSo ps1 = chuyenHonSoSangPhanSo(hs1);
	PhanSo ps2 = chuyenHonSoSangPhanSo(hs2);

	PhanSo ps;
	ps.TuSo = ps1.TuSo * ps2.MauSo + ps2.TuSo * ps1.MauSo;
	ps.MauSo = ps1.MauSo * ps2.MauSo;
	return rutGonPhanSo(ps);
}

PhanSo hieuHonSo(HonSo hs1, HonSo hs2) {
	PhanSo ps1 = chuyenHonSoSangPhanSo(hs1);
	PhanSo ps2 = chuyenHonSoSangPhanSo(hs2);

	PhanSo ps;
	ps.TuSo = ps1.TuSo * ps2.MauSo - ps2.TuSo * ps1.MauSo;
	ps.MauSo = ps1.MauSo * ps2.MauSo;
	return rutGonPhanSo(ps);
}

PhanSo tichHonSo(HonSo hs1, HonSo hs2) {
	PhanSo ps1 = chuyenHonSoSangPhanSo(hs1);
	PhanSo ps2 = chuyenHonSoSangPhanSo(hs2);

	PhanSo ps;
	ps.TuSo = ps1.TuSo * ps2.TuSo;
	ps.MauSo = ps1.MauSo * ps2.MauSo;
	return rutGonPhanSo(ps);
}

PhanSo thuongHonSo(HonSo hs1, HonSo hs2) {
	PhanSo ps1 = chuyenHonSoSangPhanSo(hs1);
	PhanSo ps2 = chuyenHonSoSangPhanSo(hs2);

	PhanSo ps;
	ps.TuSo = ps1.TuSo * ps2.MauSo;
	ps.MauSo = ps1.MauSo * ps2.TuSo;
	return rutGonPhanSo(ps);
}

void interchangeSort(HonSo b[], int size, int tang) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = i + 1; j < size; j++) {
			if ((tang && soSanhHonSo(b[i], b[j]) > 0) || (!tang && soSanhHonSo(b[i], b[j]) < 0)) {
				HonSo temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
}

void selectionSort(HonSo b[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int min_idx = i;
		for (int j = i + 1; j < size; j++) {
			if (soSanhHonSo(b[j], b[min_idx]) < 0) {
				min_idx = j;
			}
		}
		HonSo temp = b[min_idx];
		b[min_idx] = b[i];
		b[i] = temp;
	}
}

void swap(HonSo *a, HonSo *b) {
	HonSo temp = *a;
	*a = *b;
	*b = temp;
}

int partition(HonSo b[], int low, int high) {
	HonSo pivot = b[high];
	int i = (low - 1);

	for (int j = low; j < high; j++) {
		if (soSanhHonSo(b[j], pivot) < 0) {
			i++;
			swap(&b[i], &b[j]);
		}
	}
	swap(&b[i + 1], &b[high]);
	return (i + 1);
}

void quickSort(HonSo b[], int low, int high) {
	if (low < high) {
		int pi = partition(b, low, high);
		quickSort(b, low, pi - 1);
		quickSort(b, pi + 1, high);
	}
}

int main() {
	HonSo b[SIZE];
	int choice;
	do {
		printf("Menu:\n");
		printf("1. Tao mang b chua gia tri hon so ngau nhien\n");
		printf("2. Xuat danh sach hon so\n");
		printf("3. So sanh 2 hon so\n");
		printf("4. Chuyen hon so sang phan so\n");
		printf("5. Chuyen phan so sang hon so\n");
		printf("6. Tinh tong, hieu, tich, thuong 2 hon so\n");
		printf("7. Sap xep mang tang/giam\n");
		printf("8. Thoat\n");
		printf("Nhap lua chon: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			taoMangHonSoNgauNhien(b, SIZE);
			printf("Mang hon so ngau nhien da duoc tao.\n");
			break;
		case 2:
			xuatMangHonSo(b, SIZE);
			break;
		case 3: {
					HonSo hs1, hs2;
					printf("Nhap hon so 1 (phan nguyen, tu so, mau so): ");
					scanf("%d %d %d", &hs1.PhanNguyen, &hs1.TuSo, &hs1.MauSo);
					printf("Nhap hon so 2 (phan nguyen, tu so, mau so): ");
					scanf("%d %d %d", &hs2.PhanNguyen, &hs2.TuSo, &hs2.MauSo);
					int result = soSanhHonSo(hs1, hs2);
					if (result == 0) printf("Hai hon so bang nhau.\n");
					else if (result > 0) printf("Hon so 1 lon hon hon so 2.\n");
					else printf("Hon so 1 nho hon hon so 2.\n");
					break;
		}
		case 4: {
					HonSo hs;
					printf("Nhap hon so (phan nguyen, tu so, mau so): ");
					scanf("%d %d %d", &hs.PhanNguyen, &hs.TuSo, &hs.MauSo);
					PhanSo ps = chuyenHonSoSangPhanSo(hs);
					printf("Phan so: %d/%d\n", ps.TuSo, ps.MauSo);
					break;
		}
		case 5: {
					PhanSo ps;
					printf("Nhap phan so (tu so, mau so): ");
					scanf("%d %d", &ps.TuSo, &ps.MauSo);
					HonSo hs = chuyenPhanSoSangHonSo(ps);
					printf("Hon so: %d %d/%d\n", hs.PhanNguyen, hs.TuSo, hs.MauSo);
					break;
		}
		case 6: {
					HonSo hs1, hs2;
					printf("Nhap hon so 1 (phan nguyen, tu so, mau so): ");
					scanf("%d %d %d", &hs1.PhanNguyen, &hs1.TuSo, &hs1.MauSo);
					printf("Nhap hon so 2 (phan nguyen, tu so, mau so): ");
					scanf("%d %d %d", &hs2.PhanNguyen, &hs2.TuSo, &hs2.MauSo);
					PhanSo tong = tongHonSo(hs1, hs2);
					PhanSo hieu = hieuHonSo(hs1, hs2);
					PhanSo tich = tichHonSo(hs1, hs2);
					PhanSo thuong = thuongHonSo(hs1, hs2);
					printf("Tong: %d/%d\n", tong.TuSo, tong.MauSo);
					printf("Hieu: %d/%d\n", hieu.TuSo, hieu.MauSo);
					printf("Tich: %d/%d\n", tich.TuSo, tich.MauSo);
					printf("Thuong: %d/%d\n", thuong.TuSo, thuong.MauSo);
					break;
		}
		case 7: {
					int tang;
					printf("Nhap 1 de sap xep tang, 0 de sap xep giam: ");
					scanf("%d", &tang);
					interchangeSort(b, SIZE, tang);
					printf("Mang sau khi sap xep: \n");
					xuatMangHonSo(b, SIZE);
					break;
		}
		case 8:
			printf("Thoat chuong trinh.\n");
			break;
		default:
			printf("Lua chon khong hop le.\n");
		}
	} while (choice != 8);

	return 0;
}
