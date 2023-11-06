#include <stdio.h>
#include <stdlib.h>
#include "list.h"


int main() {
    int num,k;
    Node* head = NULL;
    Node* p;
    head= create_sort();
    printf("节点数：%d\n",count(head));
    printLinkedList(head);
    
    printf("输入要删除节点的序号:\n");    
    scanf("%d",&k);
    head=delete_k_node(head,k);
    printLinkedList(head);

    printf("输入要删除节点上的整数:\n");
    scanf("%d",&num);
    head=delete_Node_Num(head, num);
    printLinkedList(head);

    printf("输入要插入的数:\n");
    scanf("%d",&num);
    p=(Node*)malloc(sizeof(Node));
    p->data=num;
    p->next=NULL;
    head=insert(head,p);
    printLinkedList(head);
    
    freeLinkList(head);
    return 0;
}