/*
  线索化二叉树链式存储结构，中序线索化链表
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _btree
{
  int val;
  char lefttag;
  char righttag;
  struct _btree *left;
  struct _btree *right;
}btree,*PBTREE;

void inthreading(btree *);

//遍历中序线索化链表
void traverse_tree(btree *h)
{
  btree *p = h->left;
  while(p != h)
  {
    while(p->lefttag == 0x00)
      p = p->left;
    printf("节点%d\n",p->val);
    while(p->righttag == 0x01 && p->right != h)
    {
      p = p->right;
      printf("节点%d\n",p->val);
    }
    p = p->right; 
  }
}

btree *pre = NULL;

//将二叉树中序线索化
btree * thread(btree *t)
{
  btree *h = (btree *)malloc(sizeof(btree));
  if(!h)
    return NULL;
  //初始化双向线索化链表头
  h->lefttag = 0x00;//左线索域为0，因为他的左子树为整个二叉树，并不是指向空
  h->righttag = 0x01;//右线索域要指向后继，直接设置为0x01
  // 由于头节点的后继需要在线索化结束后，找到中序遍历的最后一个节点，所以这里暂将h的后继回指
  h->right = h;
  if(!t)
  {
    h->left = h;//如果二叉树为空，则左指针回指
  }
  else
  {
    h->left = t;
    pre = h;
    inthreading(t);
    h->right = pre;
    pre->right = h;
    pre->righttag = 0x01;//线索化后，中序遍历的最后一个节点的左右子树都为空，他的前驱在线索化结束前已经设置好，后继需要在结束后设置
  }
  return h;
}

void inthreading(btree *p)
{
  if(p)
  {
    inthreading(p->left);
    if(p->left == NULL)
    {
      p->lefttag = 0x01;
      p->left = pre;
    }
    if(pre->right == NULL)
    {
      pre->righttag = 0x01;
      pre->right = p;
    }
    pre = p;
    inthreading(p->right);
  } 
}

//创建一个二叉树
btree *create_tree(void)
{
  int val;
  scanf("%d",&val);
  if(!val)
    return NULL;
  btree *t = (btree *)malloc(sizeof(btree));
  if(!t)
    return NULL;
  memset(t,0x0,sizeof(btree));
  t->val = val;
  printf("请输入节点%d的左子节点:",val);
  t->left = create_tree();
  printf("请输入节点%d的右子节点:",val);
  t->right = create_tree();

  return t; 
}

int main(int argc,char *argv[])
{
  btree *t = create_tree();
  if(!t)
    exit(-1);
    
  //在主函数中初始化pre
  pre = (btree *)malloc(sizeof(btree));
  if(!pre)
    exit(-1);
    
  btree *h = thread(t);
  traverse_tree(h);
  return 0;
}
