#include <stdio.h>
#include <malloc.h>
#include "queue.h"

int main()
{
    LinkQueue Q;
    Initialization_LinkQueue(Q);
    LinkQueue_Inter(Q);
    LinkQueue_Out(Q);

    SqQueue S;
    Initialization_SqQueue(S);
    SqQueue_Inter(S);
    SqQueue_Out(S);
}