#include<stdio.h>
#include<stdlib.h>
#include<math.h>
// 168逆问题 进制转化问题


// 循环
int titleToNumber(char * s){
    int len =1;
    long int sum =0;
    while (s[len]!='\0')
    {
        len++;
    }
    for (int i=1; i <= len; len--)
    {
        int temp = s[len-1]-'A'+1;
        if(len==1){
            sum +=temp;
        }
        else{
            sum += temp*pow(26,i);
        }
    }
    return sum;
}