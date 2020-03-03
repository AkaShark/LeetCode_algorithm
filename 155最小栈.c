#include<stdio.h>
#include<stdlib.h>
int isPop=0;
#define MAXSIZE 2000
typedef struct {
    int top; //栈顶指针
    int minValue; // 最小值
    int *value; //栈中是数值
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *obj = (MinStack *)malloc(sizeof(MinStack));
    obj->value = (int *)malloc(MAXSIZE *sizeof(int));
    obj->top = -1;
    obj->minValue = MAXSIZE;
    return obj;
}

void minStackPush(MinStack* obj, int x) {
    if (obj->top == MAXSIZE -1) //栈满了
    {
        /* code */
    }
    else
    {
        int top = obj->top;
        obj->value[++top] = x;
        obj->top = top;
        if (obj->minValue >= x)
        {
            obj->minValue = x;
        }
    }
}

void minStackPop(MinStack* obj) {
  if (obj->top == -1) //栈为空
  {
      /* code */
  }else
  {
      isPop =1;
      obj->top--;
  }
}

int minStackTop(MinStack* obj) {
  if (obj->top==-1)
  {
      /* code */
      return 0;
  }
  else
  {
      return obj->value[obj->top];
  }
}

int minStackGetMin(MinStack* obj) {
    if(isPop){
        int minValue = minStackTop(obj);
        int temp = obj->top;
        while (temp)
        {
            if (minValue>=obj->value[temp])
            {
                minValue = obj->value[temp];
            }
            temp--;
        }
        return minValue;
    }else{
        return obj->minValue;
    }
}

void minStackFree(MinStack* obj) {
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/