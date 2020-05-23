#include <cstdio>
#include <string>
/*
题目：链表中环的入口
一个链表中包含环，如何找出环的入口结点？
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
ListNode* meetingNode(ListNode* pHead){
    if(pHead == nullptr)
        return nullptr;
    ListNode * pSlow = pHead->m_pNext;
    if(pSlow == nullptr)
        return nullptr;
    
    ListNode* pFast = pSlow->m_pNext;
    while(pFast != nullptr && pSlow != nullptr)
    {
        if(pFast == pSlow)
            return pFast;
        pSlow = pSlow->m_pNext;
        pFast = pFast->m_pNext;
        if(pFast != nullptr)
            pFast = pFast->m_pNext;
    }
    return nullptr;
}
ListNode* entryNodeOfLoop(ListNode* pHead)
{
    ListNode* meetNode = meetingNode(pHead);
    if(meetNode == nullptr)
        return nullptr;
    // 得出环中结点的数目
    int nodesInLoop = 1;
    ListNode* pNode1 = meetNode;
    while(pNode1->m_pNext != meetNode)
    {
        pNode1 = pNode1->m_pNext;
        ++nodesInLoop;
    }
    // 先移动pNode1，次数为环中结点的数据
    pNode1 = pHead;
    for(int i = 0; i < nodesInLoop; i ++)
        pNode1 = pNode1->m_pNext;
    // 再移动pNode1和pNode2
    ListNode* pNode2 = pHead;
    while(pNode1 != pNode2)
    {
        pNode1 = pNode1->m_pNext;
        pNode2 = pNode2->m_pNext;
    }
    return pNode1;
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
    List::connectListNodes(node5, node3);

    bool status = entryNodeOfLoop(node1) == node3;
    printf("status === %d", status);
    return 0;
}