/*
 * 给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。

案例:

s = "leetcode"
返回 0.

s = "loveleetcode",
返回 2.
 */
// 思路 首先是异常情况1.为空
// 变量字符串同时记录字母出现的次数以及index 利用数组(字母表 ) 字母转数字的时候出问题啦 找不到之前的代码了。。。不知道为啥错了 但是这个不用转化
// 最后判断的时候是变量s从字母表中找频率 这样就可以确定第一个不重复的字母了
// 或者利用两次循环去找 时间复杂度高
#include <stdlib.h>
int firstUniqChar(char* s) {
    if (strlen(s) < 1) {
        return -1;
    }
    int tempChar[26];
    for (int j = 0; j < 26; ++j) {
        tempChar[j] = 0;
    }
    for (int i = 0; i < strlen(s); ++i) {
        tempChar[s[i]-'a']++;
    }
    for (int k = 0; k < strlen(s); ++k) {
        if (tempChar[s[k]-'a'] == 1){
            return k;
        }
    }
    return -1;
}
