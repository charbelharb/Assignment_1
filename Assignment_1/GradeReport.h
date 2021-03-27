#ifndef GRADE_REPORT_H
#define GRADE_REPORT_H

#define MAX_INPUT 256

#include <iostream>
#include <string.h>
#include <cassert>


class GradeReport
{
	/// <summary>
	/// Output stream overload
	/// </summary>
	/// <param name="out">Stream</param>
	/// <param name="gr">Grade Report</param>
	/// <returns></returns>
	friend std::ostream & operator << (std::ostream& out, const GradeReport& gr);

	/// <summary>
	/// Input stream overload
	/// </summary>
	/// <param name="in">Stream</param>
	/// <param name="gr">Grade Report</param>
	/// <returns></returns>
	friend std::istream& operator >> (std::istream& in, GradeReport& gr);

private:
	/// <summary>
	/// Student Id
	/// </summary>
	unsigned int _id;

	/// <summary>
	/// Student First Name
	/// </summary>
	char* _firstName;

	/// <summary>
	/// Student Last Name
	/// </summary>
	char* _lastName;

	/// <summary>
	/// Student's number of credits
	/// </summary>
	unsigned short _numberOfCredits;

	/// <summary>
	/// Student Age
	/// </summary>
	unsigned short _age;

	/// <summary>
	/// Set fields
	/// </summary>
	/// <param name="id">Student Id</param>
	/// <param name="firstName">Student First Name</param>
	/// <param name="lastName">Student Last Name</param>
	/// <param name="numberOfCredits">Student's number of credits</param>
	/// <param name="age">Student Age</param>
	void set(unsigned int id, const char* firstName, const char* lastName, unsigned short numberOfCredits, unsigned short age);

	/// <summary>
	/// Set Id
	/// </summary>
	/// <param name="id">Student Id</param>
	/// <returns></returns>
	GradeReport &setId(unsigned int id);

	/// <summary>
	/// Set First Name
	/// </summary>
	/// <param name="firstName">Student First Name</param>
	/// <returns></returns>
	GradeReport &setFirstName(const char* firstName);

	/// <summary>
	/// Set Last Name
	/// </summary>
	/// <param name="lastName">Student Last Name</param>
	/// <returns></returns>
	GradeReport &setLastName(const char* lastName);

	/// <summary>
	/// Set number of credits
	/// </summary>
	/// <param name="numberOfCredits">Student's number of credits</param>
	/// <returns></returns>
	GradeReport &setNumberOfCredits(unsigned int numberOfCredits);

	/// <summary>
	/// Set Age
	/// </summary>
	/// <param name="age">Student Age</param>
	/// <returns></returns>
	GradeReport &setAge(unsigned int age);

	

public:

	/// <summary>
	/// Initialize Grade Report
	/// </summary>
	/// <param name="id">Student Id</param>
	/// <param name="firstName">Student First Name</param>
	/// <param name="lastName">Student Last Name</param>
	/// <param name="numberOfCredits">Student's number of credits</param>
	/// <param name="age">Student Age</param>
	GradeReport(unsigned int id, const char* firstName, const char* lastName, unsigned short numberOfCredits, unsigned short age);

	GradeReport();

	~GradeReport();
};
#endif
