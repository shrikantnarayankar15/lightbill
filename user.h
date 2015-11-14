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
