#include<stdio.h>
#include<stdlib.h>
struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。
*/
// AVL的平衡因子只能是-1，0，1

// 求树高
int TreeHight(struct TreeNode *root){
    if(!root) return 0;
    int l_hight = TreeHight(root->left);
    int r_hight = TreeHight(root->right);
    return l_hight>=r_hight?(l_hight:r_hight)+1;
}

bool isBalanced(struct TreeNode* root){
    if(!root) return true;
    int l_hight = TreeHight(root->left);
    int r_hight = TreeHight(root->right);
    if(l_hight-r_hight>1||r_hight-l_hight>1){
        return false;
    }
    return isBalanced(root->left) && isBalanced(root->right);
}

