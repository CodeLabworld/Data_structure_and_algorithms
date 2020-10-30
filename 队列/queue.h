#include <stdio.h>

//链式存储结构队列数据结构
typedef struct QueueNode
{
    int data;
    struct QueueNode *next;
} QueueNode, *QueuePtr;

typedef struct Queue
{
    QueuePtr front, rear; //定义对头队尾指针
} Queue;

//链式存储结构队列
//----------------------------------
//链式存储结构队列显示函数
void LinkQueueShow()

    //链式存储结构队列初始化
    void Initialization_LinkQueue()

    //链式存储结构队列入队操作
    void LinkQueue_Inter()

    //链式存储结构队列出队操作
    void LinkQueue_Out()

    //顺序存储结构队列
    //----------------------------
    //顺序存储结构队列显示函数
    void SqQueueShow()
    //顺序存储结构队列初始化
    void Initialization_SqQueue()
    //顺序存储结构队列入队操作
    void SqQueue_Inter()
    //顺序存储结构队列出队操作
    void SqQueue_Out()