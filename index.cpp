#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include<cstdlib>
#include<stdio.h>
#include"opencv2/opencv.hpp"
#include<ctime>
#include<cstdio>
#include<time.h>
#include<stdio.h>


using namespace std;
using namespace cv;



bool create_video(int i)
{	
	time_t start, end;
        VideoCapture vcap(0);
        if (!vcap.isOpened()) {
            cout << "Error opening video stream or file" << endl;
            return -1;
        }

	string filename = "/home/kusu/Programs/CppApplication/vid.avi";
        int frame_width = vcap.get(CV_CAP_PROP_FRAME_WIDTH);
        int frame_height = vcap.get(CV_CAP_PROP_FRAME_HEIGHT);
        VideoWriter video(filename, CV_FOURCC('M', 'J', 'P', 'G'), 10,Size(frame_width, frame_height), true);

        time(&start);

        for (;;) {

            Mat frame;
            vcap >> frame;
            video.write(frame);
            imshow("Frame", frame);
            char c = (char)waitKey(33);
            if (c == 27) break;


            time(&end);
            double dif = difftime(end, start);
            //printf("Elasped time is %.2lf seconds.", dif);
            if (dif==10)
            {
                std::cout << "DONE" << dif<< std::endl;
                break;
            }
        }
	return true;	
}



bool login()
{	
	int count,i=0;
	char ch;
	bool b=false; 
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
			cout<<username<<" successfully logged-in."<<endl;
			break;	
			
		}
	}
	input.close();
	
	if(count==1)
	{
		cout<<"Enter Y/N to make a 10-sec video from your webcam and store it in on your computer:";
		cin>>ch;

		while(tolower(ch) == 'y')
		{		
		b =create_video(i);
		i++;
		cout<<"Enter Y/N to make a 10-sec video from your webcam and store it in on your computer:";
		cin>>ch;
		}
	}
		
	else
		cout<<"Could not login. Please check your Username and Password again."<<endl;

	return true;
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
		int i=0;
		

		switch(n)
		{
			case 1:
				a = login();
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
