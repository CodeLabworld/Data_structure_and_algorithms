#include <stdio.h>
#include <malloc.h>
#include "queue.h"

//链式存储结构队列
//----------------------------------
//链式存储结构队列显示函数
void LinkQueueShow(LinkQueue &Q)
{
    QueuePtr u = Q.front->next;
    printf("队列数据如下：\n");
    while (1)
    {
        printf("%d-", u->data);
        u = u->next;
        if (u == Q.rear)
        {
            printf("%d", u->data);
            break;
        }
    }
    printf("\n");
}
//链式存储结构队列初始化
void Initialization_LinkQueue(LinkQueue &Q)
{
    int i, num;
    QueuePtr q = (QueuePtr)malloc(sizeof(QueueNode)); //定义头结点
    Q.front = q;
    Q.rear = q; //此时对头队尾都指向头结点，队列为空
    printf("输入队列数据个数：");
    scanf("%d", &num);
    printf("输入队列数据：");
    for (i = 0; i < num; i++)
    {
        QueuePtr p = (QueuePtr)malloc(sizeof(QueueNode)); //定义新节点
        q->next = p;
        Q.rear = p;
        scanf("%d", &p->data);
        q = q->next;
    }
    printf("队列初始化完成！\n");
    LinkQueueShow(Q);
}
//链式存储结构队列入队操作
void LinkQueue_Inter(LinkQueue &Q)
{
    QueuePtr p = (QueuePtr)malloc(sizeof(QueueNode));
    printf("输入入队的数据：");
    scanf("%d", &p->data);
    Q.rear->next = p;
    Q.rear = p;
    printf("入队成功！\n");
    LinkQueueShow(Q);
}
//链式存储结构队列出队操作
void LinkQueue_Out(LinkQueue &Q)
{
    QueuePtr p = Q.front->next;
    Q.front->next = p->next;
    free(p);
    printf("出队成功！\n");
    LinkQueueShow(Q);
}
//顺序存储结构队列
//----------------------------
//顺序存储结构队列显示函数
void SqQueueShow(SqQueue &S)
{
    printf("队列数据如下：\n");
    for (int i = S.front; i <= S.rear; i++)
    {
        printf("%d-", S.data[i]);
    }
    printf("\n");
}
//顺序存储结构队列初始化
void Initialization_SqQueue(SqQueue &S)
{
    int num;
    printf("输入队列的数据个数：");
    scanf("%d", &num);
    printf("输入队列的数据：");
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &S.data[i]);
    }
    S.front = 0;
    S.rear = num - 1;
    printf("队列初始化完成！\n");
    SqQueueShow(S);
}
//顺序存储结构队列入队操作
void SqQueue_Inter(SqQueue &S)
{
    printf("输入入队的数据：");
    scanf("%d", &S.data[S.rear + 1]);
    S.rear++;
    printf("入队成功！\n");
    SqQueueShow(S);
}
//顺序存储结构队列出队操作
void SqQueue_Out(SqQueue &S)
{
    S.data[S.front] = 0;
    S.front++;
    printf("出队成功！\n");
    SqQueueShow(S);
}