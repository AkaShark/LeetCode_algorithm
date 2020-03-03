/*
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
*/
 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

// 递归
int maxDepth(struct TreeNode* root){ 
    if (!root)
    {
        /* code */
        return 0;
    }
    // 左子树和右子树高
    int lMax = maxDepth(root->left);
    int rMax = maxDepth(root->right);
    return lMax>=rMax?(lMax:rMax)+1;
}

// 非递归 利用队列设置一个标记求树高，队列为空标记加1
int maxDepth(struct TreeNode *root){
    
    
}