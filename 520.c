/*
 给定一个单词，你需要判断单词的大写使用是否正确。

我们定义，在以下情况时，单词的大写用法是正确的：

全部字母都是大写，比如"USA"。
单词中所有字母都不是大写，比如"leetcode"。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
否则，我们定义这个单词没有正确使用大写字母。

示例 1:

输入: "USA"
输出: True
示例 2:

输入: "FlaG"
输出: False
注意: 输入是由大写和小写拉丁字母组成的非空单词。
 */
// 思路：题目给出的信息很明确判断给出的单词是否是正确的大小写 根据给定的条件做判断就好了 大小写的判断可以根据ASCII码值
// case0: 只有一个字母的情况
// case1: 多个字母是否符合上述条件
// case2: 对于首字母的判断进行区分 如果首字母大写的话 分为全部大写以及后面的都是小写的情况
// 缺陷：对于只有一个字母的情况 理解错误 时间空间复杂度`高
//bool detectCapitalUse(char* word) {
//    if (strlen(word)<2){
//        if (word[0]>=65&&word[0]<97){ // 只有一个字母并且为大写的情况
//            return true;
//        } else{
//            return false;
//        }
//    }
//    if (word[0]>=65&&word[0]<97){ // 首字母大写
//        if (word[1]>=65&&word[1]<97){ // 第二个字母大写？
//            for (int i = 2; i < strlen(word); ++i) {
//                if (word[i]>=97){ //小写
//                    return false;
//                }
//            }
//            return true;
//        } else{ // 第二个字母小写
//            for (int i = 2; i < strlen(word); ++i) {
//                if (word[i]>=65&&word[i]<97){ //大写
//                    return false;
//                }
//            }
//            return true;
//        }
//    } else {
//        for (int i = 0; i < strlen(word); ++i) {
//            if (word[i]>=65&&word[i]<97){ //大写
//                return false;
//            }
//        }
//        return true;
//    }
//}
//// 本质找出大小写的交替的个数 问题 判断差值的时候判断条件 更改直接判断大小写 同时记得判断关于交替的位置
// 优化程度不大 根据index以及just判断大写字母的位置 本质出现了不同的字母后判断位置解决问题
bool detectCapitalUse(char* word) {
    int just = 0;
    int index = 0;
    for (int i = 0; i < strlen(word)-1; ++i) {
        if ((word[i]>=65&&word[i]<97&&word[i+1]>=97)||(word[i+1]>=65&&word[i+1]<97&&word[i]>=97)){
            just++;
            index = i;
        }
    }
    if (just==1){
        if (index==0){
            return true;
        } else{
            return false;
        }
    }
    if (just == 0){ return true;}
    else { return false;}
}
