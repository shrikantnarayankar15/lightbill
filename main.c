#include "user.h"
#include "lightbill.h"
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	adduser();
	showusers(argc, argv);
	show_bill();
	fcloseall();
	lightbill obj;
	obj = find_bill(1	);
	if(obj.id) {
		printf("\n\n");
		printf("%d\n\n", obj.prev_unit);
	}
	generate_bill(2, 250);
	show_bill();
	user h;
	h = finduser(1);
	remove_user(5);
	printf("%s", h.id);
	return 0;
}
