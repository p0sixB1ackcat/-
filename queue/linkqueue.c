#include <stdio.h>
#include <stdlib.h>


typedef struct _node
{
  int value;
  struct _node *next;
}node,*PNODE;

node *front = NULL;
node *rear = NULL;

//链式队列的创建
int createque(void)
{
  front = rear = NULL;
  return 1; 
}

//判断链式队列是否为空
int isqueueEmpty()
{
  if(front == NULL && rear == NULL)
  {
    return 1;
  }  
  return 0;
}

//链式队列的入队
int enqueue(int e)
{
  node *p = (node *)malloc(sizeof(node));
  p->next = NULL;
  p->value = e;
  if(isqueueEmpty())
  {
    front = rear = p;
    return 1;
  }
  rear->next = p;
  rear = p;
  return 1; 
}

//链式队列的出队
int delqueue(int *e)
{
  if(isqueueEmpty())
     return -1;
  if(!e)
    return -1;
  if(front == rear && rear)
  {
    *e = rear->value;
    free(rear);
    front = rear = NULL;
    return 1;
  }
  *e = front->value;
  node *q = front;
  front = front->next;
  free(q);
  q = NULL;
  return 1;
} 

//链式队列的遍历
void traverseQueue(void)
{
  
  while(!isqueueEmpty())
  {
    int value;
    delqueue(&value);
    printf("%d\t",value); 
  }
  printf("\n");
}

int main(int argc,char *argv[])
{
  
  int state = -1;
  if(isqueueEmpty())
    state = createque();
  int insertnum;
input:
  printf("please input insertnum to queue:");
  scanf("%d",&insertnum);
  if(insertnum <= 0)
  {
    goto input;
  }
  int i = 0;
  while(i < insertnum)
  {
    int tmp = rand()%10;
    enqueue(tmp);
    i++;
  }
  int value;
  delqueue(&value);
  printf("current front->value is %d\n",value);
  
  usleep(1000);
  printf("please input insert value:");
  scanf("%d",&value);
  enqueue(value);
  delqueue(&value);
  printf("current front->value is %d\n",value);
  traverseQueue();

  return 0;
}
