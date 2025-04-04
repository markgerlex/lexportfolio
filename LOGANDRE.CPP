#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char pass[100], username[100], loginPass[100], loginUser[100];
char wantLog;
int option = 0, vowelCount = 0, numCount = 0, passLen = 0, invalidCounter = 0;

void registration();
void login();

main() {
	clrscr();

start:
top:
	cout<<"******************MENU*******************"<<endl<<endl;
	cout<<"  [1] - Register\n  [2] - Login\n  [3] - Exit "<<endl<<endl;
	cout<<"*****************************************"<<endl;
	cout<<"Option: ";
	cin>>option;

	switch (option){
	case 1:
		registration();																				;
		break;
	case 2:
		login();
		break;
	case 3:
	       cout <<"Goodbye...";
	       getch();
	       exit(0);
	default:
		cout<<"Invalid Input"<<endl;
		goto top;

	}
getch();
}

void registration() {

	cout<<"**************REGISTRATION**************"<<endl
	<<endl;
	cout<<"Username: ";
	gets(username);

	password:
	cout<<"Password: ";
	gets(pass);

	passLen = strlen(pass);
	pass[passLen] = '\0';

	for (int i = 0; pass[i] != '\0'; i++) {
		if(isdigit(pass[i])) {
			numCount++;
		} else if ((pass[i] == 'a') || (pass[i] == 'e') ||
		(pass[i] == 'i') || (pass[i] == 'o') || (pass[i] == 'u')) {
			vowelCount++;
		}
	}

	if (passLen < 8 || passLen > 12) {
		cout << "Invalid: Password must be 8 to 12 characters long\n"<<endl;
		vowelCount = numCount - 0;
		goto password;
	}
	if (numCount < 2) {
		cout<<"Invalid: Password must have atleast two numbers\n"<<endl;
		vowelCount =0;
		numCount =0;
		goto password;
	}

	if (vowelCount < 2) {
		cout<<"Invalid: Password must have atleast two vowels\n"<<endl;
		vowelCount =0;
		numCount = 0;
		goto password;
	}

	cout<<"\n Account Successfully Registered!\n"<<endl;
	cout<<"Do you want to Login?(Y/N)";
	cin>>wantLog;

	if (wantLog == 'y' || wantLog == 'Y') {
		cout << endl;
		main();
	} else if (wantLog == 'n' || wantLog == 'N') {
		cout<<"Goodbye...";
		getch();
		exit(0);
	}
}

void login() {

	cout<<"****************LOGIN****************"<<endl
	<<endl;

	login:
	if (invalidCounter == 3) {
		cout<<"Maximum number of attempts exceeded. Program Terminated!";
		getch();
		exit(0);
	}
	cout<<"Username: ";
	gets(loginUser);
	cout<<"Password: ";
	gets(loginPass);

	if (strcmp(loginUser, username) !=0) {
		cout<<"Invalid Username" <<endl;
		invalidCounter++;
		goto login;
	}
	if (strcmp(loginPass, pass) != 0) {
		cout<<"Invalid Password"<<endl;
		invalidCounter++;
		goto login;
	}

	cout<<"Login Successfully!";
}



