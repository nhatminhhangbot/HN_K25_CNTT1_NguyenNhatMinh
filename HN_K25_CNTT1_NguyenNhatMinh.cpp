#include <stdio.h>
#define MAX_SIZE 50

int main(void) {
	int passengers[MAX_SIZE] = {32, 18, 45, 27, 50};
	int n = 5;
	int choice;
	int value;
	int newValue;
	int pos;
	int count = 0;
	
	do {
		printf("========================================================\n");
		printf("        CHUONG TRINH QUAN LY HANH KHACH CITYBUS         \n");
		printf("========================================================\n");
		printf("1. Them so hanh khach\n");
		printf("2. Sua so hanh khach\n");
		printf("3. Xoa so hanh khach\n");
		printf("4. Tim kiem so hanh khach\n");
		printf("0. Thoat chuong trinh\n");
		printf("========================================================\n");
		printf("Vui long nhap lua chon cua ban (0 - 4): ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				printf("Mang ban dau: [");
				for (int i = 0; i < n; i++) {
					printf("%d", passengers[i]);
					if (i < n - 1) {
						printf(", ");
					}
				}
				printf("]");
				
				if (n == MAX_SIZE) {
					printf("Mang da day, khong the them!\n\n");
					break;
				}
				
				printf("\nNhap gia tri can chen: ");
				scanf("%d", &value);
				
				if (value < 0) {
					printf("So hanh khach khong hop le!\n\n");
					break;
				}
				
				printf("Nhap vi tri can chen (1 - %d): ", n + 1);
				scanf("%d", &pos);
				
				if (pos < 1 || pos > n + 1) {
					printf("Vi tri chen khong hop le!\n\n");
					break;
				}
				
				for (int i = n; i >= pos; i--) {
					passengers[i] = passengers[i - 1];
				}
				passengers[pos - 1] = value;
				n++;
				
				printf("Chen thanh cong! Mang hien tai: [");
				for (int i = 0; i < n; i++) {
					printf("%d", passengers[i]);
					if (i < n - 1) {
						printf(", ");
					}
				}
				printf("]\n\n");
				break;
			case 2:
				printf("Mang ban dau: [");
				for (int i = 0; i < n; i++) {
					printf("%d", passengers[i]);
					if (i < n - 1) {
						printf(", ");
					}
				}
				printf("]");
				
				if (n == 0) {
					printf("Mang rong, khong the sua!\n\n");
					break;
				}
				
				printf("\nNhap vi tri can sua (1 - %d): ", n);
				scanf("%d", &pos);
				
				if (pos < 1 || pos > n) {
					printf("Vi tri sua khong hop le!\n\n");
					break;
				}
				
				printf("Nhap gia tri moi: ");
				scanf("%d", &newValue);
				
				if (newValue < 0) {
					printf("So hanh khach khong hop le!\n\n");
					break;
				}
				
				passengers[pos - 1] = newValue;
				printf("Sua thanh cong! Mang hien tai: [");
				for (int i = 0; i < n; i++) {
					printf("%d", passengers[i]);
					if (i < n - 1) {
						printf(", ");
					}
				}
				printf("]\n\n");
				break;
			case 3:
				printf("Mang ban dau: [");
				for (int i = 0; i < n; i++) {
					printf("%d", passengers[i]);
					if (i < n - 1) {
						printf(", ");
					}
				}
				printf("]");
				
				if (n == 0) {
					printf("Mang rong, khong the xoa!\n\n");
					break;
				}
				
				printf("\nNhap vi tri can xoa (1 - %d): ", n);
				scanf("%d", &pos);
				
				if (pos < 1 || pos > n) {
					printf("Vi tri xoa khong hop le!\n\n");
					break;
				}
				
				for (int i = pos - 1; i < n - 1; i++) {
					passengers[i] = passengers[i + 1];
				}
				n--;
				
				printf("Xoa thanh cong! Mang hien tai: [");
				for (int i = 0; i < n; i++) {
					printf("%d", passengers[i]);
					if (i < n - 1) {
						printf(", ");
					}
				}
				printf("]\n\n");
				break;
			case 4:
				if (n == 0) {
					printf("Mang rong, khong the tim kiem!\n\n");
					break;
				}
				
				printf("Nhap gia tri can tim kiem: ");
				scanf("%d", &value);
				
				count = 0;
				for (int i = 0; i < n; i++) {
					if (passengers[i] == value) {
						if (count == 0) {
							printf("Tim thay tai vi tri: ");
						} else {
							printf(", ");
						}
						printf("%d", i + 1);
						count++;
					}
				}
				
				if (count == 0) {
					printf("Khong tim thay gia tri trong mang!\n");
				} else {
					printf("\nTong so lan xuat hien: %d\n", count);
				}
				printf("\n");
				break;
			case 0:
				printf("Da thoat chuong trinh. Tam biet!");
				printf("\n");
				break;
			default:
				printf("Lua chon khong hop le!\n\n");
				break;
		}
	} while(choice != 0);
	
	return 0;
}
