#include<stdio.h>
#include<stdlib.h>

// 思路错了
// char * convertToTitle(int n){
//     int flag = 0;
//     char result;
//     while (n>=26)
//     {
//         n = n-26;
//     }
//     for (int i = 0; i < flag; i++)
//     {
//         /* code */
//         result = result+'A';
//     }
//     // 可以写成数组
//     switch (n)
//     {
//     case 1:
//         result+'A';
//         break;
//     case 2:
//         result+'B';
//         break;
//     case 3:
//         result+'C';
//         break;
//     case 4:
//         result+'D';
//         break;
//     case 5:
//         result+'E';
//         break;
//     case 6:
//         result+'F';
//         break;
//     case 7:
//         result+'G';
//         break;
//     case 8:
//         result+'H';
//         break;
//     case 9:
//         result+'I';
//         break;
//     case 10:
//         result+'J';
//         break;
//     case 11:
//         result+'Q';
//         break;
//     case 12:
//         result+'L';
//         break;
//     case 13:
//         result+'M';
//         break;
//     case 14:
//         result+'N';
//         break;
//     case 15:
//         result+'O';
//         break;
//     case 16:
//         result+'P';
//         break;
//     case 17:
//         result+'Q';
//         break;
//     case 18:
//         result+'R';
//         break;
//     case 19:
//         result+'S';
//         break;
//     case 20:
//         result+'T';
//         break;
//     case 21:
//         result+'U';
//         break;
//     case 22:
//         result+'V';
//         break;
//     case 23:
//         result+'W';
//         break;
//     case 24:
//         result+'X';
//         break;
//     case 25:
//         result+'Y';
//         break;
//     case 26:
//         result+'Z';
//         break;
//     default:
//         break;
//     }
//     return result;
// }

// int main()
// {
//     printf("%s",convertToTitle(1)); 
//     return 1;
// }

// 循环的思路
char * convertToTitle(int n){
    // 申明一个字符数组
    char tmp[100];
    int count = 0; // 个数
    while (n){
        n --;
        tmp[count++] = n%26 +'A'; //整数转字符
        n /= 26;
    }

    char *res = (char *)malloc((count+1) * sizeof(char));
    for (int i = count-1; i >= 0; i--)
        res[count-1-i] = tmp[i];
    res[count] = '\0'; //字符
    return res;
}