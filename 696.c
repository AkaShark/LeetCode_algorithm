/*
 *
给定一个字符串 s，计算具有相同数量0和1的非空(连续)子字符串的数量，并且这些子字符串中的所有0和所有1都是组合在一起的。

重复出现的子串要计算它们出现的次数。

示例 1 :

输入: "00110011"
输出: 6
解释: 有6个子串具有相同数量的连续1和0：“0011”，“01”，“1100”，“10”，“0011” 和 “01”。

请注意，一些重复出现的子串要计算它们出现的次数。

另外，“00110011”不是有效的子串，因为所有的0（和1）没有组合在一起。
示例 2 :

输入: "10101"
输出: 4
解释: 有4个子串：“10”，“01”，“10”，“01”，它们具有相同数量的连续1和0。
注意：

s.length 在1到50,000之间。
s 只包含“0”或“1”字符。
*/
// 思路：寻找子串中相同数量的连续01
// 缺陷：没有理解题目意思 题目的意思是相同数目的0和1而且连续 不是子字符串需要有相同的01个数
// 思路：判断01和交接前有多少个0 或者1
// 思路：题目的本质就是去判断前面某个字符的个数和后面的那个字符的个数 在01连续处进行交换 根据前面和后面的个数取出最小的就是结果
// 参考：https://www.polarxiong.com/archives/LeetCode-696-count-binary-substrings.html
//      http://www.cnblogs.com/grandyang/p/7716150.html
/      https://blog.csdn.net/liuchonge/article/details/78452948
/*
解释:
这题乍看起来很复杂，但实际有一个很容易的解法。注意到题目条件，符合要求的子串需要“有相同数目的0和1”而且“0和1都是连续的”，举例来说，对于00110011，满足条件的子串只有01、0011、10、1100、01和0011，而00110011不满足条件。

既然如此，对于“当前位置”的数字来说，就只需要关注其“紧邻之前”有多少个相同数字，以及有多少个不同数字就好了。比如，当处理到00110时，对于最后一个0来说，只需要关注前面有没有1个1，这时10就是满足条件的子串；而当处理到001100时，对于最后一个0来说，它是第2个0，而其前面有2个1，这时1100就是满足条件的子串；再当处理到0011000时，对于最后一个0来说，它是第3个0，而其前面只有2个1，所以子串11000不满足条件。

综上，我们可以在处理每个数字时，记录下“紧邻之前”的不相同数字的个数，并进行比较，判断以此结尾的子串是否满足条件。这里来个更完整的例子。

001110010    prev = 0    cur = 0
0 01110010    prev = 0    cur = 1
0 0 1110010    prev = 0    cur = 2
00 1 110010    prev = 2    cur = 1    01
001 1 10010    prev = 2    cur = 2    0011
0011 1 0010    prev = 2    cur = 3
00111 0 010    prev = 3    cur = 1    10
001110 0 10    prev = 3    cur = 2    1100
0011100 1 0    prev = 2    cur = 1    01
00111001 0     prev = 1    cur = 1    10
*/
int countBinarySubstrings(char* s) {
    int result = 0;
    int prevLength = 0;
    int curLength = 1;
    for (int i = 1; i < strlen(s); ++i) {
        if (s[i] == s[i-1]){
            curLength ++;
        } else{
            prevLength = curLength;
            curLength = 1;
        }
        if (prevLength >= curLength){
            result++;
        }
    }
    return result;

}
