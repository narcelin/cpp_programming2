/*
SANDBOX by Nicolas Arcelin Ovando
*/

#include <iostream>
#include <string>     //needed for type string

using namespace std;

class Test {
    public:
        void settingProtected(){
            protectedValue = 100;
        }
        void displayProtected(){
            cout << protectedValue << endl;
        }
    protected:
        int protectedValue;
    private:
        string privateMessage = "TOP SECRET";
};

class InheritedTest  : public Test {
    public:
        void display(){
            cout << protectedValue << endl;
        }
        Test::settingProtected;
        void setProtected(int x){
            protectedValue = x;
        }
};

int main() 
{
    int i = 9;
 if(++i % 10 == 0) cout << i << endl;

    return 0;
}
