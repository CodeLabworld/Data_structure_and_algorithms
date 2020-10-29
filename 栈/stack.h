#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//链式存储结构
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

//顺序存储结构
#define MAXSIZE 20
typedef struct SqStack
{
    int data[MAXSIZE]; //数据数组
    int top;           //栈顶标识
} SqStack;

//链式存储结构显示函数
//----------------------------------
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
//顺序存储结构显示函数
//------------------------------
void SqStackShow(SqStack &Q)
{
    printf("栈内数据显示如下：\n");
    int i;
    for (i = Q.top; i >= 0; i--)
    {
        printf("|%d|\n", Q.data[i]);
    }
}

//链式存储结构栈的初始化
//-----------------------------------------------------
void Initialization_linkstack(Linkstack &S)
{
    int num, i;
    printf("输入要输入数据的个数：");
    scanf("%d", &num);
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
    printf("----初始化完成----\n");
    LinkShow(S);
}

// //链式存储结构入栈函数
//--------------------------------------------------
void LinkPush(Linkstack &S)
{
    Linkstackptr s = (Linkstackptr)malloc(sizeof(StackNode));
    printf("输入入栈的数据：");
    scanf("%d", &s->data);
    s->next = S.top;
    S.top = s;
    S.count++;
    printf("----入栈成功----\n");
    LinkShow(S);
}

//链式存储结构出栈函数
//------------------------------------------------
void Linkpop(Linkstack &S)
{
    S.top = S.top->next;
    S.count--;
    printf("----出栈成功----\n");
    LinkShow(S);
}
//顺序存储结构栈的初始化
void Initialization_Sqstack(SqStack &Q)
{
    int i, num;
    printf("输入栈内数据个数：");
    scanf("%d", &num);
    printf("输入栈内数据：");

    for (i = 0; i < num; i++)
    {
        scanf("%d", &Q.data[i]);
    }
    Q.top = i - 1;
    printf("初始化完成\n");
    SqStackShow(Q);
}
//顺序存储结构入栈函数
void SqStack_push(SqStack &Q)
{
    if (Q.top == MAXSIZE - 1)
    {
        printf("栈满\n");
    }
    else
    {
        printf("输入入栈数据：");
        scanf("%d", &Q.data[Q.top + 1]);
        Q.top++;
        printf("入栈成功\n");
        SqStackShow(Q);
    }
}
//顺序存储结构出栈函数
void SqStack_pop(SqStack &Q)
{
    if (Q.top == -1)
    {
        printf("栈为空\n");
    }
    else
    {
        Q.top--;
        printf("出栈成功\n");
        SqStackShow(Q);
    }
}