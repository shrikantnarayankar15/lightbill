#include <stdio.h>
void menu();
void displaybill();
int main() {
	menu();
	int n;
	printf("Enter Choice");
	scanf("%d", &n);
	switch(n) {
		case 1:
			//
			break;
		case 2:
			displaybill();
			break;
		case 3:
			exit(0);
	}
	return 0;
}
void menu() {
	printf("1. Admin Section\n");
	printf("2. User Section\n");
	printf("3. Exit\n");
}
