#include<stdio.h>
#include<stdlib.h>

int numberOfSteps (int num){
    int setpCount = 0;
    while (num>0)
    {
        if (num%2==0)
        {
            num /=2;
        }
        else
        {
            num -= 1;
        }
        setpCount++;
    }
    return setpCount++;
}

