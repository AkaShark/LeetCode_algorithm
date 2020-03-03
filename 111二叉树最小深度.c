
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };
/*
给定一个二叉树，找出其最小深度。

最小深度是从根节点到最近叶子节点的最短路径上的节点数量。

说明: 叶子节点是指没有子节点的节点。
*/ 


// 存在问题不对

// 求树高
//  int TreeHigh(struct TreeNode *root){
//      if(!root){
//          return 0;
//      }
//      int l_hight = TreeHigh(root->left);
//      int r_hight = TreeHigh(root->right);
//      return (l_hight>=r_hight?l_hight:r_hight)+1;
//  }

// // 最小深度
// int minDepth(struct TreeNode* root){
//     if(!root) return 0; // 空
//     if((!root->left)&&(!root->right)) return 1; // 只有一个根节点
//     int l_hight,r_hight;
//     // 左子树高
//     l_hight = TreeHigh(root->left);
//     if(l_hight==0){
//         l_hight = 9999;
//     }else
//     {
//         l_hight++;
//     }
//     // 右子树高
//     r_hight = TreeHigh(root->right)+1;
//     if(r_hight == 0){
//         r_hight = 9999;
//     }
//     else
//     {
//         r_hight++;
//     }
//     // 判断
//     if(l_hight>=r_hight) return r_hight;
//     return l_hight;
// }

// 问题所在 当一个root的一个孩子为空（左子树为空或者右子树为空的时候）直接调用不空的高度就可以啦 如果调用了空的话肯定为1 就不正确了
// 解决问题的时候应该想去想对应的case
// 修改 （递归解决）
// case1:root为空
// case2：只用一个root左右都是空
// case3：左子树后者右子树为空

int minDepth(struct TreeNode* root){
    if(!root) return 0;
    if((!root->left)&&(!root->right)) return 1;
    if(!root->left) return minDepth(root->right)+1;
    if(!root->right) return minDepth(root->left)+1;
    int l_hight = minDepth(root->left);
    int r_right = minDepth(root->right);
    if(l_hight>=r_right) return r_right+1;
    return l_hight+1;
}