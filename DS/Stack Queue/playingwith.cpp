#include <iostream>
/**/

/*
int x;
x = 52;  This doesn't work in this language, only way to set a global variable is like this int x = 52.
*/

struct testStruct{
    char data[20];
};


int main(){
    //int x;
    //x = 42;
    //std::cout << "main function";
    //std::cout << "42";

    std::string greeting = "hello";
    int stringsize = greeting.length();
    
    char buffer[20];

    for (int i = 0; i < stringsize; i++){
        buffer[i] = greeting[i];
    }
    //std::cout << buffer;

    int* pointer;   //can't store address here and derefenerece it unless declaring pointer. won't have
                    //the ability to work with it.
     
    // https://stackoverflow.com/a/2704176. No difference between:
    // int* ptr;
    // int * ptr;
    // int  *ptr;
    // The compiler strips white spaces, so these are all pointers to element ptr, of type int. nice.
    // same thing in C https://stackoverflow.com/a/4203080

    //int value = 45;

    //pointer = &value;
    //std::cout << *pointer;
    
    testStruct * tester;    
    tester->data[0] = 'h';
    tester->data[1] = 'e';
    tester->data[2] = 'y';
    std::cout << tester->data;


}
