#include <string>
#include <cstdio>
/*
题目：52 两个链表的第一个公共结点
输入两个链表，找出他们的第一个公共结点
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
unsigned int getListLength(ListNode* pHead);
ListNode* findFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
    unsigned int nLength1 = getListLength(pHead1);
    unsigned int nLength2 = getListLength(pHead2);
    int nLengthDif = nLength1 - nLength2;

    ListNode* pListHeadLong = pHead1;
    ListNode* pListHeadSort = pHead2;
    if(nLength2 > nLength1)
    {
        pListHeadLong = pHead2;
        pListHeadSort = pHead1;
        nLengthDif = nLength2 - nLength1;
    }
    // 现在链表上走几步，再同时在两个链表上遍历
    for(int i = 0; i < nLengthDif; i ++)
        pListHeadLong = pListHeadLong->m_pNext;
    while(pListHeadLong != nullptr && pListHeadSort != nullptr && pListHeadLong != pListHeadSort)
    {
        pListHeadLong = pListHeadLong->m_pNext;
        pListHeadSort = pListHeadSort->m_pNext;
    }
    // 得到第一个公共结点
    ListNode* pFirstCommonNode = pListHeadLong;
    return pFirstCommonNode;
}
unsigned int getListLength(ListNode* pHead)
{
    unsigned int nLength = 0;
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        ++ nLength;
        pNode = pNode->m_pNext;
    }
    return nLength;
}
void test(const char* testName, ListNode* pHead1, ListNode* pHead2, ListNode* pExpected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    if(findFirstCommonNode(pHead1, pHead2) == pExpected)
        printf("Passed.\n");
    else 
        printf("Failed.\n");
}

int main(int argc, char* argv[])
{

    ListNode* node1 = List::createListNode(1);
    ListNode* node2 = List::createListNode(2);
    ListNode* node3 = List::createListNode(3);
    ListNode* node4 = List::createListNode(4);
    ListNode* node5 = List::createListNode(5);
    ListNode* node6 = List::createListNode(6);
    ListNode* node7 = List::createListNode(7);

    List::connectListNodes(node1, node2);
    List::connectListNodes(node2, node3);
    List::connectListNodes(node3, node6);
    List::connectListNodes(node4, node5);
    List::connectListNodes(node5, node6);
    List::connectListNodes(node6, node7);
    test("test1", node1, node4, node6);

    return 0;
}