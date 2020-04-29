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
            printf("your input is %d\n", vals[i]);
            p1 = (pNode)malloc(sizeof(Node));
            p1->pnext = NULL;
            p1->data = vals[i];
            p2->pnext = p1;
            p2 = p1;
        }
        return Head;
    }
    static void print_list(pNode Head)
    {
        pNode p1;
        p1 = Head->pnext;
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
};
int main(){
    printf("will run/n");
    pNode pHead;
    pHead = Solution::create_node();
    Solution::print_list(pHead);
    return 0;
}

