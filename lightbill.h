typedef struct lightbill {
	int id;
	int curr_unit;
	int prev_unit;
	float prev_bill;
	float curr_bill;
	char month[10];
	char end_date[20];
	char paid_y_n;
}lightbill;
void delete_bill(int id);
void init_bill(int id);
void generate_bill(int id, int unit);
lightbill find_bill(int id);
void pay_bill(int id);
void show_bill();
