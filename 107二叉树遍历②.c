/*给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）*/
#define MAXS 1024
struct TreeNode {
    int val;
    struct TreeNode *left;     
    struct TreeNode *right;
};
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int front;
    int rear;
    struct TreeNode *stack[MAXS] = {NULL};
    struct TreeNode *p;
    int **ret;
    int i;
    int len;
    int j;
    int temp;
    int *tem;
    front = rear = 0;
    *returnColumSize = (int *)malloc(sizeof(int) * MAXS);
    if (root==NULL)
    {
        return NULL;
    }
    rear ++;
    stack[rear] = root;
    ret = (int **)malloc(sizeof(int *)*MAXS);
    while (front<rear)
    {
        /* code */
        len = rear - front;
        *(* returnColumnSizes+*returnSize) = len;
        for (int i = 0; i < len; i++)
        {
            front = (front+1)%MAXS;
            p = stack[front];
            ret[*returnSize][i] = p->val;
            if (p->left!=NULL)
            {
                rear = (rear+1)%MAXS;
                stack[rear] = p->left;
            }
            if (p->right!=NULL)
            {
                rear = (rear+1)%MAXS;
                stack[rear]=p->right;
            }
        }
        (*returnSize)++;
    }
    i = 0;
    j = *returnSize-1;
    while (i<j)
    {
        temp = *(*returnSize +i);
        *(*returnSize+j) = temp;
        tem = ret[i];
        ret[j] = tem;
        i++;
        j--;
    }
    return ret;
}