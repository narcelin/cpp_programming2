#include <iostream>

using namespace std;

class Money {
    public:
        // Contructors
        Money(long dollars, int cents);
        Money(long dollars);
        Money();

        // IO
        void output(ostream& out);
        void input(istream& in);

        // Getter
        long get();

        // Setter
        void set(long dollars, int cents);
        void set(long dollars);
        void set();
        
    private:
        long pennies;
};

int main() {

    Money test;
    Money test2(101);
    Money test3(101, 1);

    test.output(cout);
    test2.output(cout);
    test3.output(cout);

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
    out << "$" << pennies / 100 << "." << pennies % 100 << endl;
};

void Money::input(istream& in){
    in >> pennies;
};
