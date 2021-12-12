#ifndef QS_H
#define QS_H

//This function handles classical partition in classical quick sort function.
//swap variable is for number of swaps in classicalPartiton.
//avg_dist variable is for avarage distance between swap positions.
//max_dist variable is for maximum distance between swapped positions.
int classPartition(unsigned short *arr,int size, long &swap,double &avg_dist, double &max_dist);

//This function handles hoare partition in classical quick sort function.
//swap variable is for number of swaps in hoarePartition 
//avg_dist variable is for avarage distance between swap positions.
//max_dist variable is for maximum distance between swapped positions.
int hoarePartition(unsigned short *arr,int size, long &swap,double &avg_dist, double &max_dist);

//Classical quick sort function.
//Here variables swap, avg_dist and max_dist is passed by reference to partition which is determined by hoare variable.
void quickSort(unsigned short* arr, long &swap, double & avg_dist, double & max_dist, bool hoare, int size);


//This function handles  3-way partition in 3-way quick sort function.
//swap variable is for number of swaps in partition3Way 
//comparison variable is for number of comparisons during partition3Way procedure.
void partition3Way(unsigned short * arr, long& swap, long& comparison,int size, int& L, int& R);

//3-way quick sort function
//Here variables swap, swap and comparison is passed by reference to partition3Way
void quickSort3(unsigned short *arr, long &swap, long &comparison, int size);


#endif
