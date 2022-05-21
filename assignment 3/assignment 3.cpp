#include <iostream>
#include<fstream>
#include <iomanip>
#include "employee.h"

using namespace std;

void outputLine(ostream&,  Employee&);


int main() {
	ofstream outEmployee("employee.dat", ios::binary);
	ifstream inEmployee("employee.dat", ios::in);

	if (!outEmployee) {
		cerr << "File couldn't be opened" << endl;
		exit(1);
	}
	cout << "enter a number 1 to 10. 0 to end input" << endl;

	Employee employee;
	

	cin >> employee.accountnumber; 


	while (employee.getaccountnumber() > 0 && employee.getaccountnumber() <= 10) {

		cout << " enter first name, last name and age" << endl << "?";
		cin >> employee;
		if (employee.getage() < 10)
		{
			employee.setage(18);
		}
	
		outEmployee.seekp((employee.getaccountnumber()-1) * sizeof(Employee));
		outEmployee.write(reinterpret_cast<const char*>(&employee), sizeof(Employee));       // write function
		cout << "enter a number 1 to 10. 0 to end input" << endl;
		cin >> employee.accountnumber;
	}
	if (!inEmployee) {
		cerr << "File couldn't be opened" << endl;
		exit(1);
	}
	cout << "first name" << setw(16) << "last name" << setw(11) << "age" << endl;
	
	
	while (inEmployee && !inEmployee.eof() )
	
	{		outputLine(cout, employee);
			inEmployee.read(reinterpret_cast<char*>(&employee), sizeof(Employee));         // read function
	}
	return 0;
}
void outputLine(ostream& output,  Employee& e) {

	output << setiosflags(ios::left) << setw(16)<<e.getfirstname() << setw(16) << e.getlastname()<< setw(3)<<setprecision(2) << resetiosflags(ios::left)<< setiosflags(ios::fixed |	ios::showpoint)<< e.getage() << '\n';
}
