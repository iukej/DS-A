#include <cstdlib>
//note, cstdlib and stdlib.h not same, stdlib.h deprecated as well
#include <iostream>
#include <time.h>
#include <vector>   

#include "tools.h"

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

void coutVector(vector<int> input){
    cout << "vector: " << endl;
    for(int i = 0; i < input.size(); i++){
        cout << input[i] << " ";
    }
    cout << endl;
};


int pickRandomIndex(vector<int> input){
    //srand(time(NULL));
    //srand(3);
    srand(4);
    int randomIndex = rand() % input.size();
    return randomIndex;
};

