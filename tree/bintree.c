#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义二叉树结构
typedef struct _btree
{
    int val;
    struct _btree *left;
    struct _btree *right;
}btree,*PBTREE;

//模拟一个栈,链表
typedef struct _node
{
  int val;
  struct _node *next;
  btree *b;
}node,*PNODE;

//初始化栈为空
node *stack = NULL;

//判断栈是否为空
int stackEmpty(void)
{
  return stack == NULL ? 1 : 0; 
}

//入栈
void push(btree *b)
{
  node *q = (node *)malloc(sizeof(node));
  if(!q)
    return;
  memset(q,0x0,sizeof(node));
  q->next = NULL;
  q->b = b;
  if(stackEmpty())
  {
    stack = q;   
  }
  else
  {
    q->next = stack;
    stack = q; 
  } 
}

//出栈
int pop(btree **b)
{
  if(stackEmpty())
    return -1;
  node *p = stack;
  (*b) = p->b;
  stack = stack->next;
  free(p);
  p = NULL;
  return 1;
}

//中序遍历二叉树，非递归
int inordernotcursive(btree *b)
{
    if(b == NULL)
        return -1;
    while(b || !stackEmpty())
    {
        if(b)
        {
            push(b);
            b = b->left;
        }
        else
        {
            //btree *b;这里为啥要重新这样定义？没事找事。。。
            pop(&b);
            if(b == NULL)
            {
                printf("出栈错误\n");
                return -1;
            }
            printf("%d ",b->val);
            b = b->right;
        }
    }
    return 0;
}

//中序遍历，递归
int inorder(btree *p)
{
    if(p == NULL)
        return -1;
    inorder(p->left);
    printf("%d ",p->val);
    inorder(p->right);
    return 0;
}

//创建二叉树，递归
btree *create_tree(void)
{
  int val;
  printf("please input current node val:\n");
  scanf("%d",&val);
  if(val == 0)//如果输入0，那么表示结束当前节点的根节点继续往下分支
  {
    return NULL;
  }
  btree *p = (btree *)malloc(sizeof(btree));
  if(!p)
    return NULL;
  memset(p,0x0,sizeof(btree));
  p->val = val;
  printf("please input left val of %d",val);
  p->left = create_tree();
  printf("please input right val of %d",val);
  p->right = create_tree();
  return p;
}

int main(int argc,char *argv[])
{
  btree *root = create_tree();
    inorder(root);
    printf("\n");
    printf("非递归遍历:");
    inordernotcursive(root);
    printf("\n");
  return 0;
}
