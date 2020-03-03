
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*给定一个二叉树，检查它是否是镜像对称的。*/
// 递归 处理
bool isMirror(struct TreeNode* p, struct TreeNode* q)
{
    // 递归条件
    if(!p && !q) // 左右都是空
        return 1;
    if(!p || !q) // 左右有一个为空
        return 0;
    
    if(p->val == q->val) // 根相等
        return isMirror(p->left, q->right) && isMirror(p->right, q->left);
    else
        return 0;
}

bool isSymmetric(struct TreeNode* root){
    return isMirror(root, root);
}

// 迭代 队列
bool isSymmetric(struct TreeNode* root){

}

int main (){

}