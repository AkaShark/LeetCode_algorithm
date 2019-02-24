示例 1：

输入： A = "ab", B = "ba"
输出： true
示例 2：

输入： A = "ab", B = "ab"
输出： false
示例 3:

输入： A = "aa", B = "aa"
输出： true
示例 4：

输入： A = "aaaaaaabc", B = "aaaaaaacb"
输出： true
示例 5：

输入： A = "", B = "aa"
输出： false


提示：

0 <= A.length <= 20000
0 <= B.length <= 20000
A 和 B 仅由小写字母构成。*/
// 思路：利用双指针遍历 判断B中的后面一个字符是否和A中的前一个字符相等 （index）
// 异常：长度不等直接返回false
// 欠缺：前两个符号后面的不符合了 不指交换两个 不交换的情况 前后字母一样的情况 不一定是连续的

#include "stdbool.h"
bool buddyStrings(char* A, char* B) {
    int temp = 0;
    if (strlen(A) != strlen(B)){
        return false;
    }
    for (int i = 0; i < strlen(A); ++i) {
        if (A[i] == B[i+1]){
            if(A[i] == B[i] && strlen(A)<3){
                return true;
            }
            if (A[i+1] == B[i] && A[i] != B[i]){ //出现重复的情况
                temp++;
                continue;
            }
        }
    }
    if (temp > 1 || temp == 0){ // 不交换以及交换多次
        return false;
    }
    return true;
}
