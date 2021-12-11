#include "radix-sort.h"
/*
    arr       : array to be sorted
    ascending : true for ascending, false for descending 
    n         : number of elements in the array
    l         : the number of characters used in counting sort at each time
*/
int encode(int l,std::string str,int currStrIndex){
    int calc = 0;
    for(int i = l; i > 0;i--)
        calc += ((((int)(str[currStrIndex - l + i])) - 65) * pow(26,l - i));
    
    return calc;
}

void subRoutine(std::string arr[], int size, int currStrIndex, int l,int &val){
    if(currStrIndex >= l);
    else l = currStrIndex + 1;
    
    int countArrSize = pow(26,l);
    int *cArr = new int[countArrSize];
    std::string *outArr = new std::string[size];

    for(int i = 0;i < countArrSize;i++){
        cArr[i] = 0;
        val++;
    }
    
    for(int j = 0;j < size;j++){
        cArr[encode(l,arr[j],currStrIndex)]++;
        val++;
    }
    
    for(int i = 1;i < countArrSize;i++)
        cArr[i]+=cArr[i - 1];
    
    for(int i = size - 1;i >= 0;i--){
        outArr[--cArr[encode(l,arr[i],currStrIndex)]] = arr[i];
        val++;
    }

    for(int i = 0; i < size;i++){
        arr[i] = outArr[i];
        val++;
    }

    delete [] cArr;
    delete [] outArr;
}
int radixSort(std::string arr[], bool ascending, int n, int l){
    int digitSize = arr[0].length();
    int returnVal = 0;
    int i = digitSize;
    for(;i > 0;i-=l)
        subRoutine(arr,n,i - 1,l,returnVal);
    
    if(!ascending){
        for(int i = 0;i < n / 2;i++){
            std::string tmp = arr[n - 1 - i];
            arr[n - 1-i] = arr[i];
            arr[i] = tmp;
        }
    }
    
    return returnVal;       
}
