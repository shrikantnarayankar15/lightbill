/* <Remote Lightbill payment system>
    Copyright (C) <2015>  <Shrikant narayankar>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>
*/

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
void display_lightbill(lightbill a);
void show_bill_paid();
void show_bill_not_paid();

