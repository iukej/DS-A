#include <iostream>
#include <vector>   

#include "checksorted.h"

/* https://stackoverflow.com/a/38228651 */ // "when you see code using std::vector without corresponding #include, that code is broken.
/* and more https://stackoverflow.com/a/38229711 */ //"only part of of vector is built into standard
/* "the definition of std::vector is in <vector>. ok, that's it.
"The compiler only know its language, c++, not its standard library"  */

using namespace std;


bool issorted(vector<int> input){
    bool sorted = true;
    int vectorlength = input.size();
    if (vectorlength > 1){
        for (int i = 1; i  < vectorlength;  i ++){
            if (input[i] < input[i-1]){
                sorted = false;
            }
        }
    }

    return sorted;
};


//int main(){
//    //vector<int> test = {1, 3, 6};
//    //vector<int> test = {4, 3, 6};
//    vector<int> test = {4, 5, 999};
//    bool val = issorted(test);
//    cout << "sorted return: " << val << endl;
//    return val;
//};
