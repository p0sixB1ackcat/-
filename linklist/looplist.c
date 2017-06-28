#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node{
  int val;
  struct _node * next;
}node, *PNODE;

//循环链表的销毁
void destroy_loop_list(node *h)
{
  node *p = h;
  do
  {
    node *q = p;
    p = p->next;
    free(q);
    q = NULL;
  }while(p!=h);
}

//循环链表的遍历
void traverse_loop_list(node *h)
{
  node *p = h;
  do
  {
    printf("0x%x:%d\n",p->next,p->val);
    p = p->next; 
  }while(p != h);
  printf("\n");
}

node *create_list_loop(void)
{
  node *h = NULL;
  while(1)
  {
    node * p = (node *)malloc(sizeof(node));
    if(!p)
      return NULL;
    memset(p,0x0,sizeof(node));
    printf("please input vals:");
    scanf("%d",&p->val);
    
    p->next = NULL;
    if(!h)
    {
      h = p;
      p->next = h;
    }
    else
    {
      node * q = h;
      while(q->next != h)
      {
        q = q->next; 
      }
      q->next = p;
      p->next = h;
    }
    if(!p->val)
      break;   
  
  }
  return h;
}

int main(int argc,char *argv[])
{
  node * p = create_list_loop();
  node * h = p;
  /*
  while(p->next != h)
  {
    printf("%d ",p->val);
    p = p->next;
  }
  printf("%d ",p->val);
  free(p);
  p = NULL;
  printf("\n");
  */
  traverse_loop_list(h);
  destroy_loop_list(h);
}
