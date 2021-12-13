#include "xmergesort.h"

void merged(int* firstArr, int* secondArr,int* destination ,int firstSize,int secondSize, long & comparison){
    
    int i = 0,
        j = 0,
        k = 0;

    while(i < firstSize && j < secondSize){
        comparison++;
        if(firstArr[i] <= secondArr[j])
            destination[k++] = firstArr[i++];
        else
            destination[k++] = secondArr[j++];
    }
    while(i < firstSize) destination[k++] = firstArr[i++];
    while(j < secondSize) destination[k++] = secondArr[j++];   
}

int crossMergeSort(int *arr, long &comparison, int size)
{
	  int num_of_calls=1;
    if(size == 1){
        return 1;
    }
    if(size == 2 && arr[0] >= arr[1]){
        int tmp = arr[0];
        arr[0] = arr[1];
        arr[1] = tmp;
    }
    if(size == 2){
        comparison++;
    }
    else{
        int step = size / 4;
        num_of_calls += crossMergeSort(arr,comparison,step) + crossMergeSort(arr + step,comparison,step)
                        + crossMergeSort(arr + step*2,comparison,step) + crossMergeSort(arr + step * 3,comparison,step);
        int* h1 = new int[step*2];
        merged(arr,arr+step*2,h1,step,step,comparison);
        int* h2 = new int[step*2];
        merged(arr + step,arr + step*3,h2,step,step,comparison);
        merged(h1,h2,arr,step*2,step*2,comparison);
        delete h1;
        delete h2;
    }
	return num_of_calls;
}
