#include <stdio.h>
#include <stdlib.h>


typedef struct _node
{
  int value;
  struct _node *next;
}node,*PNODE;

node *top = NULL;

//栈的创建
int createStack(void)
{
  top = NULL;
  return 1;
}

//判断栈中是否为空
int isStackEmpty(void)
{
  return top == NULL ? 1 : 0;
}

//入栈
int pushStack(int data)
{
  node *p = (node *)malloc(sizeof(node));
  if(!p)
    return 0;
  p->value = data;
  p->next = NULL;
  if(isStackEmpty())
  {
    top = p;
    return 1;
  }
  p->next = top;
  top = p;
  return 1;

}

//出栈
int popStack(int *data)
{
  if(isStackEmpty() && data == NULL)
    return 0;
  if(top->next == NULL)
  {
    *data = top->value;
    free(top);
    top = NULL;
    return 1;
  }
  node *p = top;
  top = top->next;
  *data = p->value;
  free(p);
  p = NULL;
  return 1;
}

//栈的遍历
void traverseStack(void)
{
  while(!isStackEmpty())
  {
    int value;
    popStack(&value);
    printf("%d ",value);
  }
  printf("\n");
}

int main(int argc,char *argv[])
{
  int state = createStack();
  int i;
  for(i = 0; i < 100; i++)
  {
    pushStack(i);
  } 
  popStack(&i);
  printf("frist pop data is %d\n",i);
  traverseStack();
  return 0;
}
