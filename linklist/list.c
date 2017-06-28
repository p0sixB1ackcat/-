#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct _node{

  int val;
  struct _node *next;

}node, *PNODE;

node * create_linklist_q()
{
  node * h = NULL;
  while(1)
  {
    node * p = (node *)malloc(sizeof(node));
    if(!p)
    {
      return NULL;
    }
    memset(p,0x0,sizeof(node));
    p->next = NULL;
    printf("please input vals:");
    scanf("%d",&p->val);
    if(!p->val)
      break;
    if(!h)
    {
      h = p;
    }
    else
    {
      node * q = h;
      //注意这里的判断条件，并不是q是否存在，而是q的next是否存在，比如，当第一次输入9时，q虽然不为NULl，但他的next仍然为NULL，所以不会执行q = q->next，而是将p给了q->next，所以不会将第一个h覆盖掉
      while(q->next)
      {
        q = q->next;
      }
      q->next = p;
      p->next = NULL;

    } 
  }
  return h;
}

node* create_linklist_h(void)
{
  node *h = NULL;
  while(1)
  {
    node * p = (node *)malloc(sizeof(node));
    if(!p)
      return NULL;
    printf("please input vals:");
    scanf("%d",&p->val);
    
    //这里如果没有置为NULL，则会引发段错误
    p->next = NULL;
    if(!p->val)
      break;
    if(!h)
    {
      h = p;
    }
    else
    {
      //主要问题在这里，如果上面没有将p->next置为NULL，那么这里将会访问非法内存？或者是访问了不在同一内存页的内存了？
      printf("p-next oldaddress is 0x%p,h is 0x%x\n",p->next,h);
      p->next = h;
      h = p;
    }
    
  }

  return h;
}

int main(int argc,char *argv[])
{
  node * p = create_linklist_h();
  
  while(p)
  {
    printf("p->valis %d ",p->val);
    usleep(1000);
    p = p->next; 
  }
  free(p);
  p = NULL;
  printf("\n");
  
  p = create_linklist_q();
  while(p)
  {
    printf("%d ",p->val);
    p = p->next;
  }
  printf("\n");
  free(p);
  p = NULL;
  return 0;
}
