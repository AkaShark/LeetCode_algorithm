#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000
int BigNumMult(char num1[],char num2[],int sum){
    int i,j,len,len1,len2;
    int numA[MAX+10] = {0};
    int numB[MAX+10] = {0};
    int numRes[MAX*2+10] = {0};
    len1 = strlen(num1);
    for ( j = 0 ,i=len1-1;i>=0; i--)
    {
        numA[j++] = num1[i]-'0';
    }
    len2 = strlen(num2);
    for (j= 0,i=len2-1;i>=0;i--)
    {
        numB[j++] = num2[i]-'0';
    }
    for ( i = 0; i < len2; i++)
    {
        for (j= 0; j<len1; j++)
        {
            numRes[i+j] = numB[i] *numA[j];
        }
    }
    for (i = 0; i <MAX*2 ; i++)
    {
        if (numRes[i]>=10)
        {
            numRes[i+1] += numRes[i]/10;
            numRes[i] %=10;
        }
        
    }
    for (i=MAX*2;numRes[i]==0 &&i>=0; i--){

    }
    len = i+1;
    for ( ;i>=0; i--)
    {
        sum[i] = numRes[i];
    }
}