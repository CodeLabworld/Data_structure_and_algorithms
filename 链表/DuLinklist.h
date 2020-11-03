#ifdef DULINK_H
typedef struct DuNode
{
    int data;
    struct DuNode *prior; //前驱指针
    struct DuNode *next;  //后续指针
} DuNode, *DuLinklist;

//尾插法创建双向链表
void Creat_DuLinklist(DuLinklist &L);
//遍历双向链表
void Traverse_DuLinklist(DuLinklist &L);
//删除指定数据
void Delet_data(DuLinklist &L);

#endif
