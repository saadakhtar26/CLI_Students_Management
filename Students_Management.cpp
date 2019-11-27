/*
	Name: Students Management System
	Copyright: GNU General Public Liscence v3.0
	Author: Saad Rajpoot
	Date: 04/07/19 05:35
	Description: C++ code for Students Management System Program.
	
	Features:
	
		1. Add a Student.
		2. Show All Students.
		3. Edit Student Details.
		4. Delete a Student.
		5. Search Student by Name.
		6. Search Student by Roll.
		7. Search Student by Course.
		8. Search Student by Section.
		9. Exit to DOS.
*/

#include<iostream>
#include<conio.h>
#include<fstream>
#include<string>
using namespace std;

struct students{
string name;
string course;
string sec;
string roll;
};
students stud[100];

int mainop,rolluni,lines=0;
fstream file;

calc_lines(){
	lines=0;
	file.open("data.txt",ios::in);
	while(getline(file,stud[0].name,'#')){
		lines++;
	}
	file.close();
}

void add(){
	file.open("data.txt",ios::app);
	if(file){
	cout<<"Enter Name: ";
	getline(cin,stud[lines].name);
	cout<<"Enter Roll No: ";
	getline(cin,stud[lines].roll);
	cout<<"Enter Course: ";
	getline(cin,stud[lines].course);
	cout<<"Enter Section: ";
	getline(cin,stud[lines].sec);
	file<<stud[lines].name<<"$"<<stud[lines].roll<<"$"<<stud[lines].course<<"$"<<stud[lines].sec<<"#";
	}
	cout<<"\nData Entered Successfully !";
	file.close();
}

void read(){
	int i=0;
	file.open("data.txt",ios::in);
	cout<<"Total Students: "<<lines<<"\n";
	if(file){
		for(i=0;i<lines;i++){
			getline(file,stud[i].name,'$');
			cout<<"\nID: "<<i+1<<"\nName: "<<stud[i].name<<"\n";
			getline(file,stud[i].roll,'$');
			cout<<"Roll: "<<stud[i].roll<<"\n";
			getline(file,stud[i].course,'$');
			cout<<"Course: "<<stud[i].course<<"\n";
			getline(file,stud[i].sec,'#');
			cout<<"Section: "<<stud[i].sec<<"\n";
		}
	}
	file.close();
}

void del(){
	int id=0,i=0;
	read();
	cout<<"\nEnter ID to delete: ";
	cin>>id;
	file.open("data.txt",ios::out);
	if(file){
		for(i=0;i<lines;i++){
			if(i!=id-1){
				file<<stud[i].name<<"$"<<stud[i].roll<<"$"<<stud[i].course<<"$"<<stud[i].sec<<"#";
			}
		}
	}
	cout<<"\nStudent Deleted Successfully !";
	file.close();
	lines--;
}

void edit(){
	int id=0,i;
	read();
	cout<<"\nEnter ID to edit: ";
	cin>>id;
	file.open("data.txt",ios::out);
	if(file){
		for(i=0;i<lines;i++){
			if(i==id-1){
				cout<<"Enter Name: ";
				getline(cin,stud[i].name);
				getline(cin,stud[i].name);
				cout<<"Enter Roll no: ";
				getline(cin,stud[i].roll);
				cout<<"Enter Course: ";
				getline(cin,stud[i].course);
				cout<<"Enter Section: ";
				getline(cin,stud[i].sec);
			}
			file<<stud[i].name<<"$"<<stud[i].roll<<"$"<<stud[i].course<<"$"<<stud[i].sec<<"#";
		}
		cout<<"\nStudent Edited Successfully !";
		file.close();
	}
}

void search(){
	int k=0;
	string qroll,qname,qcourse,qsec;
	int srop;
	cout<<"1. Search by Name.\n2. Search by Roll no.\n3. Search by Course.\n4. Search by Section.\n> ";
	cin>>srop;

	file.open("data.txt",ios::in);
	if(file){
		
		
		if(srop==1){
			cout<<"Name: ";
			getline(cin,qname);
			getline(cin,qname);
		}
		else if(srop==2){
			cout<<"Roll no: ";
			getline(cin,qroll);
			getline(cin,qroll);
		}
		else if(srop==3){
			cout<<"Course: ";
			getline(cin,qcourse);
			getline(cin,qcourse);
		}
		else if(srop==4){
			cout<<"Section: ";
			getline(cin,qsec);
			getline(cin,qsec);
		}
		
		for(k=0;k<lines;k++){
			getline(file,stud[k].name,'$');
			getline(file,stud[k].roll,'$');
			getline(file,stud[k].course,'$');
			getline(file,stud[k].sec,'#');
			
			if(srop==1){
				if(stud[k].name==qname){
					cout<<"\nID: "<<k+1<<"\nName: "<<stud[k].name<<"\nRoll No: "<<stud[k].roll<<"\nCourse: "<<stud[k].course<<"\nSection: "<<stud[k].sec<<"\n";
				}
			}
			
			else if(srop==2){
				if(stud[k].roll==qroll){
					cout<<"\nID: "<<k+1<<"\nName: "<<stud[k].name<<"\nRoll No: "<<stud[k].roll<<"\nCourse: "<<stud[k].course<<"\nSection: "<<stud[k].sec<<"\n";
				}
			}
			
			else if(srop==3){
				if(stud[k].course==qcourse){
					cout<<"\nID: "<<k+1<<"\nName: "<<stud[k].name<<"\nRoll No: "<<stud[k].roll<<"\nCourse: "<<stud[k].course<<"\nSection: "<<stud[k].sec<<"\n";
				}
			}
			
			else if(srop==4){
				if(stud[k].sec==qsec){
					cout<<"\nID: "<<k+1<<"\nName: "<<stud[k].name<<"\nRoll No: "<<stud[k].roll<<"\nCourse: "<<stud[k].course<<"\nSection: "<<stud[k].sec<<"\n";
				}
			}
			
		}
	}
	file.close();
}


int main(){
	calc_lines();
	system("cls");
	cout<<"Total Students: "<<lines<<"\n\n";
	cout<<"1. Add a Student.\n2. Show All Students.\n3. Edit Student Details.\n4. Delete a Student.\n5. Search Student.\n6. Exit.\n>  ";
	mainop = getch();
	system("cls");
	if(mainop=='1'){
		add();
		getch();
		main();
	}
	else if(mainop=='2'){
		read();
		getch();
		main();
	}
	else if(mainop=='3'){
		edit();
		getch();
		main();
	}
	else if(mainop=='4'){
		del();
		getch();
		main();
	}
	else if(mainop=='5'){
		search();
		getch();
		main();
	}
	else if(mainop=='6'){
		exit(1);
	}
	else{
		cout<<"Wrong Option Selected !";
		getch();
		main();
	}
	return 0;
}
