#ifndef RADIX-SORT_H
#define RADIX-SORT_H

int encode(int l,std::string str,int currStrIndex);
void subRoutine(std::string arr[], int size, int currStrIndex, int l,int &val);
int radixSort(std::string arr[], bool ascending, int n, int l);

#endif
