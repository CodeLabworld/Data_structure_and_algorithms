/*顺序表的建立*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FAlSE 0
#define MAXSIZE 20    /*存储空间的初始分配量*/
typedef int ElemType; /*ElemType 类型根据实际情况而定，这里假设为MAXSIZE*/

typedef struct
{
    ElemType data[MAXSIZE]; /*数组存储数据元素，最大值为MAXSIZE*/
    int length;             /*线性表当前长度*/
} SqList;

/************显示函数***************/
void ShowAll(SqList &L)
{
    SqList p = L;
    printf("链表显示如下:\n");
    for (int i = 0; i < L.length; i++)
    {
        printf("%2d", p.data[i]);
    }
    printf("\n");
    printf("元素总数为:%d\n", L.length);
}

/************创建顺序表***************/
void CreatList(SqList &L)
{
    int i;
    printf("输入长度：");
    scanf("%d", &L.length);
    printf("请输入数据：\n");
    for (i = 0; i < L.length; i++)
    {
        scanf("%d", &L.data[i]);
    }
    ShowAll(L);
}

/*元素排序*/
//*************************************************************************************
void paixu(SqList &L)
{
    int i, j, t;
    for (j = 0; j < L.length; j++)
    {
        for (i = j + 1; i < L.length; i++)
        {
            if (L.data[i] < L.data[j])
            {
                t = L.data[j];
                L.data[j] = L.data[i];
                L.data[i] = t;
            }
        }
    }
    ShowAll(L);
}

/*获得元素操作*/
// ************************************************************************************

void GetElem(SqList &L)
{
    int i, data;
    printf("输入查找的位置：");
    scanf("%d", &i);
    if (L.length == 0 || i < 1 || i > L.length) //表不为空，判断表是否存在
        printf("表为空");                       //表为空，错误提示
    data = L.data[i - 1];                       //将表中第i个位置的值提取出来
    printf("%d\n", data);
}

/*二分查找元素*/
//******************************************************************************
void Search(SqList &L)
{
    int i, first, last, mid, mid_data;
    int search_data;
    printf("输入要查找的值：");
    scanf("%d", &search_data);
    first = 0;
    last = L.length;
    while (first <= last)
    {
        mid = (first + last) / 2;
        mid_data = L.data[mid];
        if (search_data > mid_data)
        {
            first = mid + 1;
        }
        else if (search_data < mid_data)
        {
            last = mid - 1;
        }
        else if (search_data == mid_data)
        {
            printf("查找到该元素：%d\n", mid_data);
        }
        else
        {
            printf("未查找到\n");
        }
    }
}

/*表的插入操作(在表的第i个位置插入新元素e，L的长度加1)*/
// *****************************************************************************

void ListInsert(SqList &L)
{
    int i, e;
    int k; //定义数组下标变量
    printf("输入插入位置与新元素（中间空格隔开）：");
    scanf("%d%d", &i, &e);
    if (L.length == MAXSIZE)
    {                     //表已经满了
        printf("表满了"); //错误提示
    }
    if (i < 1 || i > L.length + 1)
    {                        //i不在范围
        printf("i不在范围"); //错误提示
    }
    if (i <= L.length)
    {                                           //插入数据位置不在表尾
        for (k = L.length - 1; k >= i - 1; k--) //将插入位置后的数据元素值与下标向后移动一位，将插入位置空出来
            L.data[k + 1] = L.data[k];
    }
    L.data[i - 1] = e; //将新元素插入
    L.length++;
    ShowAll(L);
}

/*表的删除操作（将表的第i个位置的值删去，L长度减1）*/
// ***********************************************************************************
void ListDelete(SqList &L)
{
    int k;
    int i;
    printf("输入删除元素位置：");
    scanf("%d%d", &i);
    if (L.length == 0)
    {                     //表为空
        printf("表为空"); //错误提示
    }
    if (i < 1 || i > L.length)
    {                             //删除位置不存在
        printf("删除位置不存在"); //错误提示
    }
    if (i < L.length)
    {                                  //删除位置不是最后一个
        for (k = i; k < L.length; k++) //将删除位置的后继元素前移（下标为k-1的为i位置的值）
            L.data[k - 1] = L.data[k];
    }
    L.length--;
    ShowAll(L);
}

/*主函数*/
//****************************************************
int main()
{
    SqList L;
    CreatList(L);
    GetElem(L);
    ListInsert(L);
    ListDelete(L);

    int common1, common2;
    printf("---------------顺序表相关操作-------------------------\n");
    printf("****************************************************\n");
    printf("命令：\n1.建立顺序表\n2.顺序表查找\n3.将元素排序\n4.二分法查找\n");
    printf("****************************************************\n");
    printf("输入相关命令：");
    scanf("%d", &common1);
    if (common1 == 1)
    {
        CreatList(L);
    }
    else if (common1 == 2)
    {
        GetElem(L);
    }
    else if (common1 == 3)
    {
        paixu(L);
    }
    else if (common1 == 4)
    {
        Search(L);
    }

    system("pause");
}