#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Linkstack S; //定义栈
    //初始化栈
    Initialization_linkstack(S); //采用引用传参，若用指针需要定义头结点，因为c语言中不能用空指针，会报错
}