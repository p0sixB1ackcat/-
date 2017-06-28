#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _dnode{

  int val;
  struct _dnode *pre;
  struct _dnode *next;

}dnode,*DNODE;

void traverse_doublelist(dnode *h)
{
  dnode *p = h;
  while(p)
  {
    printf("0x%x<---0x%x--->0x%x:%d\n",p->pre,p,p->next,p->val);
    p = p->next;
  }
  
}

dnode *create_doublelist_tail(void)
{
  dnode *h = NULL;
  while(1)
  {
    dnode *p = (dnode *)malloc(sizeof(dnode));
    if(!p)
      return NULL;
    memset(p,0x0,sizeof(dnode));
    p->pre = p->next = NULL;
    printf("please input vals:");
    scanf("%d",&p->val);
    if(!h)
      h = p;
    else
    {
      dnode *q = h;
      while(q->next)
        q = q->next;
      q->next = p;
      p->pre = q;
      
    }
    if(!p->val)
      break;  
  }
  return h;
}

dnode* create_doublelist_head(void)
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
    }
    else
    {
      p->next = h;
      h->pre = p;
      h = p;     
    }
    if(!p->val)
      break;
  }
  return h; 
}


int main(int argc,char *arg[])
{
  dnode *h = create_doublelist_head();
  traverse_doublelist(h);
  h = create_doublelist_tail();
  traverse_doublelist(h);
  return 0;
}
