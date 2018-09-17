#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include "busninessfunctions.h"
//Below are function headers, however they are unnessecary due to me including the function. But it is a just a habit
void employeeList(Employees allEmployees[], int size); 
void  sortEmployeesnames(Employees allEmployees[], int size);
void storearray(fstream & inFile, Employees allEmployees[],int size);
void bossoptions();
void addEmployee( fstream & inFile, Employees allEmployees[],int & size);
int searchEmployee(Employees allEmployees[],int size, long long id );
void deleteEmployee(fstream & inFile,Employees allEmployees[],int index, int& size);
const int employees = 25;// This constant is to create an array big enough to hold a lot of employees
int main()
{
	//declare variable, files, and struct
	int workers, choice, index;
	char decision = 'N';
	long long id;
	fstream File;
	fstream File2;
	fstream File3;
	Employees allEmployees[employees];
	File.open("businessemployeesinput.txt");
	if (!File)
	{
		cout << "File not found\n\n" ;
		system("pause");
		return 1;
	}
	//Will ask how many employees in the user's company
	cout << "How many employees do you have in your company? :";
	cin >> workers;
	//This while loop will repeat on command until the user chooses to be done with the program
	while( decision != 'Y' ||  decision != 'y' || decision != 'N'|| decision != 'n')
	{
		storearray(File, allEmployees,workers);
		sortEmployeesnames(allEmployees, workers);
		system("cls");
		employeeList(allEmployees, workers);
		while( decision == 'N' ||  decision == 'n')
		{
			bossoptions();
			decision ='Y';
		}
		cin >> choice;
		while(choice != 1 &&  choice != 2 && choice != 3 && choice !=4)
		{
			cout << "Sorry that is not a choice, please choose from the options listed above! : ";
			cin >> choice;
		}
	
		if(choice == 1)//This is choice 1, it will allow the user to search an employee by id number. It is mainly for use if the employee list is to big to read the names off the list.
		{
			cout << "Can you please enter in the employee's ID number : ";
			cin >> id;
			index = searchEmployee(allEmployees,workers,id);
			cout << "Full Name: " << allEmployees[index].firstName << ' ' << allEmployees[index].lastName << endl;
			cout << "Job Title: " << allEmployees[index].jobTitle << endl;
			cout << "Annual Salary: " << allEmployees[index].annualSal << endl;
			cout << "Employee ID Number: " << allEmployees[index].id << endl << endl;
			cout << "Do you wish to continue searching employees? (y/n): ";
			cin >> decision;
			while (decision != 'Y' &&  decision != 'y' && decision != 'N'&& decision != 'n')
			{
				cout << "Please choose (y) for yes or (n) for no.";
				cout << "Do you wish to continue searching employees? (y/n): ";
				cin >> decision;
			}

		}
		else if (choice ==2)//This is choice 2, it will add an employee to the text document and array. By using the add function from our header
		{
		
			File2.open("businessemployeesinput.txt");
			while(decision =='y' || decision =='Y')
			{
				system("cls");
				addEmployee(File2, allEmployees,workers);
				cout << "Do you wish to continue adding employees? (y/n): ";
				cin >> decision;
				while (decision != 'Y' &&  decision != 'y' && decision != 'N'&& decision != 'n')
				{
					cout << "Please choose (y) for yes or (n) for no.";
					cout << "Do you wish to continue adding employees? (y/n): ";
					cin >> decision;
				}
			}
			File2.close();
		}
		else if (choice ==3)//This is choice 3, it will delete an employee from the text document and from the array using the delete function from our header file
		{
			File3.open("businessemployeesinput.txt");
			while(decision == 'Y' || decision == 'y')
			{
				system("cls");
				cout << "Can you please enter in the employee's ID number : ";
				cin >> id;
				index = searchEmployee(allEmployees,workers,id);
				cout << "Full Name: " << allEmployees[index].firstName << ' ' << allEmployees[index].lastName << endl;
				cout << "Job Title: " << allEmployees[index].jobTitle << endl;
				cout << "Annual Salary: " << allEmployees[index].annualSal << endl;
				cout << "Employee ID Number: " << allEmployees[index].id << endl << endl;
				cout <<"Is this the employee you wish to fire? (y/n): ";
				cin >> decision;
				while (decision != 'Y' &&  decision != 'y' && decision != 'N'&& decision != 'n')
				{
					cout << "Please choose (y) for yes or (n) for no.";
					cout << "Is this the employee you wish to fire? (y/n): ";
					cin >> decision;
				}
				if ( decision == 'Y' || decision == 'y')
				{
					deleteEmployee(File3,allEmployees, index, workers);
				}
				cout << "Do you wish to continue deleting employees? (y/n): ";
				cin >> decision;
				while (decision != 'Y' &&  decision != 'y' && decision != 'N'&& decision != 'n')
				{
					cout << "Please choose (y) for yes or (n) for no.";
					cout << "Do you wish to continue deleting employees? (y/n): ";
					cin >> decision;
				}
			}
			File3.close();
		}
		else if(choice == 4)//This is choice 4, it will qut the system if chosen
		{
			system("cls");
			cout << "Job Well Done!!\n";
			system("pause");
			return 1;
		}	
	}
	File.close();
	system("pause");
	return 0;	
}