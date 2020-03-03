#include<stdlib.h>
#include<stdio.h>
// 容易造成溢出 思路错了 
int trailingZeroes(int n){
    int num = factorial(n);
    int count = 0;
    while (num>0)
    {
        int tail = num % 10;
        if (tail==0)
        {
            count++;
        }else
        {
            return count;
        }
        num /= 10;
    }
    return count;
}

int factorial(int n){
    int factorial = 1;
    for (int i = 1; i <= n; i++)
    {
        factorial *= i;
    }
    return factorial;
}

// 统计 n /5 的个数 具体看笔记这个题 2*5=10 一个0 
int trailingZeroes(int n){
    int count = 0;
    while (n>0)
    {
        count = n/5;
        n /= 5; 
    }
    return count;
}
