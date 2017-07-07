#include <stdio.h>
#include <stdlib.h>

//定义二叉树结构
typedef struct _btree
{
  int val;
  struct _btree *left;
  struct _btree *right;
}btree,*PBTREE;

//创建二叉树，递归
bree *create_tree(void)
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
  memset(0x0,p,sizeof(p));
  p->val = val;
  printf("please input left val of %d",val);
  p->left = create_tree();
  printf("please input right val of %d",val);
  p->right = create_tree();
  return p;
}

int main(int argc,char *argv[])
{

  
  return 0;
}
