#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAXSIZE 100

typedef struct _node
{
  int value;
  struct _node *next;
}node,*PNODE;

int Queue[MAXSIZE] = {0};
//当front = rear时，说明队列为空
int front = 0;//前端索引
int rear = 0;//后端索引

//创建一个循环队列
int createQueue(void)
{
  front = rear = 0;
  return 1;
}

//判断循环队列是否为空
int isQueueEmpty(void)
{
  return rear == front ? 1 : 0;
}

//判断循环队列是否为满
int isQueueFull(void)
{
  return (rear + 1) % MAXSIZE == front ? 1 : 0;
}

//循环队列的入队
int enQueue(int e)
{
  if(isQueueFull())
    return 0;
  Queue[rear] = e;
  rear = (rear + 1) % MAXSIZE;
  return 1;
}

//循环队列的出队
int delQueue(int *e)
{
  if(isQueueEmpty())
    return 0;
  if(e == NULL)
    return 0;
  *e = Queue[front];
  front = (front + 1) % MAXSIZE;
  return 1;
}

//循环队列的遍历
void traverseQueue(void)
{
  while(!isQueueEmpty())
  {
    int value;
    delQueue(&value);
    printf("%d ",value);
  }
  printf("\n");
}

int main(int argc,char *argv[])
{
 
  int state = createQueue();
  if(!state)
    _exit(-1);
  int i;
  for(i = 0; i < 200; i++)
  {
    enQueue(i);
  } 
  int value;
  delQueue(&value);
  printf("创建队列后删除的第一个数据:%d\n",value);
  delQueue(&value);
  printf("创建队列后删除的第二个数据:%d\n",value);
  usleep(1000);
  traverseQueue();
  return 0;
}
