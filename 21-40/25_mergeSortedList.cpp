#include <cstdio>
#include <string>
/*
题目：25 合并两个排序的链表
输入两个递增排序的链表，合并这两个链表并使链表中的结点仍然是按照递增排序的。
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
ListNode* merge(ListNode* pHead1, ListNode* pHead2)
{
    if(pHead1 == nullptr)
        return pHead2;
    else if(pHead2 == nullptr)
        return pHead1;
    ListNode* pMergedHead = nullptr;
    if(pHead1->m_nValue < pHead2->m_nValue)
    {
        pMergedHead = pHead1;
        pMergedHead->m_pNext = merge(pHead1->m_pNext, pHead2);
    }
    else 
    {
        pMergedHead = pHead2;
        pMergedHead->m_pNext = merge(pHead1, pHead2->m_pNext);
    }
    return pMergedHead;
}
int main(int argc, char* argv[])
{
    ListNode * node1 = List::createListNode(1);
    ListNode * node2 = List::createListNode(2);
    ListNode * node3 = List::createListNode(3);
    ListNode * node4 = List::createListNode(4);
    ListNode * node5 = List::createListNode(5);

    List::connectListNodes(node1, node2);
    List::connectListNodes(node2, node3);
    List::connectListNodes(node3, node4);
    List::connectListNodes(node4, node5);

    ListNode * node6 = List::createListNode(3);
    ListNode * node7 = List::createListNode(4);
    ListNode * node8 = List::createListNode(5);

    List::connectListNodes(node6, node7);
    List::connectListNodes(node7, node8);

    ListNode* mergeNode = merge(node1, node6); 
    List::printList(mergeNode);

    return 0;
}