#include <iostream>

using namespace std;

class COP3014 {
    private:
        string studentFirstName;
        string studentLastName;
        int studentZNumber;

        double assignment1Grade;
        double assignment2Grade;
        double assignment3Grade;
        double assignment4Grade;
        double midtermExamGrade;
        double finalExamGrade;

        double overallFinalGrade;

    public:
    COP3014(){
        cout << "WARNING: Empty student object created." << endl;
    };
    COP3014(string initStudentFirstName, string initStudentLastName, int initStudentZNumber) :  studentFirstName(initStudentFirstName), studentLastName(initStudentLastName), studentZNumber(initStudentZNumber){
        assignment1Grade = -1;
        assignment2Grade = -1;
        assignment3Grade = -1;
        assignment4Grade = -1;
        midtermExamGrade = -1;
        finalExamGrade = -1;
        overallFinalGrade = -1;
    };

    bool validGrade(double grade){
        if(grade < 0 || grade > 100){
            cout << "ERROR: Invalid grade input. ";
            return false;
        } else {
            return true;
        }

    }

    void setAssignmentGrade(int assignmentNumber, double grade ){
        if(validGrade(grade)){        
            switch (assignmentNumber)
            {
            case 1:
                assignment1Grade = grade;
                break;

            case 2:
                assignment2Grade = grade;
                break;

            case 3:
                assignment3Grade = grade;
                break;

            case 4:
                assignment4Grade = grade;
                break;

            default:
                cout << "ERROR: Assignment not found. Assignment Number Inputted: " << assignmentNumber << ". Attempted assigned grade: " << grade << "." << endl; 
                return;
            }

            cout << "Assignment " << assignmentNumber << "'s grade was captured" << endl;
            return;

        } else {
            cout << "Input grade value: " << grade << endl;
        }

    }

    void setMidtermGrade(double inputGrade){
        if(validGrade(inputGrade)) {
            midtermExamGrade = inputGrade;
            cout << "Midterm grade was captured" << endl;
        } else {
            cout << "input grade value: " << inputGrade << endl;

        }
    }

    void calculatingOverallGrade(){

    }

    void displayOutput(){
        cout << "Student: " << studentFirstName << ", " << studentLastName << "." << endl;
        cout << "Students Z-number: " << studentZNumber << "." << endl;

        cout << "Assignment 1 Exam Grade: " << assignment1Grade << "." << endl;
        cout << "Assignment 2 Exam Grade: " << assignment2Grade << "." << endl;
        cout << "Assignment 3 Exam Grade: " << assignment3Grade << "." << endl;
        cout << "Assignment 4 Exam Grade: " << assignment4Grade << "." << endl;
        cout << "Midterm Exam Grade: " << midtermExamGrade << "." << endl;
        cout << "Final Exam Grade: " << finalExamGrade << "." << endl;
        cout << "Overall Final Grade: " << overallFinalGrade << "." << endl;
    }
};

int main(){
    COP3014 student1("John", "Doe", 555);
    student1.displayOutput();
    student1.setAssignmentGrade(1, 101);
    student1.setMidtermGrade(80);
    student1.setMidtermGrade(801);
    student1.displayOutput();
    return 0;
}