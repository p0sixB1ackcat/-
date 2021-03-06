#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _dnode{

  int val;
  struct _dnode *pre;
  struct _dnode *next;

}dnode,*PDNODE;


void insert_doublelooplinklist1(dnode **h,int index,dnode *q)
{
    dnode *p = *h;
    do
    {
        if(p->val == index)
        {
            p->pre->next = q;
            q->pre = p->pre;
            q->next = p;
            if(p == *h)
                *h = q;
            return;
        }
        p = p->next;
    }while(p != *h);
}

//旧的函数
void insert_doublelooplinklist(dnode *h,int index,dnode *p)
{
  dnode *q = h;
  while(q->next != h)
  {
    if(q->val == index)
      break;
    q = q->next;
  }
  p->pre = q->pre;
  p->next = q;
  q->pre->next = p;
  q->pre = p;
}


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
void del_doublelooplinklist(dnode **h,int val)
{
    //因为是双向循环链表，所以不需要再另外定义一个指针来指向每次遍历后的节点的上一个节点了
    dnode *p = *h;
    do
    {
        if(p->val == val)
        {
            p->pre->next = p->next;
            p->next->pre = p->pre;
            if(p == *h)
            {
                //如果p为头结点，那么要重新设置头结点，否则下面将当前头结点释放，不在链表里，while将不会退出循环
                (*h) = (*h)->next;
            }
            free(p);
            p = NULL;
            return;
        }
        p = p->next;
        
    }while(p != h);
}


//旧的函数
void del_looplinklist(dnode **h,int indexval)
{
  if(!h)
    return;
   
  dnode *p = *h;
  dnode *q = NULL;  
  
  do//这里要用do...while，而不是while
  {
    if(p->val == indexval)
    {
      if(p == *h)
      {
        (*h)->next->pre = (*h)->pre;
        (*h)->pre->next = (*h)->next;         
        *h = (*h)->next;
      }
      else
      {
        q->next = p->next;
        p->next->pre = q; 
      }
      free(p);
      p = NULL;
      return;
    }
    q = p;
    p = p->next;
    
  }while(p != *h); 
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
  h = create_looplinklist_tail();
  traverse_looplinklist(h);
  int index;
  printf("please input del node val:");
  scanf("%d",&index);
  printf("删除一个节点后的链表:\n");
  del_doublelooplinklist(&h,index);
  //del_looplinklist(&h,index);
  traverse_looplinklist(h);
    
  printf("please input insert node val in linklist:");
  scanf("%d",&index);
  int val;
  printf("please input new node val:");
  scanf("%d",&val);
  dnode *p = (dnode *)malloc(sizeof(dnode));
  p->pre = p->next = NULL;
  p->val = val;
  //insert_doublelooplinklist(h,index,p);
  insert_doublelooplinklist1(&h,index,p);
  printf("插入后的链表:\n");
  traverse_looplinklist(h);
  printf("销毁后的链表:\n");
  destroy_looplinklist(h);
  traverse_looplinklist(h);
  return 0;
}
