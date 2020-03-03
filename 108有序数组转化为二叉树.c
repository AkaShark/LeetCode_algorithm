/*将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。

本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。*/
#include<stdlib.h>
#include<stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// 分治
struct TreeNode* helper(int* nums,int left, int right){
    if (left>right)
    {
        /* code */
        return NULL;
    }
    struct TreeNode *t;
    t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int middle = (left+right)/2;
    t->val = nums[middle];
    t->left = helper(nums,left,middle-1);
    t->right = helper(nums,middle+1,right);
    return t;
}

// struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
//     return helper(nums, 0, numsSize - 1);
// }
#define MaxSize 1000
// 中序遍历赋值+层序遍历

// 中序遍历
void InOrder(struct TreeNode *root,int *nums,int *i){
    if (root!=NULL)
    {
        /* code */
        InOrder(root->left,nums,i);
        root->val = nums[(*i)++]; // 赋值
        InOrder(root->right,nums,i);
    }
}


struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize<=0)
    {
        /* code */
        return NULL;
    }
    struct TreeNode *root,*p,*q,*qu[MaxSize];
    int rear = 0 , front = 0, count = 1;
    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left = root->right = NULL;
    rear = (rear+1) % MaxSize;
    qu[rear] = root; // root入队列
    //  构造一个完全二叉树 root是树
    while (count<numsSize)
    {
        // 出队
        front = (front+1) % MaxSize;
        p = qu[front];
        q = (struct TreeNode *)malloc(sizeof(struct TreeNode));
        p->left = q;
        q->left = q->right = NULL;
        rear = (rear+1) % MaxSize;
        // 入队
        qu[rear] = q;
        count++;
        if (count < numsSize)
        {
            /* 入队 */
            q = (struct TreeNode *)malloc(sizeof(struct TreeNode));
            p->right = q;
            q->left = q->right =NULL;
            rear = (rear+1) % MaxSize;
            qu[rear] = q;
            count ++;
        }
    }
    // 从根开始
    count = 0;
    // 中序赋值
    InOrder(root,nums,&count);
    // 返回构造好的二叉树
    return root;
}
