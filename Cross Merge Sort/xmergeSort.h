#define XMERGESORT_H
#define XMERGESORT_H


//This function is a variation of k-way merge sort, where k is 4 and the partitions are merged in a different order.
//First we divide arr in to 4 quarters and 4 recursive calls as follows:
//cross merge sort q1
//cross merge sort q2
//cross merge sort q3
//cross merge sort q4
//after sorting we merge q1 and q3 into h1, q2 to q4 into h2 then h1 and h2 to resulting array using merged procedure.
//comarison variable is for counting number of comparisons. This value passed by referenco to merged procedure.
int crossMergeSort(int *arr, long &comparison, int size);
void merged(int* firstArr, int* secondArr,int* destination ,int firstSize,int secondSize, long & comparison);


#endif;
