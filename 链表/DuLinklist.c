#include <malloc.h>
#include "DuLinklist.h"

//尾插法创建双向链表
void Creat_DuLinklist(DuLinklist &L)
{
    int num;
    L = (DuLinklist)malloc(sizeof(DuNode)); //整个链表
    DuLinklist r = L;                       //定义一个“移动的标识”
    L->prior = L;
    L->next = L;
    printf("输入双向链表数据个数：");
    scanf("%d", &num);
    printf("输入双向链表的数据：");
    for (int i = 0; i < num; i++)
    {
        DuLinklist p = (DuLinklist)malloc(sizeof(DuNode)); //定义新节点
        scanf("%d", &p->data);
        r->next = p;
        p->prior = r;
        r = p;
    }
    r->next = NULL;
    printf("创建双向链表成功！\n");
    Traverse_DuLinklist(L);
}

//遍历双向链表
void Traverse_DuLinklist(DuLinklist &L)
{
    DuLinklist p;
    p = L->next;
    printf("该双向链表内的数据如下：");
    while (p != NULL)
    {
        printf("%d--", p->data);
        p = p->next;
    }
    printf("\n");
}

//删除指定数据
void Delet_data(DuLinklist &L)
{
    int elem;
    int sign = 0;
    DuLinklist p;
    p = L->next;
    printf("输入要删除的数据：");
    scanf("%d", &elem);
    while (p != NULL)
    {
        if (elem == p->data)
        {
            p->prior->next = p->next;
            p->next->prior = p->prior;
            printf("删除完成！\n");
            sign = 1;
            free(p);
        }
        p = p->next;
    }
    if (sign == 0)
    {
        printf("删除的元素不存在!\n");
    }
    else
    {
        Traverse_DuLinklist(L);
    }
}