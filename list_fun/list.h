#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int data;           // 数据
    struct Node* next;  // 指向下一个节点的指针
} Node;

Node* insert(Node* head, Node* newNode);    //插入
Node* create_sort(void);   //创建新节点
Node* delete_k_node(Node* head, int k);   //删除第K个节点
Node* delete_Node_Num(Node* head, int num);   //删除特定值
void printLinkedList(Node* head);     //输出链表
int count(Node* head);                //返回链表节点数
void freeLinkList(Node* head);       //释放空间


#endif /* LIST_H */
