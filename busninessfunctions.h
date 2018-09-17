#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
struct Employees
{
	string lastName;
	string firstName;
	string jobTitle;
	long long annualSal;
	long long id;

};
//This fucntion will print the list of employees for the user
void employeeList(Employees allEmployees[], int size)
{
	int i=0;
	int c = 1;
	cout << "Last Name" <<setw(20)<< "First Name" <<setw(20)<< "Job Title" << setw(30)<<"Annual Salary" <<setw(30)<< "Employee ID Number\n";
	cout << "________________________________________________________________________________________________________________________\n";
	while(i<size)
	{

		cout << c << ')' << setw(1) << allEmployees[i].lastName << setw(20) << allEmployees[i].firstName << setw(27) << allEmployees[i].jobTitle << setw(17) << '$' << allEmployees[i].annualSal << setw(17) << "ID#:" << allEmployees[i].id << endl;
		i=i+1;
		++c;
		cout << "________________________________________________________________________________________________________________________\n";
	}
}
//This function will store the array into a text document
void storearray(fstream & inFile, Employees allEmployees[],int size)
{
	int i; //counter
	for(i=0; i<size; ++i)
	{
		//read file and place input into array
		inFile >> allEmployees[i].lastName >> allEmployees[i].firstName >>  allEmployees[i].jobTitle >> allEmployees[i].annualSal >> allEmployees[i].id;
	}
	cout << "\n\n";
}
//This fucntion will allow the user to add an employee
void addEmployee(fstream & inFile, Employees  allEmployees[],int & size)
{
	int i ;
	string lastName, firstName, jobTitle;
	long long annualSal;
	long long id;
	size = size + 1;
	cout << "Please enter all the employees information as follows.\n";
	cout << "Last Name: ";
	cin >> lastName;
	allEmployees[size-1].lastName = lastName;
	cout << allEmployees[size-1].lastName;
	cout << endl;
	cout << "First Name: ";
	cin >> firstName;
	allEmployees[size-1].firstName = firstName;
	cout << allEmployees[size-1].firstName;
	cout << endl;
	cout << "Job Title: " ;
	cin >> jobTitle;
	allEmployees[size-1].jobTitle = jobTitle ;
	cout << allEmployees[size-1].jobTitle;
	cout << endl;
	cout << "Annual Salary: ";
	cin >> annualSal;
	allEmployees[size-1].annualSal = annualSal;
	cout << allEmployees[size-1].annualSal;
	cout << endl;
	cout << "Employee ID Number: ";
	cin >> id;
	allEmployees[size-1].id = id;
	cout << allEmployees[size-1].id;
	cout << endl;
	for ( i=0; i<size; i++)
	{
		inFile <<  allEmployees[i].lastName << ' ' << allEmployees[i].firstName << ' ' << allEmployees[i].jobTitle << ' ' << allEmployees[i].annualSal << setw(1) << ' ' <<  allEmployees[i].id << ' ' << endl; 
	}
}
//This function will sort the employees by their id numbers
void  sortEmployeesid(Employees allEmployees[], int size)
{
	Employees temp; 
    bool swap; 
    int i, j; // counters
    for(i = 0; i < size; ++i)
    {
        swap = false;
        for(j = 0; j < size - i - 1; ++j)
        {
            if ( allEmployees[j].id > allEmployees[j+1].id )
            {
                swap = true;
                temp = allEmployees[j];
                allEmployees[j] = allEmployees[j+1];
                allEmployees[j+1] = temp;
            }
        }
        if (!swap)
        {
            break;
        }
    }
}
//This function will binary search for an employee
int searchEmployee(Employees allEmployees[],int size, long long id )
{
	int first = 0; // Beginning of the search range
    int last = size - 1; // End of the search range
    int middle; // Middle of the search range
    int index = -1; // Position of the target, or -1 if not found
    bool found = false; // True if the target has been found
	sortEmployeesid(allEmployees, size);//function call
	//while loop that will go through the array of Movie struct and find a certain result
	while ( !found && first <= last )
	{
		middle = (first + last) / 2;
		if( allEmployees[middle].id == id )
        {
            index = middle;
            found = true;
        }
		else if( allEmployees[middle].id > id )
        {
            last = middle - 1;
        }
		else
        {
            first = middle + 1;
        }
    }

    return index;
}
//This fucntion will sort the names of the employees and it has a proper fail safe incase the employees have the same name
void  sortEmployeesnames(Employees allEmployees[], int size)
 {
	Employees temp; 
    bool swap; 
    int i, j; // counters
    for(i = 0; i < size; ++i)
    {
        swap = false;
        for(j = 0; j < size - i - 1; ++j)
        {
            if ( allEmployees[j].lastName > allEmployees[j+1].lastName )
            {
				swap = true;
                temp = allEmployees[j];
                allEmployees[j] = allEmployees[j+1];
                allEmployees[j+1] = temp;
            }
			else if (allEmployees[j].lastName == allEmployees[j+1].lastName)
			{
				if ( allEmployees[j].firstName > allEmployees[j+1].firstName )
				{
					swap = true;
					temp = allEmployees[j];
					allEmployees[j] = allEmployees[j+1];
					allEmployees[j+1] = temp;
				}
			}
		
		}
			
        if (!swap)
        {
            break;
        }
    }
}
//This function will allow the user to delete an employee from the text document and array
void deleteEmployee(fstream & inFile,Employees allEmployees[],int index, int& size)
{
	int i;
	allEmployees[index].firstName ="zzzzzzzzzzzzzzzzzzzzzzzzz";
	allEmployees[index].lastName="zzzzzzzzzzzzzzzzzzzzzzzzz";
	allEmployees[index].jobTitle ="zzzzzzzzzzzzzzzzzzzzzzzzz";
	allEmployees[index].annualSal = 9223372036854775807;
	allEmployees[index].id = 9223372036854775807;
	sortEmployeesnames(allEmployees,size);
	size= size-1;
	for ( i=0; i<size; ++i)
	{
		inFile <<  allEmployees[i].lastName << ' ' << allEmployees[i].firstName << ' ' << allEmployees[i].jobTitle << ' ' << allEmployees[i].annualSal << setw(1) << ' ' <<  allEmployees[i].id << ' ' << endl; 
	}
	inFile << "                                                                      ";
}
//This function will display the options the user has to use in the program
void bossoptions()
{
	 cout << "1)Search for an employee.\n";
	 cout << "2)Add an employee.\n";
	 cout << "3)Delete an employee.\n";
	 cout << "4)Quit Program.\n";
	 cout << "Please pick one of the choices listed above(1,2,3,4): ";
}