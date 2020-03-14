#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<cstdlib>

using namespace std;

bool login()
{	
	int count;
	string username, password, u,p;
	system("clear");
	cout<<"**********************User Login***********************\n\n";
	cout<<"Enter Username: ";
	cin>>username;
	cout<<"Enter Password: ";
	cin>>password;

	ifstream input("database.txt");
	while(input>>u>>p)
	{
		if(u==username && p==password)
		{
			count =1;
			system("clear");
		}
	}
	input.close();
	
	if(count==1)
		cout<<username<<" successfully logged-in."<<endl;
	else
		cout<<"Could not login. Please check your Username and Password again."<<endl;

	return false;
}

bool new_registration()
{
	string username, password;
	system("clear");
	cout<<"*******************New Registration********************\n\n";
	cout<<"Enter Username(without space): ";
	cin>>username;
	cout<<"Enter Password: ";
	cin>>password;

	ofstream reg("database.txt", ios::app);
	reg<<username<<" "<<password<<endl;
	//system("clear");
	cout<<"\n\nUser Successfully Registered\n"; 
	return true;
}

bool forgot_password()
{
	int count=0;
	string search_user, u,p;
	system("clear");
	cout<<"*******************Password Retrieval********************\n\n";
	cout<<"Enter username:";
	cin>>search_user;
	
	ifstream get_password("database.txt");
	
	while(get_password>>u>>p)
	{
		if(u==search_user)
			count=1;
	}	
	
	get_password.close();
	
	if(count==1)
		cout<<"Password retrieved: "<<p<<endl;
	
	else
		cout<<"UserID not found!"<<endl;
	
	return true;
}

bool create_video(int i)
{
	return true;	
}

int main()
{
	int n; //choices
	
	while(n!=4)
		{
		cout<<"********************************************************"<<endl;
		cout<<endl;
		cout<<"1. Login"<<endl;
		cout<<"2. Register"<<endl;
		cout<<"3. Forgot Password"<<endl;
		cout<<"4. Exit"<<endl;
		cout<<endl;
		cout<<"********************************************************"<<endl;
		cout<<"Choose an option:";
		
		cin>>n;
		bool a= false;
		char ch='Y';
		bool v= false;
		int i=0;
		

		switch(n)
		{
			case 1:
				a = login();
				
				cout<<"Enter Y/N to make a 10-sec video from your webcam and store it in on your computer:";
				cin>>ch;

				while(tolower(ch) == 'y')
				{		
				v =create_video(i++);
				cout<<"Enter Y/N to make a 10-sec video from your webcam and store it in on your computer:";
				cin>>ch;
				}
				break;

			case 2:
				a = new_registration();
				break;

			case 3:
				a = forgot_password();
				break;

			case 4:
				cout<<"Closing Application."<<endl;
				break;
				
			default:
				cout<<"Not a valid option. Try again!"<<endl;
		}
	}

	return 0;
}
