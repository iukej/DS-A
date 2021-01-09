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
         
        if ((newPivotIndex != 0) and (newPivotIndex != (inputLength - 1))){
            vector<int> leftHalf(newPivotIndex,0);
            vector<int> rightHalf(inputLength - (newPivotIndex+1), 0);

           for (int i = 0; i < newPivotIndex; i++){
               leftHalf[i] = output[i];
               }

           for (int i = newPivotIndex + 1; i < inputLength; i++){       
               rightHalf[i-newPivotIndex - 1] = output[i];
               }

           leftHalf = quickSort(leftHalf);
           rightHalf = quickSort(rightHalf);

           int outputInserter = 0;
           for (int i = 0; i < leftHalf.size(); i++){
               output[outputInserter] = leftHalf[i];
               outputInserter += 1;
           }

           output[outputInserter] = pivotValue;
           outputInserter += 1;

            
           for (int i = 0; i < rightHalf.size(); i++){
               output[outputInserter] = rightHalf[i];
               outputInserter += 1;
           }

            return output;
           //coutVector(leftHalf);
           //coutVector(rightHalf);
        }else if (newPivotIndex == (inputLength - 1)){
            //in this case, we don't want the right half. off by one errors.
            vector<int> leftHalf(newPivotIndex,0);

            for (int i = 0; i < newPivotIndex; i++){
                leftHalf[i] = output[i];
                }
            //cout << "split off left half" << endl;
            //coutVector(leftHalf);

            leftHalf = quickSort(leftHalf);

            int outputInserter = 0;
            for (int i=0; i < leftHalf.size(); i++){
                output[outputInserter] = leftHalf[i];
                outputInserter += 1;
            }
            output[outputInserter] = pivotValue;


            return output;
            //cout << "split off left half after resort" << endl;
            //coutVector(leftHalf);
        }else if (newPivotIndex == 0){
            vector<int> rightHalf(inputLength-1,0);

            for (int i = 1; i < inputLength;i++){
                rightHalf[i-1] = output[i];
                }
            cout << "split off right half" << endl;
            coutVector(rightHalf);

            rightHalf = quickSort(rightHalf);

            int outputInserter = 0;
            output[outputInserter] = pivotValue;
            outputInserter += 1;

            for (int i=0; i < rightHalf.size(); i++){
                output[outputInserter] = rightHalf[i];
                outputInserter +=1;
                   
            }


            //cout << "split off right half after resort" << endl;
            coutVector(rightHalf);
            return output;

        }
          

        
    return output;
    }
};


int main(){
    //vector<int> inputvector = {4,5,6};
    //vector<int> inputvector = {4,6,4,2};
    vector<int> inputvector = {4,3,46,7,345345,345,43,2,5234,467,756,8568,4};
    //vector<int> inputvector = {4,5,6,2};

    //vector<int> sorted;
    //while (issorted(inputvector) != 1){
    //inputvector = quickSort(inputvector);
    //}
    //coutVector(inputvector);

    vector<int> outputvector;
    outputvector = quickSort(inputvector);
    coutVector(outputvector);



    return 1;
};
