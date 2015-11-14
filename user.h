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
typedef struct user {	
	char id[10];
	char name[30];
	char addr[50];
	char phone_no[11];
	char age[3];
	char email[30];
}user;





void adduser();
void remove_user(int id);
int verifyid(int id);
user finduser(int id);
void showusers();
void display_user(user a);
