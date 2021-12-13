#include "qs.h"

int classPartition(unsigned short *arr,int size, long &swap,double &avg_dist, double &max_dist){
    unsigned short pivot = arr[size - 1];
    int i = -1;
    for(int j = 0;j < size - 1;j++){
        if(arr[j] >= pivot){
            i++;
            unsigned short swapTmp = arr[i];
            arr[i] = arr[j];
            arr[j] = swapTmp;
            
            double currDistance = (j - i);
            if(currDistance < 0)
                currDistance*=(-1);
                
            if(currDistance > max_dist)
                max_dist = currDistance;
            
            double prvDistTotal = swap * avg_dist;
            swap++;
            avg_dist = (prvDistTotal + currDistance) / swap;

        }
    }   
    
    unsigned short swapTmp = arr[i + 1];
    arr[i + 1] = arr[size - 1];
    arr[size - 1] = swapTmp;
    double currDistance = i + 1 - size + 1;
    if(currDistance < 0)
        currDistance*=(-1);
    if(currDistance > max_dist)
                max_dist = currDistance;
                
    double prvDistTotal = swap * avg_dist;
    swap++;
    avg_dist = (prvDistTotal + currDistance) / swap;
    return i + 1;
    
}

int hoarePartition(unsigned short *arr,int size, long &swap,double &avg_dist, double &max_dist){
    
    unsigned short pivot = arr[(size - 1)/2];
    int i = -1;
    int j = size;
    
    while(true){
        
        do{
            j--;
        }while(arr[j] < pivot);
        
        do{
            i++;
        }while(arr[i] > pivot);
        
        if(i < j){
            unsigned short swapTmp = arr[i];
            arr[i] = arr[j];
            arr[j] = swapTmp;
            
            
            double currDistance = (j - i);
            if(currDistance < 0)
                currDistance*=(-1);
                
            if(currDistance > max_dist)
                max_dist = currDistance;
            
            double prvDistTotal = swap * avg_dist;
            swap++;
            avg_dist = (prvDistTotal + currDistance) / swap;
        }
        else{
            return j;
        }
        
    }
}

void quickSort(unsigned short* arr, long &swap, double & avg_dist, double & max_dist, bool hoare, int size)
{
   
    if(!hoare){
        
        if(size > 1){
            int p = classPartition(arr,size,swap,avg_dist,max_dist);
            quickSort(arr,swap,avg_dist,max_dist,hoare,p);
            quickSort(arr + (p+1), swap,avg_dist,max_dist,hoare,size - p - 1);
        }
    }
    else{
        if(size > 1){
            int p = hoarePartition(arr,size,swap,avg_dist,max_dist);
            quickSort(arr,swap,avg_dist,max_dist,hoare,p + 1);
            quickSort(arr + p + 1, swap,avg_dist,max_dist,hoare,size - p -1);
        }
        
    }
}

void partition3Way(unsigned short * arr, long& swap, long& comparison,int size, int& L, int& R){
    int i = 0;
    int j = 0;
    int p = size - 1;
    
    while(i < p){
        if(arr[i] > arr[size -1]){
            unsigned short swapTmp = arr[i];
            arr[i] = arr[j];
            arr[j] = swapTmp;
            swap++;
            i++;
            j++;
            comparison++;
            
        }
        else if(arr[i] == arr[size -1]){
            p--;
            comparison+=2;
            unsigned short swapTmp = arr[i];
            arr[i] = arr[p];
            arr[p] = swapTmp;
            swap++;
        }
        else{
            i++;
            comparison+=2;
        }
        
    }
    
    int n;
    if(p - j < size -p)
        n = p - j;
    else
        n = size - p;
    
    for(int iter = j;iter < j+n;iter++){
        unsigned short swapTmp = arr[iter];
        arr[iter] = arr[size -j -n + iter];
        arr[size -j -n + iter] = swapTmp;
        swap++;
    }
    
    L = j;
    R = p - j;
}

void quickSort3(unsigned short *arr, long &swap, long &comparison, int size) {
    int L,R;
    if (size > 1){
        partition3Way(arr,swap,comparison,size,L,R);
        quickSort3(arr,swap,comparison,L);
        quickSort3(arr + size - R,swap,comparison,R);
    }
}
