#include <iostream>

using namespace std;

class Money {
    public:
        // Contructors
        Money(long dollars, int cents);
        Money(long dollars);
        Money();

        // IO
        void output(ostream& output);
        void inpute(istream& input);

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