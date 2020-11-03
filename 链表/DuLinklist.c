#include <stdio.h>
#include <malloc.h>
#include "DuLinklist.h"

void Creat_DuLinklist(DuLinklist &L)
{
    int num;
    L = (DuLinklist)malloc(sizeof(DuNode)); //整个链表
    DuLinklist r = L;                       //定义一个“移动的标识”
    L.prior = L;
    L.next = L;
    printf("输入双向链表数据个数：");
    scanf("%d", &num);
    printf("输入双向链表的数据：");
    for (int i; i < num; i++)
    {
        DuLinklist p = (DuLinklist)malloc(sizeof(DuNode)); //定义新节点
        scanf("%d", &p->data);
        r->next = p;
        p->prior = r;
        r = p;
    }
    r->next = NULL;
    printf("创建双向链表成功！\n");
}

void Traverse_DuLinklist(DuLinklist &L)
{
}