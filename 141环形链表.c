/*
给定一个链表，判断链表中是否有环。
为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
如果 pos 是 -1，则在该链表中没有环。
*/ 
#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int val;
    struct ListNode *next;
};

// 链表是否有环快慢指针判断 (判断成环的位置)
bool hasCycle(struct ListNode *head) {
    if(head==NULL){ //只有一个根节点
        return 0;
    }
    struct ListNode *p,*q;
	p=head;q=head;
	while(p->next!=NULL&&q->next!=NULL){
        // 相遇
		if(p->next==q->next->next){
			return 1;
		}
        // 快慢指针
		p=p->next;q=q->next->next;
        if(p==NULL||q==NULL){
            return 0;
        }
	}
	return 0;
}

// 确定环的入口
/*
  问题2：若存在环，如何找到环的入口点（即上图中的结点E）？
       解答：如图中所示，设链起点到环入口点间的距离为x，环入口点到问题1中fast与low重合点的距离为y，又设在fast与low重合时fast已绕环n周（n>0），且此时low移动总长度为s，则fast移动总长度为2s，环的长度为r。则
        s + nr = 2s,n>0      ①
        s = x + y               ②
       由①式得  s = nr                 
       代入②式得
       nr = x + y
       x = nr - y                ③
       现让一指针p1从链表起点处开始遍历，指针p2从encounter处开始遍历，且p1和p2移动步长均为1。则当p1移动x步即到达环的入口点，由③式可知，此时p2也已移动x步即nr - y步。由于p2是从encounter处开始移动，故p2移动nr步是移回到了encounter处，再退y步则是到了环的入口点。也即，当p1移动x步第一次到达环的入口点时，p2也恰好到达了该入口点。于是函数可写如下：
*/ 
// encounter是fast和slow相遇的点
struct LinkNode* findEntry(struct LinkNode* head, struct LinkNode* encounter)
{ 
	struct LinkNode *p1 = head;
    struct LinkNode *p2 = encounter;
	while(p1 != p2) // 根据上面公式的推到得到p1和p2相遇的位置就是环的入口
	{
        // 每次移动的步长为1
		p1 = p1->next;
		p2 = p2->next;
	}
	return p1; //返回p1p2一样的
}
    