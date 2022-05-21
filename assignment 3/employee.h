#include <iostream>
#include<iomanip>
using namespace std;
class Employee {
	friend istream& operator>>(istream&, Employee&);

private:
	int age;
	string firstname;
	string lastname;

public:



	string getfirstname() { return firstname; }
	string getlastname() { return lastname; }
	int getage() { return age; }
	int getaccountnumber() { return accountnumber; }
	int accountnumber;
	void setage(int);
};
void Employee::setage(int a)
{
	age = a;
}
	

 istream& operator >>(istream& input,  Employee& e) {

	 input.ignore();
	 input >> setw(10) >> e.firstname;
	 input.ignore();
	 input >> setw(10) >> e.lastname;
	 input.ignore();
	 input >> setw(10) >> e.age;

	 return input;


}
