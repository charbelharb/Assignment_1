#include "GradeReport.h"

GradeReport::GradeReport( int id, const char* firstName, const char* lastName,  short numberOfCredits,  short age)
{
	set(id, firstName, lastName, numberOfCredits, age);
}

GradeReport::GradeReport()
{
	_id = {};
	_firstName = {};
	_lastName = {};
	_numberOfCredits = {};
	_age = {};
}

void GradeReport::set( int id, const char* firstName, const char* lastName,  short numberOfCredits,  short age)
{
	setId(id).setFirstName(firstName).setLastName(lastName).setNumberOfCredits(numberOfCredits).setAge(age);
}

GradeReport& GradeReport::setId( int id) {
	_id = id >= 2003 ? id : 0;
	return *this;
}

GradeReport& GradeReport::setFirstName(const char* firstName)
{
	 int firstNameSize = strlen(firstName) + 1;
	_firstName = new char[firstNameSize];
	assert(_firstName != 0);
	strcpy_s(_firstName, firstNameSize, firstName);
	return *this;
}

GradeReport& GradeReport::setLastName(const char* lastName)
{
	 int lastNameSize = strlen(lastName) + 1;
	_lastName = new char[lastNameSize];
	assert(_lastName != 0);
	strcpy_s(_lastName, lastNameSize, lastName);
	return *this;
}

GradeReport& GradeReport::setNumberOfCredits( int numberOfCredits)
{
	_numberOfCredits = numberOfCredits >= 3 && numberOfCredits <= 18 ? numberOfCredits : 3;
	return *this;
}

GradeReport& GradeReport::setAge( int age)
{
	_age = age;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const GradeReport& gr)
{
	out << "Student:\t" << "ID\t" << "Fname\t" << "Lname\t" << "Credits\t" << "Age" << std::endl;
	out << "\t" << gr._id << "\t" << gr._firstName << "\t" << gr._lastName << "\t" << gr._numberOfCredits << "\t" << gr._age << std::endl;
	return out;
}

std::istream& operator>>(std::istream& in, GradeReport& gr)
{
	std::cout << "Enter id" << std::endl;
	 int id{};
	in >> id;
	in.ignore();
	std::cout << "Enter First Name" << std::endl;
	char* firstName = new char[MAX_INPUT];
	in.getline(firstName, MAX_INPUT);
	std::cout << "Enter Last Name" << std::endl;
	char* lastName = new char[MAX_INPUT];
	in.getline(lastName, MAX_INPUT);
	std::cout << "Enter Number of Credit" << std::endl;
	 short numberOfCredits{};
	in >> numberOfCredits;
	 short age{};
	std::cout << "Enter age" << std::endl;
	in >> age;
	gr.set(id, firstName, lastName, numberOfCredits, age);
	delete[] firstName;
	delete[] lastName;
	return in;
}

GradeReport& GradeReport::operator++()
{
	++_age;
	return *this;
}

GradeReport& GradeReport::operator+=(int val)
{
	setNumberOfCredits(_numberOfCredits + val);
	return *this;
}

GradeReport& GradeReport::operator=(int val)
{
	setId(val);
	return *this;
}

GradeReport::~GradeReport()
{
	delete[] _firstName;
	delete[] _lastName;
}