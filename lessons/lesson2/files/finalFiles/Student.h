#pragma once
#include <string>

// grades array access
#define NUM_OF_GRADES 4
#define HISTORY_GRADE_IDX 0
#define MATH_GRADE_IDX 1
#define LITERATURE_GRADE_IDX 2
#define ENGLISH_GRADE_IDX 3

// initial grade value
#define EMPTY_GRADE -1

class Student 
{
public:

	// constructors & destructor
	Student(const int id, const std::string firstName, const std::string lastName, const int height);
	Student(const Student& other);
	~Student();

	// getters
	int getId() const;
	std::string getFirstName() const;
	std::string getLastName() const;
	int getHeight() const;
	unsigned int getGrade(const int grade_idx) const;

	// setters
	void setId(const int newId);
	void setFirstName(const std::string newFirstName);
	void setLastName(const std::string newLastName);
	void setHeight(const int newHeight);
	void setGrade(const int grade_idx, const unsigned int new_grade);

	// operators
	bool operator==(const Student& other) const;
	bool operator<(const Student& other) const;
	bool operator>(const Student& other) const;
	Student& operator++(int);

	// copy operator
	Student& operator=(const Student& other);

	// methods
	double getAverage() const;
	void print() const;

private:
	// fields
	int _id;
	std::string _firstName;
	std::string _lastName;
	int _height;

	unsigned int *_grades;

	//methods
	std::string getGradeString(const int gradeIndex) const;	// helper method

};