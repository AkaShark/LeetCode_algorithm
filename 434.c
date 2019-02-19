/*
 *
 * 统计字符串中的单词个数，这里的单词指的是连续的不是空格的字符。

请注意，你可以假定字符串里不包括任何不可打印的字符。

示例:

输入: "Hello, my name is John"
输出: 5
 */
// case1.为空的情况 " "
// case2.中间存在两个空格的情况 abc  aaa
// case3.结尾为  的这样的话不可以算为一个字母
// 思路遍历字符串判断连续两个字符是不是空格 如果不是的话count++ 不对这样统计出来的大
// 思路 遍历看见空格判断前面的是否还是空格如果不是+1 利用了每个字母开头一定为空格的特性
int countSegments(char* s) {
    int count=0;
    int len = strlen(s);
    if (len < 1 && s[0] == '\0'){
        return 0;
    }
    for (int i = 0; i < len; i++) {
       char temp = s[i];
       if (temp == ' '){
           if (i>=1 && s[i-1] != ' '){
               count ++;
           }
       }

    }
    if (s[len-1] != ' '){
        count++;
    }
    return count;
}
