#include <iostream>
#include <stdint.h>
#include <sys/malloc.h>
#include <stdlib.h>
using namespace std;
typedef struct node
{
    int data; // 数据域
    struct node *pnext; // 指针域
}Node, *pNode;
class Solution{
public:
    // 创建链表
    static pNode create_node(void){
        printf("will create \n");
        pNode Head, p1, p2;
        int val, num, i;
        Head = (pNode)malloc(sizeof(Node));// p = (struct node *)malloc(sizeof(struct node))
        Head->pnext = NULL;
        if (Head == NULL)
        {
            printf("request malloc is failure, this program stop");
            exit(-1);
        }
        p2 = Head;
        // printf("please input the number of node :");
        // scanf("%d",&num);
        num = 8;
        int vals[] = {1,2,3,4,6,7,2,9};
        for (int i = 0; i < num; i++)
        {
            printf("your input is %d \n", vals[i]);
            p1 = (pNode)malloc(sizeof(Node));
            p1->pnext = NULL;
            p1->data = vals[i];
            p2->pnext = p1;
            p2 = p1;
        }
        return Head;
    }
    // 遍历链表
    static void print_list(pNode Head)
    {
        pNode p1;
        p1 = Head->pnext;// 注意此处不是p1 = Head，而是p1 = Head->pnext
        while (1)
        {
            if (p1->pnext == NULL)
            {
                printf("%d ",p1->data);
                break;
            }
            printf("%d ",p1->data);
            p1 = p1->pnext;
        }
    }
    // 判断链表是否为空
    static bool is_empty(pNode Head){
        if (Head->pnext == NULL)
        {
            return true;
        }
        return false;
    }
    // 链表的长度
    static int length_list(pNode Head){
        int i  = 0;
        pNode p1;
        if (is_empty(Head))
        {
            printf("this list is null");

        }
        else{
            p1 = Head->pnext;
            while (1)
            {
                if(p1->pnext == NULL)
                {
                    i ++;
                    break;
                }
                i ++;
                p1 = p1->pnext;
            }
            
        }
        return i;
    }
    // 插入元素
    static bool insert_list(pNode Head, int pos, int val){
        int i = 0;
        pNode p;
        p = Head;
        while (p->pnext != NULL && i < pos - 1)     
        {
            p = p->pnext;
            ++ i;
        }// 将P指向要插入节点位置的前一个节点
        if(p->pnext == NULL || i > pos - 1) // i > pos - 1 的作用是当i取负值时的一种情况
            return false;
        pNode pNew = (pNode)malloc(sizeof(Node));
        if(pNew == NULL){
            printf("malloc is failure");
            exit(-1);
        }
        pNew->data = val;
        pNew->pnext = NULL;

        pNode q = p->pnext;
        p->pnext = pNew;
        pNew->pnext = q;

        return true;
    }
    // 删除元素
    static bool delete_list(pNode Head, int pos, int *val){
        int i = 0;
        pNode p = Head;
        while (p->pnext != NULL && i < pos - 1)
        {
            p = p->pnext;
            ++i;
        }
        if (p->pnext == NULL || i > pos - 1)
            return false;
        pNode q = p->pnext;
        *val = q->data;

        p->pnext = p->pnext->pnext;
        free(q);
        q = NULL;
        return true;
    }
    static void sort_list(pNode Head){
        int i,j,t;
        pNode p,q;
        int len = length_list(Head);
        for (i = 0, p = Head->pnext; i < len - 1; i++, p = p->pnext)    
        {
            for (j = i + 1, q = p->pnext;j < len - 1;j++, q = q->pnext)
            {
                if (p->data > q->data)
                {
                    t = p->data;
                    p->data = q->data;
                    q->data = t;
                }
                
            }
            
        }
        
    }
};
int main(){
    printf("will run \n");
    pNode pHead;
    int val;
    pHead = Solution::create_node();
    Solution::print_list(pHead);

    int length = Solution::length_list(pHead);
    printf("\n this list length is %d \n", length);

    bool status = Solution::insert_list(pHead, 3, 100);
    printf("\n insert status %d \n", status);
    Solution::print_list(pHead);
    bool del_status = Solution::delete_list(pHead, 4, &val);
    printf("\n delete status %d \n", status);
    Solution::print_list(pHead);

    Solution::sort_list(pHead);
    Solution::print_list(pHead);
    return 0;
}

