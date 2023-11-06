#include <stdio.h>
#include <stdlib.h>
#include "list.h"

// 定义链表结构
Node* insert(Node* head, Node* newNode);    //插入
Node* create_sort(void);   //创建新节点
Node* delete_k_node(Node* head, int k);   //删除第K个节点
Node* delete_Node_Num(Node* head, int num);   //删除特定值
void printLinkedList(Node* head);     //输出链表
int count(Node* head);                //返回链表节点数
void freeLinkList(Node* head);       //释放空间

Node* insert(Node* head, Node* newNode) {
    if (head == NULL || newNode->data <= head->data) {    //新节点最小时  为头节点
        newNode->next = head;
        head = newNode;
    } else {                         
        Node* q = head;
        while (q->next != NULL && newNode->data > q->next->data) {   //查找刚好大于新节点值的前一个节点
            q = q->next;
        }
        newNode->next = q->next;    //插入
        q->next = newNode;
    }
    return head;
}

// 创建一个新的节点                                 
Node* create_sort(void) {
    Node *p,*head=NULL;
    int a;
    printf("创建一条有序链表，输入数据以-1结束:");
    scanf("%d",&a);
    while(a!=-1){
        p=(Node*)malloc(sizeof(Node));    //创建空间
        p->data=a;
        p->next=NULL;
        head=insert(head,p);
        scanf("%d",&a);
    }
    printf("输入完毕\n");
    return head;
}


// 删除第 k 个节点                           
Node* delete_k_node(Node* head, int k) {
    if (head == NULL) {
        printf("链表为空，无节点可删！\n");
        return NULL;
    }
    //判断K值下限
    if (k < 1) {                            
        printf("无效的位置。\n");
        return head;
    }

    if (k == 1) {
        // 删除头节点
        Node* temp = head;
        head = head->next;
        free(temp);
        printf("删除第1个节点!\n");
    } else {
        // 找到第 k-1 个节点
        Node* q = NULL;
        Node* p = head;
        int count = 1;
        while (p != NULL && count < k) {
            q = p;
            p = p->next;
            count++;
        }
        //判断K上限
        if (p == NULL) {          //   k>节点数
            printf("无效的位置，超出！\n");
        } else {
            // 删除
            q->next = p->next;
            free(p);
        }
    }

    return head;
}

// 删除链表上包含特定值的节点                              
Node* delete_Node_Num(Node* head, int num) {
    if (head == NULL) {
        printf("链表为空。\n");
        return NULL;
    }

    Node* q = NULL;
    Node* p = head;

    // 遍历链表    
    while (p != NULL) {
        if (p->data == num) {
            if (q == NULL) {
                // 特殊情况 --头节点
                head = head->next;
                free(p);
                // 继续搜索
                p = head;
            } else {
                q->next = p->next;
                free(p);
                // 继续搜索
                p = q->next;
            }
        } else {
            // 继续搜索
            q = p;
            p = p->next;
        }
    }

    return head;
}

// 输出链表上各个节点的值                                
void printLinkedList(Node* head) {
    if (head == NULL) {
        printf("链表为空。\n");
        return;
    }

    Node* p = head;
    printf("链表上各个节点的数据为：\n");
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }

    printf("\n");
}

// 计算链表中的节点数量                           ---完成
int count(Node* head) {
    int count = 0;
    Node* p = head;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

// 释放链表中的节点空间                                 ----完成
void freeLinkList(Node* head) {
    if (head == NULL) {
        return;
    }

    Node* p = head;

    while (p != NULL) {
        Node* temp = p;
        p = p->next;
        free(temp);
    }
    printf("已释放链表的节点空间！\n");
}
