#include "Student.h"
#include <iostream> // std::cout, std::endl

using std::cout;
using std::endl;

int main()
{
	// initiates a Student object
	Student A(111111111, "Beyonce", "", 169);
	Student B(222222222, "Rihanna", "", 173);

	A.setGrade(HISTORY_GRADE_IDX, 90);
	A.setGrade(MATH_GRADE_IDX, 77);
	A.setGrade(LITERATURE_GRADE_IDX, 88);
	A.setGrade(ENGLISH_GRADE_IDX, 100);

	A.print();
	B.print();

	if (A < B)
	{
		cout << B.getFirstName() << " is taller than " << A.getFirstName() << endl;
	}
	if (A > B)
	{
		cout << A.getFirstName() << " is taller than " << B.getFirstName() << endl;
	}

	cout << "\nAdded 3 points to all student's grades" << endl;
	A++;
	(A++)++;

	// the following lines are equivalent:
	if (A == B)
	{
		cout << "SAME" << endl;
	}

	if (A.operator==(B))
	{
		cout << "SAME" << endl;
	}

	A.print();


	system("pause");
	return 0;
}


