#include <iostream>
#include <string>
#include <cstdio>
/*
题目：在o(1)时间删除结点
给定单向链表的头指针和结点指针，定义一个函数在o(1)时间删除该结点。
*/
struct ListNode
{
    int m_nValue;
    ListNode* m_pNext;
};
class List
{
public:
    static ListNode* createListNode(int value)
    {
        ListNode * pNode = new ListNode();
        pNode->m_nValue = value;
        pNode->m_pNext = nullptr;
        return pNode;
    }
    static void connectListNodes(ListNode* pCurrent, ListNode* pNext)
    {
        if (pCurrent == nullptr)
        {
            printf("Error to connect two nodes. \n");
            return;
        }
        pCurrent->m_pNext = pNext;
    }
    static void printListNode(ListNode* pNode)
    {
        if (pNode == nullptr)
        {
            printf("this node is nullptr\n");
        }
        else 
        {
            printf("this key in node is %d.\n", pNode->m_nValue);
        }
    }
    static void printList(ListNode * pHead)
    {
        printf("printList starts.\n");
        ListNode* pNode = pHead;
        while (pNode != nullptr)
        {
            printf("%d\t", pNode->m_nValue);
            pNode = pNode->m_pNext;
        }
        printf("\nprintList ends.\n");
    }
    static void destoryList(ListNode* pHead)
    {
        ListNode* pNode = pHead;
        while (pNode != nullptr)
        {
            pHead = pHead->m_pNext;
            delete pNode;
            pNode = pHead;
        }
    }
    static void addToTail(ListNode** pHead, int value)
    {
        ListNode * pNew = new ListNode();
        pNew->m_nValue = value;
        pNew->m_pNext = nullptr;
        if (*pHead == nullptr)
        {
            *pHead = pNew;
        }
        else
        {
            ListNode* pNode = *pHead;
            while(pNode->m_pNext != nullptr)
                pNode = pNode->m_pNext;
            pNode->m_pNext = pNew;
        }
    }
    static void removeNode(ListNode** pHead, int value){
        if(pHead == nullptr || *pHead == nullptr)
            return;
        ListNode * pToBeDeleted = nullptr;
        if((*pHead)->m_nValue == value)
        {
            pToBeDeleted = *pHead;
            *pHead = (*pHead)->m_pNext;
        }
        else
        {
            ListNode* pNode = *pHead;
            while(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
                pNode = pNode->m_pNext;
            
            if(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
            {
                pToBeDeleted = pNode->m_pNext;
                pNode->m_pNext = pNode->m_pNext->m_pNext;
            }
        }
        if(pToBeDeleted != nullptr)
        {
            delete pToBeDeleted;
            pToBeDeleted = nullptr;
        }
    }
};

void deleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{   
    if(!pListHead || !pToBeDeleted)
        return;
    // 要删除的结点不是尾结点
    if(pToBeDeleted->m_pNext != nullptr)
    {
        ListNode* pNext = pToBeDeleted->m_pNext;
        pToBeDeleted->m_nValue = pNext->m_nValue;
        pToBeDeleted->m_pNext = pNext->m_pNext;

        delete pNext;
        pNext = nullptr;
    }
    else if(*pListHead == pToBeDeleted)// 链表只有一个结点，删除头结点（也是尾结点）
    {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHead = nullptr;
    }
    else // 链表中有多个结点，删除尾结点
    {
        ListNode* pNode = *pListHead;
        while (pNode->m_pNext != pToBeDeleted)
        {
            pNode = pNode->m_pNext;
        }
        pNode->m_pNext = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
}
int main(int argc, char* argv[])
{
    ListNode * pNode1 = List::createListNode(1);
    ListNode * pNode2 = List::createListNode(2);
    ListNode * pNode3 = List::createListNode(3);
    ListNode * pNode4 = List::createListNode(4);
    ListNode * pNode5 = List::createListNode(5);
    ListNode * pNode6 = List::createListNode(6);

    List::connectListNodes(pNode1, pNode2);
    List::connectListNodes(pNode2, pNode3);
    List::connectListNodes(pNode3, pNode4);
    List::connectListNodes(pNode4, pNode5);
    List::connectListNodes(pNode5, pNode6);
    printf("The original list is :\n");
    List::printList(pNode1);
    printf("The node to be deleted is: \n");
    List::printListNode(pNode2);
    deleteNode(&pNode1, pNode2);
    printf("The result list is: \n");
    List::printList(pNode1);
    return 0;
}