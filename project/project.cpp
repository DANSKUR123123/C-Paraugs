/*
	Programma, kas imitē skolas datu bāzi
*/
#include <iostream>
#include<string>
#include<iomanip>

using namespace std;


struct Student
{
	int Nr;
	string firstName;
	string lastName;
	int yearOfEnrollment;
	int scholarship;
};


void addRecord(Student students[],int count)
{
	cout << "\n\nEnter Student Number: ";
	cin >> students[count].Nr;

	while (students[count].Nr < 0 || students[count].Nr > INT_MAX)
	{
		cout << "Please enter valid value: ";
		cin >> students[count].Nr;
	}

	cin.ignore();
	cout << "Enter First Name: ";
	getline(cin,students[count].firstName);

	cout << "Enter Last Name: ";
	getline(cin, students[count].lastName);

	cout << "Enter Year Of Enrollment: ";
	cin>> students[count].yearOfEnrollment;
	while (students[count].yearOfEnrollment < 1800 || students[count].yearOfEnrollment > INT_MAX)
	{
		cout << "Please enter valid value: ";
		cin >> students[count].yearOfEnrollment;
	}


	cout << "Enter Scholarchip: ";
	cin >> students[count].scholarship;
	while (students[count].scholarship < 0 || students[count].scholarship > INT_MAX)
	{
		cout << "Please enter valid value: ";
		cin >> students[count].scholarship;
	}


	cout << "\n\nStudent Record Add Successfully..." << endl;
}

void searchByLastName(Student students[], int count)
{

	if (count > 0)
	{
		string lastName;
		bool exist = false;
		cout << "\n\nEnter last Name:   ";
		cin.ignore();
		getline(cin, lastName);
		cout << fixed << left << setw(15) << "Number" << setw(20) << "First Name";
		cout << setw(20) << "Last Name" << setw(30) << "year Of Enrollment" << setw(30) << "Scholarship %" << endl;
		for (int i = 0; i < count; i++)
		{
			if (students[i].lastName == lastName)
			{
				cout << fixed << left << setw(15) << students[i].Nr << setw(25) << students[i].firstName;
				cout << setw(25) << students[i].lastName << setw(25) << students[i].yearOfEnrollment << setw(23) << students[i].scholarship << endl;
				exist = true;
			}
		}

		if (!exist)
			cout << "No Student Exist" << endl;
	}
	else
	{
		cout << "\nNo Record Found!" << endl;
	}
}


void viewArrayContent(Student students[], int count)
{
	if (count > 0)
	{


		cout << endl << endl;
		cout << fixed << left << setw(15) << "Number" << setw(20) << "First Name";
		cout << setw(20) << "Last Name" << setw(30) << "year Of Enrollment" << setw(30) << "Scholarship (%)" << endl;
		for (int i = 0; i < count; i++)
		{
			cout << fixed << left << setw(15) << students[i].Nr << setw(25) << students[i].firstName;
			cout << setw(25) << students[i].lastName << setw(25) << students[i].yearOfEnrollment << setw(23) << students[i].scholarship << endl;
		}
	}
	else
	{
		cout << "\nNo Record Found!" << endl;
	}
}


void displayScholarShipBaseStudents(Student students[], int count)
{
	int scholarship;
	char lower;
	bool exist = false;

	cout << "\nEnter Scholarship %: ";
	cin >> scholarship;

	while (scholarship < 0 || scholarship > INT_MAX)
	{
		cout << "Please enter valid value: ";
		cin >> scholarship;
	}

	cin.ignore();
	cout << "Do you want students information lower than " << scholarship << " %  (y/n):  ";
	cin >> lower;
	if (lower == 'y' || lower == 'Y')
	{
		cout << fixed << left << setw(15) << "Number" << setw(20) << "First Name";
		cout << setw(20) << "Last Name" << setw(30) << "year Of Enrollment" << setw(30) << "Scholarship %" << endl;
		for (int i = 0; i < count; i++)
		{
			if (students[i].scholarship <= scholarship)
			{
				cout << fixed << left << setw(15) << students[i].Nr << setw(25) << students[i].firstName;
				cout << setw(25) << students[i].lastName << setw(25) << students[i].yearOfEnrollment << setw(23) << students[i].scholarship << endl;
				exist = true;
			}
		}
		if (!exist)
			cout << "\nNo Record Found!" << endl;
	}
	else
	{
		cout << fixed << left << setw(15) << "Number" << setw(20) << "First Name";
		cout << setw(20) << "Last Name" << setw(30) << "year Of Enrollment" << setw(30) << "Scholarship %" << endl;
		for (int i = 0; i < count; i++)
		{
			if (students[i].scholarship >= scholarship)
			{
				cout << fixed << left << setw(15) << students[i].Nr << setw(25) << students[i].firstName;
				cout << setw(25) << students[i].lastName << setw(25) << students[i].yearOfEnrollment << setw(23) << students[i].scholarship << endl;
				exist = true;
			}
		}
		if (!exist)
			cout << "\nNo Record Found!" << endl;
	}
}

void sortArray(Student students[], int count)
{
	
	if (count > 0)
	{
		for (int i = 1; i < count; i++)
		{
			Student temp = students[i];
			int j = i - 1;

			while (j >= 0 && students[j].lastName > temp.lastName)
			{
				students[j + 1] = students[j];
				j = j - 1;
			}
			students[j + 1] = temp;
		}
		cout << "\n\nRecords Arrange Successfully...." << endl;
	}
	else
	{
		cout << "\nNo Record Found!" << endl;
	}
}


void displayMenu()
{
	cout << "\n\n";
	cout << "1- Add Record" << endl;
	cout << "2- Search By Last Name" << endl;
	cout << "3- View Array Content" << endl;
	cout << "4- View Specified Student Base On Scholar Ship" << endl;
	cout << "5- Arrange Record By Last Name" << endl;
	cout << "6- Quit" << endl;
	cout << "Select Option =>  ";

}
int main()
{
	
	Student students[100];


	int count = 0;
	int option;

	do
	{
		displayMenu();
		cin >> option;
		while (option < 1 || option > 6)
		{
			cout << "Invalid option! Enter again:   ";
			cin >> option;
		}

		if (option == 1)
		{
			addRecord(students, count);
			count++;
		}

		else if (option == 2)
		{
			searchByLastName(students, count);
		}
		else if (option == 3)
		{
			viewArrayContent(students, count);
		}
		else if (option == 4)
		{
			
			displayScholarShipBaseStudents(students, count);
		}
		else if (option == 5)
		{
			sortArray(students, count);
		}
		else if (option == 6)
		{
			cout << "***********************GOOD BYE***************************" << endl;
		}

	} while (option != 7);



	return 0;
}
