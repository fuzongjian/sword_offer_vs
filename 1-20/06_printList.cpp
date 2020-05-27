#include <string>
#include <stack>
using namespace std;
/*
题目6：从头到尾打印链表
输入一个链表的头结点，从尾到头反过来打印出每个结点的值
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
void printListReversinglyIteratively(ListNode* pHead){
    std::stack<ListNode*> nodes;
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }
    while(!nodes.empty())
    {
        pNode = nodes.top();
        printf("%d\t", pNode->m_nValue);
        nodes.pop();
    }
}
void printListReversinglyRecursively(ListNode* pHead)
{
    if(pHead != nullptr)
    {
        if(pHead->m_pNext != nullptr)
            printListReversinglyRecursively(pHead->m_pNext);
        printf("%d\t", pHead->m_nValue);
    }
}
void test(ListNode* pHead)
{
    List::printList(pHead);
    printListReversinglyIteratively(pHead);
    printf("\n");
    printListReversinglyRecursively(pHead);
}
void test1()
{
    printf("\n test1 begins.\n");
    ListNode* node1 = List::createListNode(1);
    ListNode* node2 = List::createListNode(2);
    ListNode* node3 = List::createListNode(3);
    ListNode* node4 = List::createListNode(4);
    ListNode* node5 = List::createListNode(5);

    List::connectListNodes(node1, node2);
    List::connectListNodes(node2, node3);
    List::connectListNodes(node3, node4);
    List::connectListNodes(node4, node5);

    test(node1);
}
int main(int argc, char* argv[])
{
    test1();
    return 0;
}