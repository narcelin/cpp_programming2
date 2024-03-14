#include <iostream>

using namespace std;

class ParentClass {
    private: //Variables 
        int parentInteger;
    public: //Seters, Getters, Modifiers functions
        void setInteger(int input){
            parentInteger = input;
        };

        int getInteger(){
            return parentInteger;
        }
};

class ChildClass : public ParentClass { //inheritance
    private:
    public:
};

void passByReference(string& reference){
    cout << "Pass by reference: " << reference << endl;
    reference = "I have been changed";
};

int main(){
    ChildClass child;
    child.setInteger(5);
    cout << child.getInteger() << endl;

    //passByReference("This does not work");
    string reference = "This does work";
    passByReference(reference);
    cout << reference << endl;

    return 0;
};