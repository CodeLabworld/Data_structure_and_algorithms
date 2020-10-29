#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int command_one; //一级命令
    int command_two; //二级命令
    while (1)
    {
        printf("___________________________________________\n");
        printf("1.链式存储结构栈\n2.顺序存储结构栈\n");
        printf("___________________________________________\n");
        printf("输入执行命令：");
        scanf("%d", &command_one);
        if (command_one == 1)
        {
            //定义栈
            Linkstack S;
            //初始化栈
            Initialization_linkstack(S); //采用引用传参，若用指针需要定义头结点，因为c语言中不能用空指针，会报错
            while (1)
            {
                printf("___________________________________________\n");
                printf("1.入栈\n2.出栈\n");
                printf("___________________________________________\n");
                printf("输入操作命令：");
                scanf("%d", &command_two);
                if (command_two == 1)
                {
                    //链式存储结构入栈
                    LinkPush(S);
                }
                else if (command_two == 2)
                {
                    //链式存储结构出栈
                    Linkpop(S);
                }
                else
                {
                    printf("输入命令有误，请重新输入！\n");
                }
            }
        }
        else if (command_one == 2)
        {
            //定义栈
            SqStack Q;
            //初始化栈
            Initialization_Sqstack(Q); //采用引用
            while (1)
            {
                printf("___________________________________________\n");
                printf("1.入栈\n2.出栈\n");
                printf("___________________________________________\n");
                printf("输入操作命令：");
                scanf("%d", &command_two);
                if (command_two == 1)
                {
                    //顺序存储结构入栈
                    SqStack_push(Q);
                }
                else if (command_two == 2)
                {
                    //顺序存储结构出栈
                    SqStack_pop(Q);
                }
                else
                {
                    printf("输入命令有误，请重新输入！\n");
                }
            }
        }
        else
        {
            printf("输入命令错误，请重新输入\n");
        }
    }
}