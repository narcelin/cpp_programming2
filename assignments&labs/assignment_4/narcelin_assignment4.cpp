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
        string finalLetterGrade;

        void calculateOverallGrade(){
            cout << "Calculating overall grade." << endl;

            double tempOverallGrade = 0;

            double assignmentsPoints = 0;
            int numOfAssignmentsGraded = 0;
            if(assignment1Grade > -1){
                numOfAssignmentsGraded ++;
                assignmentsPoints += assignment1Grade;
            } else {
                cout << "WARNING: Assignment 1 is not captured." << endl;
            }
            if(assignment2Grade > -1){
                numOfAssignmentsGraded ++;
                assignmentsPoints += assignment2Grade;
            } else {
                cout << "WARNING: Assignment 2 is not captured." << endl;
            }
            if(assignment3Grade > -1){
                numOfAssignmentsGraded ++;
                assignmentsPoints += assignment3Grade;
            } else {
                cout << "WARNING: Assignment 3 is not captured." << endl;
            }
            if(assignment4Grade > -1){
                numOfAssignmentsGraded ++;
                assignmentsPoints += assignment4Grade;
            } else {
                cout << "WARNING: Assignment 4 is not captured." << endl;
            }
            double assignmentsExamWeightedGrade = 100 * ((assignmentsPoints / (numOfAssignmentsGraded * 100.00)) * 0.25);
            cout << "Assignments weighted grade: " << assignmentsExamWeightedGrade << endl;

            double midtermExamWeightedGrade = 0;        
            if(midtermExamGrade > -1){
                midtermExamWeightedGrade += 100 * ((midtermExamGrade / 100) * 0.30);
                cout << "Weighted Midterm Grade: " << midtermExamWeightedGrade << endl;
            } else {
                cout << "WARNING: Midterm exam is not captured." << endl;
            }

            double finalExamWeightedGrade = 0;
            if(finalExamGrade > -1){
                finalExamWeightedGrade += 100 * ((finalExamGrade / 100) * 0.45);
                cout << "Weighted Final Grade: " << finalExamWeightedGrade << endl;
            } else {
                cout << "WARNING: Final exam is not captured." << endl;
            }

            overallFinalGrade = assignmentsExamWeightedGrade + midtermExamWeightedGrade + finalExamWeightedGrade;
            cout << "Overall final grade: " << overallFinalGrade << endl;

            if(overallFinalGrade >= 90){
                finalLetterGrade = "A";
            } else if(overallFinalGrade >= 87){
                finalLetterGrade = "A-";
            } else if(overallFinalGrade >= 83){
                finalLetterGrade = "B+";
            } else if(overallFinalGrade >= 80){
                finalLetterGrade = "B";
            } else if(overallFinalGrade >= 77){
                finalLetterGrade = "B-";
            } else if(overallFinalGrade >= 73){
                finalLetterGrade = "C+";
            } else if(overallFinalGrade >= 70){
                finalLetterGrade = "C";
            } else if(overallFinalGrade >= 67){
                finalLetterGrade = "C-";
            } else if(overallFinalGrade >= 63){
                finalLetterGrade = "D+";
            } else if(overallFinalGrade >= 60){
                finalLetterGrade = "D";
            } else if(overallFinalGrade >= 51){
                finalLetterGrade = "D-";
            } else if(overallFinalGrade <= 50){
                finalLetterGrade = "F";
            }

            cout << finalLetterGrade << endl;

    }

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

    void setFinalGrade(double inputGrade){
        if(validGrade(inputGrade)) {
            finalExamGrade = inputGrade;
            cout << "Final grade was captured" << endl;
            calculateOverallGrade();
        } else {
            cout << "input grade value: " << inputGrade << endl;

        }
    }

    void reCalculateOverallGrade(){
        calculateOverallGrade();
    }

    double getAssignmentGrade(int assignmentNumber){
        switch (assignmentNumber)
        {
        case 1:
            return assignment1Grade;
        case 2:
            return assignment2Grade;
        case 3:
            return assignment3Grade;
        case 4:
            return assignment4Grade;        
        default:
            cout << "ERROR: Retrieving assignment grade. Assignment input number: " << assignmentNumber << endl;
            break;
        }
        return -1;
    }

    double getMidtermGrade(){
        return midtermExamGrade;
    }

    double getFinalGrade(){
        return finalExamGrade;
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

class Spring24 : public COP3014 {
    private:
    public:
};

int main(){
    COP3014 student1("John", "Doe", 555);
    student1.setAssignmentGrade(1, 34);
    student1.setAssignmentGrade(2, 78);
    student1.setAssignmentGrade(3, 90);
    student1.setAssignmentGrade(4, 68);
    student1.setMidtermGrade(88);
    student1.setFinalGrade(75);
    return 0;
}