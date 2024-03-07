#include <iostream>
#include <iomanip>

using namespace std;

/**
 * @brief Class stores total amount of money in pennies
*/

class Money {
    public:
        // Contructors
        /**
         * @brief constructor creates Money object with two parameters
         * 
         * @param dollars the dollar amount excluding cents
         * @param cents the cents excluding dollars
        */
        Money(long dollars, int cents);
        Money(long dollars);
        Money();

        // IO
        void output(ostream& out);
        void input(ostream& out, istream& in);

        // Getter
        /**
         * @brief getter function to return value of pennies
         * 
         * @return pennies is the value stored in the class
        */
        long get();

        // Setter
        void set(long dollars, int cents);
        void set(long dollars);
        void set();
        
    private:
        long pennies;
};

int main() {


    //Testing constructors and output functions
    Money test;
    Money test2(101);
    Money test3(101, 1);

    test.output(cout);
    test2.output(cout);
    test3.output(cout);

    //Test getting and setting
    test.set(75, 75);
    test.output(cout);

    cout << test.get() << endl;

    test.input(cout, cin);
    test.output(cout);

    return 0;
};

Money::Money(long dollars, int cents){
    pennies = cents + (dollars * 100);
};

Money::Money(long dollars){
    pennies = dollars * 100;
};

Money::Money(){
    pennies = 0;
};

long Money::get(){
    return pennies;
};

void Money::set(long dollars, int cents){
    pennies = cents + (dollars * 100);
};

void Money::set(long dollars){
     pennies = dollars * 100;
};

void Money::set(){
    pennies = 0;
};

void Money::output(ostream& out){
    out << "$" << fixed << setprecision(2) << pennies / 100.0 << endl;
};

void Money::input(ostream& outs, istream& in){
    outs << "Input dollars without cents: " << endl;
    long dollars;
    in >> dollars;
    outs << "Input leftover cents: " << endl;
    int cents;
    in >> cents;
    set(dollars, cents);
};
