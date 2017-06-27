#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _dnode{

  int val;
  struct _dnode *pre;
  struct _dnode *next;

}dnode,*PDNODE;

//销毁
void destroy_looplinklist(dnode *h)
{
  dnode *p = h;
  do
  {
    dnode *q = p;
    p = p->next;
    free(q);
    q = NULL;
  }while(p != h);
}

//删除一个指定节点，指定条件为数据域val
void del_looplinklist(dnode *h,int indexval)
{
  dnode *p = h;
  dnode *q = h;
  while(q->val != indexval)
  {
    p = q;
    q = q->next;
  }
  p->next = q->next;
  q->next->pre = p;
  free(q);
  q = NULL;
  
}


//遍历
void traverse_looplinklist(dnode *h)
{
  dnode *p = h;
  do
  {
    printf("0x%x<---0x%x--->0x%x:%d\n",p->pre,p,p->next,p->val);
    p = p->next;
  }while(p != h);
}

//创建链表，从尾部插入
dnode *create_looplinklist_tail(void)
{
  dnode *h = NULL;
  while(1)
  {
    dnode *p = (dnode *)malloc(sizeof(dnode));
    if(!p)
      return NULL;
    memset(p,0x0,sizeof(dnode));
    printf("please input vals:");
    scanf("%d",&p->val);
    p->pre = p->next = NULL;
    if(!h)
    {
      h = p;
      p->pre = h;
      p->next = h;
    }
    else
    {
      dnode *q = h;
      while(q->next != h)
        q = q->next;
      p->pre = q;
      p->next = h;
      q->next = p;
      h->pre = p;
      
    }
    if(!p->val)
      break;
  }
  return h;
}


//创建循环双向链表，从头部插入
dnode * create_looplinklist_head(void)
{
  dnode *h = NULL;
  while(1)
  {
    dnode *p = (dnode *)malloc(sizeof(dnode));
    if(!p)
      return NULL;
    memset(p,0x0,sizeof(dnode));
    printf("please input vals:");
    scanf("%d",&p->val);
    p->pre = p->next = NULL;
    
    if(!h)
    {
      h = p;
      p->pre = h;
      p->next = h;
    }
    else
    {
      dnode *q = h;
      while(q->next != h)
      {
        q = q->next;
      }
      p->pre = q;
      p->next = h;
      q->next = p;
      h->pre = p;
      h = p;
    }
    if(!p->val)
      break;
  }
  return h;
}

int main(int argc,char *argv[])
{
  dnode *h = create_looplinklist_head();
  traverse_looplinklist(h);
  destroy_looplinklist(h);
  h = create_looplinklist_tail();
  traverse_looplinklist(h);
  printf("\n\n");
  del_looplinklist(h,4);
  traverse_looplinklist(h);
  printf("\n\n");
  destroy_looplinklist(h);
  traverse_looplinklist(h);
  return 0;
}
