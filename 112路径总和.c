/*给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。*/ 

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 二叉树的问题大部分都可以利用递归解决（或者用栈实现迭代）
// 递归实现
// 思路：判断根节点是否是空的如果为空直接返回false，否则sum-root->val递归调用下面的节点直到最后判断叶子节点是否是sum
bool hasPathSum(struct TreeNode* root, int sum){
   if (!root) return false; //如果只有根节点为空的话返回false
   if ((sum==root->val)&&!root->left&&!root->right) //叶子节点等于sum
   {
       return true;
   }
   int diff = sum - root->val;
   return (hasPathSum(root->left,diff) || hasPathSum(root->right,diff));
    
}

// 利用栈迭代实现
// 栈的思路:根节点进栈判断是否满足root->val是否等于sum，如果满足而且是叶子节点返回true，否则出栈，左子树右子树进栈

// LeetCode 思路
/*所以我们从包含根节点的栈开始模拟，剩余目标和为 sum - root.val。
然后开始迭代：弹出当前元素，如果当前剩余目标和为 0 并且在叶子节点上返回 True；如果剩余和不为零并且还处在非叶子节点上，将当前节点的所有孩子以及对应的剩余和压入栈中。
*/
bool hasPathSum(struct TreeNode* root, int sum){
    
}