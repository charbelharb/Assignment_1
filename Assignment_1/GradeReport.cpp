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
	_numberOfCredits = numberOfCredits > 3 || numberOfCredits <= 18 ? numberOfCredits : 3;
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
