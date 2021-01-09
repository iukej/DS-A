#include <algorithm>
#include <iostream>
#include <vector>

#include "tools.h"

using namespace std;

vector<int> quickSort(vector<int> input){
    int inputLength = input.size();
    if (((issorted(input) == 1) or (inputLength == 1))){                                //recursive. if already sorted or 1 element, nothing to do.
        return input;
    }else{
        int pivot = pickRandomIndex(input);                                             //pick random pivot within list
        int pivotValue = input[pivot];
        //cout << "pivotIndex: " << pivot << " pivotValue: " << pivotValue << endl;

        vector<int> output(inputLength, 0);
        int smallerValueIndex = 0, largerValueIndex = inputLength-1, matchingpivots = 0;

        for (int i = 0; i < inputLength; i++){                                          
            if (input[i] < pivotValue){                                          //assign values < pivot Value from left side of array
                output[smallerValueIndex] = input[i];
                smallerValueIndex += 1;
            }else if (input[i] > pivotValue){                                    //assign values > pivot Value from right side of array
                output[largerValueIndex] = input[i];
                largerValueIndex -= 1;
            }else if (input[i] == pivotValue){                                   //Handle case where pivot has duplicate values
                matchingpivots += 1;
            }
        }

        int newPivotIndex = smallerValueIndex;
        for (int i = 0; i < matchingpivots; i++){
            output[newPivotIndex] = pivotValue;                                 //fill in pivot values 
            newPivotIndex += 1;
        }
        newPivotIndex -= 1;
         
        if ((newPivotIndex != 0) and (newPivotIndex != (inputLength - 1))){    //if pivot position not at either end, have two sides to put through quicksort
            vector<int> leftHalf(newPivotIndex,0);
            vector<int> rightHalf(inputLength - (newPivotIndex+1), 0);

           for (int i = 0; i < newPivotIndex; i++){
               leftHalf[i] = output[i];
               }

           for (int i = newPivotIndex + 1; i < inputLength; i++){       
               rightHalf[i-newPivotIndex - 1] = output[i];
               }
                                                                               //sort sides of the pivot 
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

        }else if (newPivotIndex == (inputLength - 1)){                      //if pivot position at right end, run left side through sort
            vector<int> leftHalf(newPivotIndex,0);     

            for (int i = 0; i < newPivotIndex; i++){
                leftHalf[i] = output[i];
                }

                                                                            
            leftHalf = quickSort(leftHalf);                                 //sort left side of pivot 

            int outputInserter = 0;
            for (int i=0; i < leftHalf.size(); i++){
                output[outputInserter] = leftHalf[i];
                outputInserter += 1;
            }
            output[outputInserter] = pivotValue;

        }else if (newPivotIndex == 0){                                      //if pivot position at left end, run right side through sort
            vector<int> rightHalf(inputLength-1,0);

            for (int i = 1; i < inputLength;i++){
                rightHalf[i-1] = output[i];
                }
                                                                             
            rightHalf = quickSort(rightHalf);                               //sort right side of pivot 

            int outputInserter = 0;
            output[outputInserter] = pivotValue;
            outputInserter += 1;

            for (int i=0; i < rightHalf.size(); i++){
                output[outputInserter] = rightHalf[i];
                outputInserter +=1;
            }
        }
    return output;
    }
};

vector<int> mergeSort(vector<int> input){
    int inputLength = input.size();
    if (((issorted(input) == 1) or (inputLength == 1))){                                //recursive. if already sorted or 1 element, nothing to do.
        return input;
    }else{
        //i'd like to do halves here, not random indices 

        int halfSize = input.size()/2;                                                 // int(a)/int(b) brings back quotient, ignoring remainder
        vector<int> leftHalf(input.begin(), input.begin() + halfSize);                 
        vector<int> rightHalf(input.begin() + halfSize, input.end());                  //https://stackoverflow.com/a/9811343
                                                                                       //can also just pass addresses with appropriate offsets bc vectors contiguous.

        leftHalf = mergeSort(leftHalf);                                                //checks if already sorted, if not, break down further.
        rightHalf = mergeSort(rightHalf);


        for(int i=0; i < input.size(); i++){ 
            if ((leftHalf.size() > 0) && (rightHalf.size() > 0)){                      //logic depending on wether arrays have members
                if (leftHalf[0] <= rightHalf[0]){                                      //if 0th element of righthalf < 0th of lefthalf, insert. lefthalf otherwise. 
                    input[i] = leftHalf[0];
                    leftHalf.erase(leftHalf.begin());                                  //remove 0th element from vector
                }else{
                    input[i] = rightHalf[0];
                    rightHalf.erase(rightHalf.begin());
                }
            }else if (leftHalf.size() > 0){
                    input[i] = leftHalf[0];
                    leftHalf.erase(leftHalf.begin());
            }else if (rightHalf.size() > 0){
                    input[i] = rightHalf[0];
                    rightHalf.erase(rightHalf.begin());
            }

        }
        return input;
    }
};

int main(){
    //vector<int> inputvector = {4,3,46,-7,345345,345,43,2,-5234,467,756,8568,4};
    vector<int> inputvector = {4,5,6,3,2,1};
    vector<int> outputvector;

    //outputvector = quickSort(inputvector);
    outputvector = mergeSort(inputvector);
    coutVector(outputvector);
    
    return 1;
};
