#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 0x400
int Stack[MAXSIZE] = {0x0};
int top = 0x0;

//创建基于数组的栈
int createStack(void)
{
  top = 0;
  return 1;
}

//判断栈中是否为空
int isStackEmpty(void)
{
  return top == 0 ? 1 : 0;
}

//判断栈中是否已满
int isStackFull(void)
{
  return top == MAXSIZE ? 1 : 0;
}

//入栈
int pushStack(int data)
{
  if(isStackFull())
    return 0;
  Stack[top] = data;
  top++;
  return 1;
}

//出栈
int popStack(int *data)
{
  if(isStackEmpty() || data == NULL)
    return 0;
  top--;
  *data = Stack[top];
  return 1;
}

//遍历基于数组结构的栈
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
  for(i = 0; i < 0x200; i++)
  {
    pushStack(i);
  }

  popStack(&i);
  printf("frist pop stack data is : %d\n",i);
  printf("剩下的数据是:\n");
  traverseStack();
  return 0;
}
