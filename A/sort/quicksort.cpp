#include <iostream>
#include <vector>

#include "checksorted.h"

using namespace std;

vector<int> quickSort(vector<int> input){
    if ((issorted(input) == 1)){
        return input;
    }
};



int main(){
    vector<int> testing = {4,5,6};
   // bool retval = checksorted::issorted(testing);
    //bool retval = issorted(testing);
    cout << "is sorted: " << retval << endl;
    return retval;
};
