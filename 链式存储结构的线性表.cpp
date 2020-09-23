#include <iostream>
#include <stdio.h>
#include <time.h>
typedef int ElemType;
#define OK 1
#define ERROR 0
#define TRUE 1
#define FAlSE 0

/*初始化*/
//****************************************************************************
typedef struct Node
{
    ElemType data;
    struct Node *next;

} Node;
typedef struct Node *LinkList; //定义LinkList

/*显示函数*/
//***********************************************
void ShowAll(LinkList &L)
{
    LinkList p;
    int number = 0;
    p = L->next;
    printf("显示链表数据：");
    while (p)
    {
        printf("%3d", p->data);
        p = p->next;
        number++;
    }
    printf("\n");
    printf("链表数据总数：%d\n", number);
}

/*单链表的整表创建(建立带头结点的单链表L（头插法）)*/
//***********************************************************

void CreatListHead(LinkList &L)
{
    LinkList p;
    int number;
    int i;
    printf("输入表的长度：");
    scanf("%d", &number);
    L = (LinkList)malloc(sizeof(Node));
    (L)->next = NULL; //先建立一个带头结点的单链表
    printf("输入数据：");
    for (i = 0; i < number; i++)
    {
        p = (LinkList)malloc(sizeof(Node)); //生成新结点
        scanf("%d", &p->data);
        p->next = (L)->next; //将p->next变为L->next
        (L)->next = p;       //将L->next变为p
    }
    ShowAll(L);
}

/*单链表的整表创建(建立带头结点的单链表L（尾插法）)*/
//***************************************************************************

void CreateListTail(LinkList &L)
{
    LinkList p, r;
    int i;
    int number;
    printf("输入表的长度：");
    scanf("%d", &number);
    L = (LinkList)malloc(sizeof(Node)); //为整个线性表
    r = L;
    printf("输入数据：");
    for (i = 1; i < number; i++)
    {
        p = (Node *)malloc(sizeof(Node)); //生成新节点
        scanf("%d", &p->data);
        r->next = p; //将表尾终端结点的指针指向新节点
        r = p;       //将当前的新节点定义为表尾终端结点
    }
    r->next = NULL;
    ShowAll(L);
}

/*单链表的读取（读取第i个元素）*/
// **************************************************************************

int GetElem(LinkList L)
{
    int j, position, e;
    printf("输入读取的元素位置：");
    scanf("%d", &position);
    LinkList p;               //声明一结点p
    p = L->next;              //让p指向链表L的第一个结点
    j = 1;                    //j为计数器
    while (p && j < position) //p不为空，或者计数器j还没有等于i时，循环继续（第i-1个为第i个位置）
    {
        p = p->next; //让p指向下一个结点
        ++j;
    }
    if (!p || j > position)
    {
        printf("该元素不存在"); //第i个元素不存在
        return ERROR;
    }

    e = p->data; //取第i个元素的数据
    printf("该元素为%d\n", e);
    ShowAll(L);
    return OK;
}

/*单链表的插入（在L中第i个位置之前插入新的数据元素e，L的长度加1）*/
// ****************************************************************************

int ListInsert(LinkList &L)
{
    int j, position, e;
    LinkList p, s;
    p = L;
    j = 1;
    printf("输入插入的位置：");
    scanf("%d", &position);
    printf("输入插入的值：");
    scanf("%d", &e);
    while (p && j < position) //寻找第i个结点
    {
        p = p->next;
        ++j;
    }
    if (!p || j > position)
    {
        printf("该位置元素不存在");
        return ERROR; //第i个元素不存在
    }
    s = (LinkList)malloc(sizeof(Node)); //生成新结点
    s->data = e;
    s->next = p->next; //将p的后继结点赋值给s的后继
    p->next = s;       //将s赋值给p的后继
    ShowAll(L);
    return OK;
}

/*单链表的删除(删除L的第i个数据元素，并用e返回其值，L的长度减一)*/
//*************************************************************************

int ListDelete(LinkList &L)
{
    int j, position, e;
    LinkList p, q;
    printf("输入删除的位置：");
    scanf("%d", &position);
    p = L;
    j = 1;
    while (p->next && j < position) //遍历寻找第i个元素
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > position)
    {
        printf("该元素不存在");
        return ERROR; //第i个元素不存在
    }

    q = p->next;
    p->next = q->next; //将q的后继赋值给p的后继
    e = q->data;       //将q结点中的数据给e
    free(q);           //让系统回收此结点，释放内存
    ShowAll(L);
    return OK;
}

/*单链表的整表删除（顺序线性表L已存在，操作结果：将L重置为空表）*/
//***************************************************************************
int ClearList(LinkList &L)
{
    LinkList p, q;
    p = (L)->next; //*p指向第一个结点
    while (p)      //没到表尾
    {
        q = p->next;
        free(p);
        p = q;
    }
    (L)->next = NULL; //头结点指针域为空
    printf("整表已删除\n");
    return OK;
}

int main()
{
    LinkList L;
    int common1, common2;
    printf("****************************************************\n");
    printf("命令：\n1.头插法创表\n2.尾插法创表\n3.获取表中的值\n4.表的插入\n5.表的删除\n6.整表删除\n");
    printf("****************************************************\n");
    printf("输入创建命令（1 or 2）：");
    scanf("%d", &common1);
    while (1)
    {
        if (common1 == 1)
        {
            CreatListHead(L);
            break;
        }
        else if (common1 == 2)
        {
            CreateListTail(L);
            break;
        }
        else
        {
            printf("命令错误，请重新输入！\n");
        }
    }
    printf("创表完成\n");
    while (1)
    {
        printf("输入对表的操作命令：");
        scanf("%d", &common2);
        if (common2 == 3)
            GetElem(L);
        else if (common2 == 4)
            ListInsert(L);

        else if (common2 == 5)
            ListDelete(L);
        else if (common2 == 6)
        {
            ClearList(L);
            break;
        }
        else
            printf("命令错误，请重新输入！\n");
    }
    printf("所有操作已完成\n");
    system("pause");
}