// CGPA CALCULATE CODE
#include <iostream>
#include <string>
using namespace std;

int main()
{

    int totalSem;
    double overallGradePoints = 0;
    double overallCredit = 0;

    cout << "enter total number of semester : ";
    cin >> totalSem;

    float cgpa;

    for (int sem = 1; sem <= totalSem; sem++)
    {
        // input no. of courses
        int numCourse;
        cout << "enter no.of courses in this sem : ";
        cin >> numCourse;

        double semCredit = 0;
        double semGradePoints = 0;

        float GPA;

        for (int i = 1; i <= numCourse; i++)
        {
            // input subject name
            string sub;
            cout << "enter Subject name : ";
            cin >> sub;

            // input credit of the subject
            int credit;
            cout << "enter credit of this subject : ";
            cin >> credit;

            // input grade
            string grade;
            cout << "enter grade of the subject : ";
            cin >> grade;

            int gradepoints = 0;
            if (grade == "Ex" || grade == "ex")
            {
                gradepoints = 10;
            }
            else if (grade == "A" || grade == "a")
            {
                gradepoints = 9;
            }
            else if (grade == "B" || grade == "b")
            {
                gradepoints = 8;
            }
            else if (grade == "C" || grade == "c")
            {
                gradepoints = 7;
            }
            else if (grade == "P" || grade == "p")
            {
                gradepoints = 6;
            }
            else if (grade == "F" || grade == "f")
            {
                gradepoints = 5;
            }
            semCredit += credit;
            semGradePoints += gradepoints;
        }

        double semGPA = semGradePoints / semCredit;
        cout << "\n --------------------------------\n";
        cout << "  Semester " << sem << " GPA : " << semGPA << endl;
        cout << "\n --------------------------------\n";

        overallCredit += semCredit;
        overallGradePoints += semGradePoints;
    }

    double finalCGPA = overallCredit / overallGradePoints;

    cout << "\n============================" << endl;
    cout << "         SEMESTER CGPA         " << endl;
    cout << "Total credit Earned : " << overallCredit << endl;
    cout << " Final CGPA : " << finalCGPA << endl;
    cout << "\n============================" << endl;

    return 0;
}
