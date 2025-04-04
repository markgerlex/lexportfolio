#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char name[100], program[100], address[100], contactNumber[50], religion[50];
int age = 0;

void regUser();
void view();

main() {
	int option = 0;
menu:
	clrscr();
	cout<<"******************MENU*******************"<<endl<<endl;
	cout<<"  [1] - Register\n  [2] - View\n  [3] - Exit "<<endl<<endl;
	cout<<"*****************************************"<<endl;
	cout<<"Option: ";
	cin>>option;

	switch (option){
	case 1:
		regUser();																				;
		break;
	case 2:
		view();
		break;
	case 3:
	       cout <<"Program Terminated!";
	       getch();
	       exit(0);
	default:
		cout<<"Invalid Input! Please try again."<<endl;
		main();

	}
	cout << "\nPress any key to continue...";
    getch();
    goto menu;
}

void regUser() {

	cout<<"**************REGISTER USER**************\n";
	cout<<"Enter Name: ";
	gets(name);
	cout<<"Enter Program: ";
	gets(program);
	cout<<"Enter Address: ";
	gets(address);
	cout<<"Enter Age: ";
	cin>>age;
	cout<<"Enter Contact Number: ";
	gets(contactNumber);
	cout<<"Enter Religion: ";
	gets(religion);

	cout<<"\nUser successfully registered!\n";
}

void view() {

	cout<<"****************VIEW INFORMATION****************"<<endl
	<<endl;
	if (strlen(name) == 0) {
		cout << "\nNo registered user found! Please register first.\n";
	} else {
		cout << "Name: " << name << endl;
		cout << "Program: " << program << endl;
		cout << "Address: " << address << endl;
		cout << "Age: " << age << endl;
		cout << "Contact Number: " << contactNumber << endl;
		cout << "Religion: " << religion << endl;
	}
}




