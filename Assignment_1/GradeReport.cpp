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
	 unsigned  long firstNameSize = strlen(firstName) + 1;
	_firstName = new char[firstNameSize];
	assert(_firstName != nullptr);

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    strlcpy(_firstName, firstNameSize, firstName);
#elif __APPLE__ || __linux__ || __linux || __unix || __unix__ || __posix || defined(_POSIX_VERSION)
    strcpy(_firstName,firstName);
#endif

	return *this;
}

GradeReport& GradeReport::setLastName(const char* lastName)
{
	 unsigned  long lastNameSize = strlen(lastName) + 1;
	_lastName = new char[lastNameSize];
	assert(_lastName != nullptr);
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
    strcpy_s(_lastName, lastNameSize, lastName);
#elif __APPLE__ || __linux__ || __linux || __unix || __unix__ || __posix || defined(_POSIX_VERSION)
    strcpy(_lastName,lastName);
#endif
    
	return *this;
}

GradeReport& GradeReport::setNumberOfCredits( int numberOfCredits)
{
	_numberOfCredits = (short)(numberOfCredits >= 3 && numberOfCredits <= 18 ? numberOfCredits : 3);
	return *this;
}

GradeReport& GradeReport::setAge( int age)
{
	_age = (short)age;
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

GradeReport& GradeReport::operator+=(const GradeReport& val)
{
	if (_id == val._id) {
		int sizeFname = strlen(_firstName);
		int sizeLname = strlen(val._lastName);
		int size = sizeFname + sizeLname + 3;
		char* newName = new char [size];
		assert(newName != nullptr);
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) || defined(__NT__)
        strcpy_s(newName, sizeFname + 1, _firstName);
		strcat_s(newName, sizeFname + 2, " ");
		strcat_s(newName, size, val._lastName);
#elif __APPLE__ || __linux__ || __linux || __unix || __unix__ || __posix || defined(_POSIX_VERSION)
        strcpy(newName, _firstName);
        strcat(newName, " ");
        strcat(newName, val._lastName);
#endif
		
		setFirstName(newName);
		delete[] newName;
	}
	return *this;
}

GradeReport::~GradeReport()
{
	delete[] _firstName;
	delete[] _lastName;
}