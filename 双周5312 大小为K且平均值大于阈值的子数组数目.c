#include<stdio.h>
#include<stdlib.h>
int ava(int *arr,int size){
    int sum=0,avarage=0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    
    avarage = sum/size;
    return avarage;
}

int numOfSubarrays(int* arr, int arrSize, int k, int threshold){
    int count = 0;
    for (int i = 0; i < arrSize; i++)
    {
        int temp[k];
        int tempindex = i;
        if(i+k>arrSize){
            return count;
        }
        for (int j = 0; j < k; j++)
        {
            temp[j] = arr[tempindex];
            tempindex++;
            int avarage = ava(temp,k);
            if (avarage >= threshold)
            {

                count++;
            }
            
        }       
    }
    return count;
    
}
int main(int argc, char const *argv[])
{
    int array[] = {2,2,2};
    int avarage = ava(array,3);
    printf("%d",avarage);
    return 0;
}
