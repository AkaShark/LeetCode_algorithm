#include<stdio.h>
#include<math.h>
// 统计数组中可以组成三角型的个数
// int triangleNumber(int* nums, int numsSize){

// }
/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。
*/
// double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){


// }

/*
给定一个范围在  1 ≤ a[i] ≤ n ( n = 数组大小 ) 的 整型数组，数组中的元素一些出现了两次，另一些只出现一次。

找到所有在 [1, n] 范围之间没有出现在数组中的数字。

您能在不使用额外空间且时间复杂度为O(n)的情况下完成这个任务吗? 你可以假定返回的数组不算在额外空间内。
*/

// void findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
//     int tempArr[numsSize];
//     printf("%d",*returnSize);
//     for (int i = 0; i < numsSize; i++)
//     {
//         tempArr[nums[i]]++; 
//     }
//     for (int i = 0; i < numsSize; i++)
//     {
//         // printf("%d\n",tempArr[i]);
//     }
    
// }
/* 
2.给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
// */
// struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
//     ListNode *p,*q;
//     p = l1; q = l2;
//     int num1, num2;
//     int i = 0;
//     while (p->next!=NULL)
//     {
//         /* code */
//         int temp = p ->val;
//         num1 += temp*pow(10,i);
//     }
//     while (q->next!=NULL)
//     {
//         /* code */
//         int temp = q ->val;
//         num2 += temp*pow(10,i);
//     }
//     printf("%d-----%d",num1,num2);
    
// }

/*
    判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
*/
// bool isPalindrome1(int x){
//  if (x<0)
//  {
//      return false;
//  }
//  int sum = 0;
//  int num = x;
//  while (x!=0)
//  {
//      sum = sum * 10 + x %10;
//      printf("%d",sum);
//      x/=10;
//  }
//  if (sum != num)
//  {
//      return false;
//  }
//  return true;
// }

/*
    将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
*/
//  struct ListNode {
//       int val;
//       struct ListNode *next;
// };
// struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
//     // 异常处理
//     if (l1 == NULL)
//     {
//         return l2;
//     }
//     if (l2 == NULL)
//     {
//         return l1;
//     }
//     // 声明
//     struct ListNode *p = l1;
//     struct ListNode *q;
//     // 全部合并进q（l1）
//     while (p->next!=NULL)
//     {
//         p = p->next;
//     }
//     p->next = l2;
//     // 冒泡排序
//     int temp;
//     for (p=l1; p; p=p->next)
//     {
//         struct ListNode *ptr; //前一个元素
//         for (q=p->next; q; q=q->next)
//         {
//             /* code */
//             ptr=p;
//             if (ptr->val>q->val) //大于交换
//             {
//                 // swap
//                 temp = q->val; 
//                 q->val = p->val;
//                 p->val = temp;
//             }
//             else
//             {
//                 ptr = q;
//             }
//         }
//     }
//     return l1;
// }
/*
    计算并返回 x 的平方根，其中 x 是非负整数。

   由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
   牛顿法 
*/
// int mySqrt(int x){
    
//     int small = 1;
//     while (small<x)
//     {
//         int j = small * small;
//         if (j>x)
//         {
//             return small-1;
//         }
//         small++;
//     }
//     return 0;
// }

/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。
*/
// 递归 效率低
// int climbStairs(int n){
//     return countNum(0,n);    
// }
// int countNum(int i,int n ){
//     // 当前比总数还大
//     if (i>n)
//     {
//         return 0;
//     }
//     // 上一步
//     if (i==n)
//     {
//         return 1;
//     }
//     return countNum(i+1,n)+countNum(i+2,n);

// }
// 动态规划 斐波那契数列
// int climbStairs(int n){
//     if (n<3)
//     {
//         return n ;
//     }
//     int p = 1; //走两步
//     int q = 2; //走一步
//     for (int i = 0; i < n-2; i++) //n-2为pq为第一步第二步
//     {
//         int t = p+q; // 当前需要的可走的步数
//         p = q;
//         q = t;
//     }
//     return q;
// }

// 加记忆数组的递归
// int climbStairs(int n){
//     int i , a[999];
//     if (n == 1)
//     {
//         return 1;
//     }
//     if (n == 2)
//     {
//         return 2;
//     }
//     a[0] = 0;
//     a[1] = 1;
//     a[2] = 2;
//     for (int i = 3; i < n; i++)
//     {
//         /* code */
//         a[i] = a[i-1]+a[i-2];
//     }
//     return a[n];
// }
/*
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
*/
//  struct ListNode {
//      int val;
//      struct ListNode *next;
// };

// struct ListNode* deleteDuplicates(struct ListNode* head){
//     struct ListNode *pre, *current;
//     pre = head;// 前驱指针
//     current = head ->next;// 工作指针
//     while (current!=NULL)
//     {
//         // 判断相邻的是否值的大小同
//         if (pre->val == current->val)
//         {
//             /* 如果相同则工作指针向后移动 前驱不要动 */
//             current = current->next;
//         }else
//         {
//             // 不相同则前驱和工作指针一起动
//             pre = current;
//             current = current->next;
//         }
//     }
//     // 返回链表的头结点
//     return head;
// }

int main(){

}
