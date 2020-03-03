/*给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。*/
 struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
// 1.递归2.前序遍历（非递归）判断值是否相等3.LeetCode上的方法用到了队列没看懂再查查
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (p==NULL && q==NULL) // 都为空返回
    {
        return true;
    }
    if (!p||!q) //不可能都是空的 一个空一个不空 返回
    {
        return false;
    }
    if (p->val == q->val) //值相等
    {
        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
    }    
    return true;
}
// 非递归前序遍历 吉谦求职
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    struct TreeNode strack1[1000]; // 定义栈（顺序栈）
    struct TreeNode strack2[1000];
    int top1 = 0; // 栈顶指针
    int top2 = 0; // 栈顶指针
    struct TreeNode *i，j; //工作指针
    while ((p&&q)||(!top1&&!top2))
    {
        while (p)
        {
            strack1[top1++] = p;
            p = p->left;
        }
        if (top1>0)
        {
            p = strack1[--top1];
        }
        while (q)
        {
            strack2[top2++] = q;
            q = q->left;
        }
        if (top2>0)
        {
            q = strack2[--top2];
        }
        if (q!=p)
        {
            return true;
        } 
        p = p->right;
        q = q->right; 
    }
    return false;
}


// 单纯的树的前序遍历
struct TreeNode* preOrder(struct TreeNode* p){
    struct TreeNode strack[100];//定义栈
    int top = 0; // 栈顶指针
    struct TreeNode *i=p; //工作指针
    while (p||!top)
    {
        /* code */
        while (p)
        {
            strack[top++] = p;//进栈
            p = p->left; //左边全部要进栈
        }
        if (top>0)//栈不空
        {
            /* code */
            p = strack[--top];//出栈
        }
        // 访问P
        p = p->right//切换到右边
    }
    
}