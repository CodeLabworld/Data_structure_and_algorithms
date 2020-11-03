#ifndef QUEUE_H
#define MAXSIZE 20
//链式存储结构队列数据结构
typedef struct QueueNode //定义结点
{
    int data;               //数据
    struct QueueNode *next; //后续指针
} QueueNode, *QueuePtr;

typedef struct Queue //定义整个队列
{
    QueuePtr front, rear; //定义对头队尾指针
} LinkQueue;

//顺序存储结构队列数据结构
typedef struct SqQueue
{
    int data[MAXSIZE];
    int front;
    int rear;
} SqQueue;

//链式存储结构队列
//----------------------------------
//链式存储结构队列显示函数
void LinkQueueShow(LinkQueue &Q);
// 链式存储结构队列初始化
void Initialization_LinkQueue(LinkQueue &Q);
//链式存储结构队列入队操作
void LinkQueue_Inter(LinkQueue &Q);
//链式存储结构队列出队操作
void LinkQueue_Out(LinkQueue &Q);
//顺序存储结构队列
//----------------------------
//顺序存储结构队列显示函数
void SqQueueShow(SqQueue &S);
//顺序存储结构队列初始化
void Initialization_SqQueue(SqQueue &S);
//顺序存储结构队列入队操作
void SqQueue_Inter(SqQueue &S);
//顺序存储结构队列出队操作
void SqQueue_Out(SqQueue &S);

#endif
