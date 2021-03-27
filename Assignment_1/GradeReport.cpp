#include "GradeReport.h"

void GradeReport::set(unsigned int id, const char* firstName, const char* lastName, unsigned short numberOfCredits, unsigned short age)
{
	setId(id).setFirstName(firstName).setLastName(lastName).setNumberOfCredits(numberOfCredits).setAge(age);
}

GradeReport& GradeReport::setId(unsigned int id) {
	_id = id >= 2003 ? id : 0;
	return *this;
}

GradeReport& GradeReport::setFirstName(const char* firstName)
{
	unsigned int firstNameSize = strlen(firstName) + 1;
	_firstName = new char[firstNameSize];
	assert(_firstName != 0);
	strcpy_s(_firstName, firstNameSize, firstName);
	return *this;
}

GradeReport& GradeReport::setLastName(const char* lastName)
{
	unsigned int lastNameSize = strlen(lastName) + 1;
	_lastName = new char[lastNameSize];
	assert(_lastName != 0);
	strcpy_s(_lastName, lastNameSize, lastName);
	return *this;
}

GradeReport& GradeReport::setNumberOfCredits(unsigned int numberOfCredits)
{
	_numberOfCredits = numberOfCredits >= 3 && numberOfCredits <= 18 ? numberOfCredits : 3;
	return *this;
}

GradeReport& GradeReport::setAge(unsigned int age)
{
	_age = age;
	return *this;
}

GradeReport::GradeReport(unsigned int id, const char* firstName, const char* lastName, unsigned short numberOfCredits, unsigned short age)
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

GradeReport::~GradeReport()
{
	 delete [] _firstName;
	 delete [] _lastName;
}

std::ostream& operator<<(std::ostream& out, const GradeReport& gr)
{
	return out;
}

std::istream& operator>>(std::istream& in, GradeReport& gr)
{
	std::cout << "Enter id" << std::endl;
	unsigned int id{};
	in >> id;	
	in.ignore();
	std::cout << "Enter First Name" << std::endl;
	char* firstName = new char[MAX_INPUT];
	in.getline(firstName,MAX_INPUT); 
	std::cout << "Enter Last Name" << std::endl;
	char* lastName = new char[MAX_INPUT];
	in.getline(lastName, MAX_INPUT);
	std::cout << "Enter Number of Credit" << std::endl;
	unsigned short numberOfCredit{};
	in >> numberOfCredit;
	unsigned short age{};
	std::cout << "Enter age" << std::endl;
	in >> age;
	gr.set(id, firstName, lastName, numberOfCredit, age);
	delete[] firstName;
	delete[] lastName;	
	return in;
}
