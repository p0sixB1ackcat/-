//
//  main.m
//  linkList
//
//  Created by rongbei-wuxian on 2018/4/4.
//  Copyright © 2018年 rongbei-wuxian. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node
{
    struct _node *next;
    int value;
    
}node,*pnode;


void freelinklist(node *h)
{
    while(h)
    {
        node *p = h;
        h = h->next;
        free(p);
        p = NULL;
    }
}

//遍历，从后续结点遍历
void TraverseForBlink(node *h)
{
    node *p = h;
    node *flink = NULL;
    while(p)
    {
        printf("node->address is %p,node->value is %d\n",p,p->value);
        if(!flink)
        {
            flink = p;
            p = p->next;
        }
        else
        {
            node *tmp = p;
            p = (node *)((long)p->next ^ (long)flink);
            flink = tmp;
        }
        
    }
}

//模拟双向链表，前驱遍历
void TraverseForFlink(node *h)
{
    node *p = h;
    node *flink = NULL;
    while(p)
    {
        if(!flink)
        {
            flink = p;
            p = p->next;
        }
        else
        {
            node *tmp = p;
            p = (node *)((long)p->next ^ (long)flink);
            flink = tmp;
        }
    }
    //printf("flink->value is %d\n",flink->value);
    
    
    node *blink = NULL;
    
    while(flink)
    {
        printf("flink->value is %d\n",flink->value);
        node *tmp = flink;
        //*****(long)
        flink = (node *)((long)flink->next ^ (long)blink);
        blink = tmp;
    }
}

node * create(void)
{
    node *h = NULL;
    
    while(1)
    {
        node *p = (node *)malloc(sizeof(node));
        if(!p)
        {
            printf("malloc faild\n");
            return NULL;
        }
        
        memset(p, 0x00, sizeof(node));
        p->next = NULL;
        printf("please input node->value:");
        scanf("%d",&p->value);
        if(!p->value)
        {
            free(p);
            p = NULL;
            break;
        }
        
        if(!h)
        {
            h = p;
        }
        else
        {
            h->next = (node *)((long)p ^ (long)h->next);//从尾部插入结点
            //所以，在这里设置他的next的next，即p1->next = p0 ^ p2
            p->next = h;
            h = p;
        }
        
    }
    
    h->next = (node *)(0 ^ (long)h->next);
    
    
    return h;
    
}




int main(int argc, const char * argv[]) 
{       
    pnode h = create();
        
    TraverseForFlink(h);
        
    return 0;
}
