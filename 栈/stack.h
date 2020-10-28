#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct StackNode //定义栈中结点
{
    int data;               //数据
    struct StackNode *next; //指向下一个的指针
} StackNode, *Linkstackptr;

typedef struct Linkstack //定义整个链式栈
{
    Linkstackptr top; //栈顶指针
    int count;        //栈内数据个数
} Linkstack;

//链式存储结构栈的初始化
void Initialization_linkstack(Linkstack &S)
{
    int num, i;
    printf("输入要输入数据的个数：");
    scanf("%d", &num);
    printf("\n");
    printf("输入数据：");
    for (i = 0; i < num; i++)
    {
        Linkstackptr s = (Linkstackptr)malloc(sizeof(StackNode));
        scanf("%d", &s->data);
        if (i >= 1)
        {
            s->next = S.top;
        }
        else
        {
            s->next = NULL;
        }
        S.top = s;
    }
    S.count = num;
    printf("初始化完成\n");
    LinkShow(S)
}
// //链式存储结构入栈函数
// void linklist_push()
// //链式存储结构出栈函数
// void linklist_pop()
// //链式存储结构显示函数
void LinkShow(Linkstack &S)
{
    int i;
    Linkstackptr p;
    p = S.top;
    printf("栈内数据如下:\n");
    for (i = 0; i < S.count; i++)
    {
        printf("|%d|\n", p->data);
        p = p->next;
    }
}
// //顺序存储结构栈的初始化
// void Initialization_sqstack()
// //顺序存储结构入栈函数
// void sqstack_push()
// //顺序存储结构出栈函数
// void sqstack_pop()