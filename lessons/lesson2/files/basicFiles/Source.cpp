#include "Student.h"
#include <iostream>;

using std::cout;
using std::endl;

int main()
{
	Student stud1;

	// first student info
	stud1.setFirstName("Shahar");
	stud1.setLastName("Hasson");
	stud1.setId(123456789);
	stud1.setGrade(HISTORY_GRADE_IDX, 78);
	stud1.setGrade(MATH_GRADE_IDX, 81);
	stud1.setGrade(LITERATURE_GRADE_IDX, 90);
	stud1.setGrade(ENGLISH_GRADE_IDX, 65);
	
	Student stud2;

	// second student info
	stud2.setFirstName("Beyonce");
	stud2.setLastName("");
	stud2.setId(111111111);
	stud2.setGrade(HISTORY_GRADE_IDX, 95);
	stud2.setGrade(MATH_GRADE_IDX, 87);
	stud2.setGrade(LITERATURE_GRADE_IDX, 90);
	stud2.setGrade(ENGLISH_GRADE_IDX, 98);


	system("pause");
	return 0;
	
}