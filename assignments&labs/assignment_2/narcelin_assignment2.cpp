/*

Feburary 2024

Loan Calculator
Assignment 2-3 for Programming 2 class taught by Dr. Sareh Raebi.
Creator: Nicolas Arcelin Ovando

See repository @ https://github.com/narcelin/workspaceForProgramming2/tree/LoanCalculator_Assignment2-3/assignments%26labs/assignment_2
*/

#include <iostream>
#include <cmath>
#include <array>
#include <vector>
#include <iomanip>

using namespace std;

/* PROGRAM INFO

Inputs: loan amount (P), annual percentage rate (APR), loan term(n) - in years and/or months

Goal: calculates and displays the monthly payments and balance of loan until the load is paid off. Known as "amortization schedule"

Monthly payments calculated using amortization equations: | M = P ((r(1+r)^n)/((1+r)^n)-1) | M = monthly payments, P is principal load, r is the monthly interest rate and n is the number of pauments over loan's lifetime.

r = (1+ (APR/100)^1/12) - 1

*/

void ValueInputer(double* balance, double* apr, int* n);
float AprConverter(double apr);
double AmortizationCalculator(double balance, float r, int n);
void InterestAndPrincipalCalculator(double* balance, float r, double* payment_amount, double* interest_amount, double* principal_amount);
void TotalPaymentsAndInterestAccumulator(int n, double* balance_ptr, float r, double* payment_amount, double* interest_amount, double* principal_amount, double beginning_balances[], double ending_balances[], double interest_amounts[], double principal_amounts[]);
void DisplayTabularInformation(int n, double beginning_balances[], double ending_balances[], double interest_amounts[], double principal_amounts[]);



int main(){
    bool rerun_program = false;
    do{
        double balance = 0.00; //Loan Amount
        double apr = 0.00; //Annual Percentage Rate
        int n = 0; //Loan term in months

        double interest_amount = 0.00;
        double principal_amount = 0.00;

        ValueInputer(&balance, &apr, &n);
        float r = AprConverter(apr);
        double payment_amount = AmortizationCalculator(balance, r, n); //Monthly payments

        double beginning_balances[n - 1];
        double ending_balances[n - 1];
        double interest_amounts[n - 1];
        double principal_amounts[n-1];

        TotalPaymentsAndInterestAccumulator(n, &balance, r, &payment_amount, &interest_amount, &principal_amount, beginning_balances, ending_balances, interest_amounts, principal_amounts);
        DisplayTabularInformation(n, beginning_balances, ending_balances, interest_amounts, principal_amounts);


        char rerun_input_valid = false;
        do{
            cout << "Do you want to re-run this program? (y/n): ";
            char rerun_program = ' ';
            cin >> rerun_program;
            if(rerun_program == 'y'){
                cout << endl << "------------ RE INITALIZING PROGRAM ------------ " << endl << endl;
                rerun_program = true;
                rerun_input_valid = true;
            } else if(rerun_program == 'n'){
                cout << endl << "END OF PROGRAM" << endl;
                exit(1);
            } else {
                cout << "### INVALID INPUT ###: Please input 'y' for yes and 'n' for no" << endl;
            }
        } while(!rerun_input_valid);
    } while (!rerun_program);
    return 0;
}

void ValueInputer(double* balance_ptr, double* apr_ptr, int* n_ptr){ 

    cout << "*** Input the following values ***" << endl;
   
   bool isLoanAmountValid = false;
    do{
        cout << "Loan Amount (P): ";
        cin >> *balance_ptr; //Code breaks if user inputs non-numeric value. Usure how to rectify issue.
        if(*balance_ptr <= 0){
            cout << "### INVALID ### : Please input a Loan Amount greater the 0" << endl;
            isLoanAmountValid = false;
        } else {
            isLoanAmountValid = true;
        }
   } while (!isLoanAmountValid);
    
    bool isAnnualPercentageRateValid = false;
    do{
        cout << "Annual Percentage Rate (APR): ";
        cin >> *apr_ptr; //Code breaks if user inputs non-numeric value. Usure how to rectify issue.
        if(*apr_ptr <= 0){
            cout << "### INVALID ### : Please input a Annual Percentage Rate greater then 0" << endl;
            isAnnualPercentageRateValid = false;
        } else {
            isAnnualPercentageRateValid = true;
        }
   } while (!isAnnualPercentageRateValid);
    
    bool isLoanTermValid = false;
    do{
        cout << "Loan Term \"in months\" (n): ";
        cin >> *n_ptr; //Code breaks if user inputs non-numeric value. Usure how to rectify issue.
        if(*n_ptr <= 0){
            cout << "### INVALID ### : Please input a Loan Term greater then 0" << endl;
            isLoanTermValid = false;
        } else {
            isLoanTermValid = true;
        }
   } while (!isLoanTermValid);
    

};

float AprConverter(double apr){
    float r = (pow((1+(apr/100)),(1.0/12))) - 1; //Monthly interest rate
    return r;
};

double AmortizationCalculator(double balance, float r, int n){
    return(balance * (r * pow((1 + r), n))/(pow((1 + r), n) - 1));
};

void InterestAndPrincipalCalculator(double* balance_ptr, float r, double* payment_amount, double* interest_amount, double* principal_amount){
    *interest_amount = (r * *balance_ptr);
    *principal_amount = *payment_amount - *interest_amount;
    *balance_ptr = *balance_ptr - *principal_amount;
};

void TotalPaymentsAndInterestAccumulator(int n, double* balance_ptr, float r, double* payment_amount, double* interest_amount, double* principal_amount, double beginning_balances[], double ending_balances[], double interest_amounts[], double principal_amounts[]){ 
    for(int i = 0; i < n; i++){
        beginning_balances[i] = *balance_ptr;
        InterestAndPrincipalCalculator(balance_ptr, r, payment_amount, interest_amount, principal_amount);
        interest_amounts[i] = *interest_amount;
        principal_amounts[i] = *principal_amount;
        ending_balances[i] = *balance_ptr;
    }
};

void DisplayTabularInformation(int n, double beginning_balances[], double ending_balances[], double interest_amounts[], double principal_amounts[]){
    cout << fixed << setprecision(2);
    cout 
        << setw(10) << "Month" 
        << setw(20) << "Beginning Balance" 
        << setw(20) << "Interest" 
        << setw(20) << "Principal" 
        << setw(20) << "Ending Balance" 
        << endl;

    for(int i = 0; i < n; i++){
        cout 
            << setw(8) << i + 1
            << setw(20) << beginning_balances[i]
            << setw(20) << interest_amounts[i]
            << setw(20) << principal_amounts[i]
            << setw(20) << ending_balances[i] 
            << endl;

    }
};
