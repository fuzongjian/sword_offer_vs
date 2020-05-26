#include <cstdio>
#include <string>
/*
题目：35 复杂链表的复制
请实现函数ComplexListNode* clone(complexListNode* pHead),复制一个复杂的链表。
在复杂链表中，每个结点除了有一个m_pNext指针指向下一个结点外，还有一个m_pSibling指向链表中任意结点或者nullptr
*/
struct ComplexListNode  
{
    int                 m_nValue;
    ComplexListNode*    m_pNext;
    ComplexListNode*    m_pSibling;
};
ComplexListNode* createNode(int value)
{
    ComplexListNode* pNode = new ComplexListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = nullptr;
    pNode->m_pSibling = nullptr;
    return pNode;
}
void buildNodes(ComplexListNode* pNode, ComplexListNode* pNext, ComplexListNode* pSibling)
{
    if(pNode != nullptr)
    {
        pNode->m_pNext = pNext;
        pNode->m_pSibling = pSibling;
    }
}
void printList(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while (pNode != nullptr)
    {
        printf("The value of this node is: %d.\n", pNode->m_nValue);
        if(pNode->m_pSibling != nullptr)
            printf("The value of its sibling is: %d.\n", pNode->m_pSibling->m_nValue);
        else
            printf("this node does not have a sibling.\n");
        printf("\n");
        pNode = pNode->m_pNext;
    }
    
}
void cloneNodes(ComplexListNode* pHead);
void connectSiblingNodes(ComplexListNode* pHead);
ComplexListNode* reconnectNodes(ComplexListNode* pHead);
ComplexListNode* clone(ComplexListNode* pHead)
{
    cloneNodes(pHead);
    connectSiblingNodes(pHead);
    return reconnectNodes(pHead);
}
void cloneNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while (pNode != nullptr)
    {
        ComplexListNode* pCloned = new ComplexListNode();
        pCloned->m_nValue = pNode->m_nValue;
        pCloned->m_pNext = pNode->m_pNext;
        pCloned->m_pSibling = nullptr;

        pNode->m_pNext = pCloned;
        pNode = pCloned->m_pNext;
    }
}
void connectSiblingNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    while (pNode != nullptr)
    {
        ComplexListNode* pCloned = pNode->m_pNext;
        if(pNode->m_pSibling != nullptr)
            pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
        pNode = pCloned->m_pNext;
    }
}
ComplexListNode* reconnectNodes(ComplexListNode* pHead)
{
    ComplexListNode* pNode = pHead;
    ComplexListNode* pClonedHead = nullptr;
    ComplexListNode* pClonedNode = nullptr;
    if (pNode != nullptr)
    {
        pClonedHead = pClonedNode = pNode->m_pNext;
        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    while(pNode != nullptr)
    {
        pClonedNode->m_pNext = pNode->m_pNext;
        pClonedNode = pClonedNode->m_pNext;

        pNode->m_pNext = pClonedNode->m_pNext;
        pNode = pNode->m_pNext;
    }
    return pClonedHead;
}
void test(const char* testName, ComplexListNode* pHead)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    printf("The original list is: \n");
    printList(pHead);
    ComplexListNode* pClonedHead = clone(pHead);
    printf("The cloned list is: \n");
    printList(pClonedHead);
}
void test1()
{
    ComplexListNode* node1 = createNode(1);
    ComplexListNode* node2 = createNode(2);
    ComplexListNode* node3 = createNode(3);
    ComplexListNode* node4 = createNode(4);
    ComplexListNode* node5 = createNode(5);

    buildNodes(node1, node2, node3);
    buildNodes(node2, node3, node5);
    buildNodes(node3, node4, nullptr);
    buildNodes(node4, node5, node2);
    test("test1", node1);    
}
int main(int argc, char* argv[])
{
    test1();
    return 0;
}