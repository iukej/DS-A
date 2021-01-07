#include <algorithm>
#include <iostream>
#include <vector>

#include "tools.h"




using namespace std;





// come back to this












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

        int newPivotIndex = smallerValueIndex;
        for (int i = 0; i < matchingpivots; i++){
            output[newPivotIndex] = pivotValue;                 //fill in pivot values 
            newPivotIndex += 1;
        }

        newPivotIndex -= 1;

        cout << "newPivotIndex: " << newPivotIndex << endl;
         
        vector<int> leftHalf(newPivotIndex,0);
        vector<int> rightHalf(inputLength - (newPivotIndex+1), 0);

        for (int i = 0; i < newPivotIndex; i++){
            leftHalf[i] = output[i];
        }
        leftHalf = quickSort(leftHalf);

        for (int i = newPivotIndex + 1; i < inputLength; i++){       
            rightHalf[i-newPivotIndex - 1] = output[i];
        }
        rightHalf = quickSort(rightHalf);

        

        coutVector(leftHalf);
        coutVector(rightHalf);
       // if ((newPivotIndex != 0) and (newPivotIndex != (inputLength - 1))){
       //     vector<int> leftHalf(newPivotIndex,0);
       //     vector<int> rightHalf(inputLength - (newPivotIndex+1), 0);

       //    for (int i = 0; i < newPivotIndex; i++){
       //        leftHalf[i] = output[i];
       //    }
       //    leftHalf = quickSort(leftHalf);

       //    for (int i = newPivotIndex + 1; i < inputLength; i++){       
       //        rightHalf[i-newPivotIndex - 1] = output[i];
       //    }
       //    rightHalf = quickSort(rightHalf);

       //    

       //    coutVector(leftHalf);
       //    coutVector(rightHalf);
       // }

        //vector<int> leftHalf(smallerValueIndex-1,0);
        //vector<int> rightHalf(inputLength - (smallerValueIndex), 0);

       //for (int i = 0; i < smallerValueIndex; i++){
       //    leftHalf[i] = output[i];
       //}
       //for (int i = smallerValueIndex; i < inputLength; i++){       //pivot can go left or right, doesn't matter
       //    rightHalf[i-smallerValueIndex] = output[i];
       //}

//        coutVector(leftHalf);
//        coutVector(rightHalf);
//        coutVector(output);
          

        
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
