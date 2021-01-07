#include <algorithm>
#include <iostream>
#include <vector>

#include "tools.h"

using namespace std;

vector<int> quickSort(vector<int> input){
    int inputLength = input.size();
    if (((issorted(input) == 1) or (inputLength == 1))){    //recursive. if already sorted or 1 element, nothing to do.
        cout << "already sorted or input length 1" << endl;
        return input;
    }else{
        cout << "entered else block " << endl;
        int pivot = pickRandomIndex(input);
        int pivotValue = input[pivot];
        cout << "pivotIndex: " << pivot << endl;
        cout << "pivotValue: " << pivotValue << endl;

        vector<int> output(inputLength, 0);
        int smallerValueIndex = 0;
        int largerValueIndex = inputLength-1;
        int matchingpivots = 0;

        for (int i = 0; i < inputLength; i++){
            if (input[i] < pivotValue){
                output[smallerValueIndex] = input[i];
                smallerValueIndex += 1;
            }else if (input[i] > pivotValue){                                    //need this to catch the duplicate pivot condition
                output[largerValueIndex] = input[i];
                largerValueIndex -= 1;
            }else if (input[i] == pivotValue){
                matchingpivots += 1;
            }
            
        }
        for (int i = 0; i < matchingpivots; i++){
            output[smallerValueIndex] = pivotValue;                 //fill in pivot values 
            smallerValueIndex += 1;
        }

        vector<int> leftHalf(pivot+1, 0);
        vector<int> rightHalf(inputLength - (pivot + 1), 0);

        for (int i = 0; i < pivot; i++){
            leftHalf[i] = output[i];
        }
        for (int i = pivot; i < inputLength; i++){              //pivot can go left or right, doesn't matter
            rightHalf[i-pivot] = output[i];
        }

        //leftHalf = quickSort(leftHalf);
        coutVector(leftHalf);
        //rightHalf = quickSort(rightHalf);
        coutVector(rightHalf);

        
        //coutVector(output);  
        
    return output;
    }
};


int main(){
    //vector<int> inputvector = {4,5,6};
    //vector<int> inputvector = {4,6,4,2};
    vector<int> inputvector = {4,5,6,2};

    vector<int> sorted;
    sorted = quickSort(inputvector);
    //coutVector(sorted);



    return 1;
};
