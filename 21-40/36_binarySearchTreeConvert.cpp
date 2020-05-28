#include <cstdio>
#include <string>
/*
题目：36 二叉搜索树和双向链表
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向
*/
struct BinaryTreeNode
{
    int              m_dbValue;
    BinaryTreeNode*     m_pLeft;
    BinaryTreeNode*     m_pRight;
};
BinaryTreeNode* creareBinaryTreeNode(int value)
{
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_dbValue = value;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;
    return pNode;
}
void connectTreeNode(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}
void printTreeNode(const BinaryTreeNode* pNode)
{
    if(pNode != nullptr)
    {
        printf("value of this node is: %d.\n", pNode->m_dbValue);
        if(pNode->m_pLeft != nullptr)
            printf("value of its left child is: %d.\n", pNode->m_pLeft->m_dbValue);
        else 
            printf("left child is nullptr.\n");

        if(pNode->m_pRight != nullptr)
            printf("value of its right child is: %d.\n", pNode->m_pRight->m_dbValue);
        else 
            printf("right child is nullptr.\n");
    }
    printf("\n");
}
void printTree(const BinaryTreeNode* pRoot)
{
    printTreeNode(pRoot);
    if(pRoot != nullptr)
    {
        if(pRoot->m_pLeft != nullptr)
            printTree(pRoot->m_pLeft);
        if(pRoot->m_pRight != nullptr)
            printTree(pRoot->m_pRight);
    }
}
void destoryTree(BinaryTreeNode* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTreeNode* pLeft = pRoot->m_pLeft;
        BinaryTreeNode* pRigth = pRoot->m_pRight;
        delete pRoot;
        pRoot = nullptr;

        destoryTree(pLeft);
        destoryTree(pRigth);
    }
}
void convertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList);
BinaryTreeNode* convert(BinaryTreeNode* pRootOfTree)
{
    BinaryTreeNode* pLastNodeInList = nullptr;
    convertNode(pRootOfTree, &pLastNodeInList);
    // pLastNodeInList指向双向链表的尾结点，需要返回头结点
    BinaryTreeNode* pHeadOfList = pLastNodeInList;
    while(pHeadOfList != nullptr && pHeadOfList->m_pLeft != nullptr)
        pHeadOfList = pHeadOfList->m_pLeft;
    return pHeadOfList;
}
void convertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)
{
    if(pNode == nullptr)
        return;
    BinaryTreeNode* pCurrent = pNode;
    if(pCurrent->m_pLeft != nullptr)
        convertNode(pCurrent->m_pLeft, pLastNodeInList);
    pCurrent->m_pLeft = *pLastNodeInList;
    if(*pLastNodeInList != nullptr)
        (*pLastNodeInList)->m_pRight = pCurrent;
    *pLastNodeInList = pCurrent;
    if(pCurrent->m_pRight != nullptr)
        convertNode(pCurrent->m_pRight, pLastNodeInList);
}
//测试
void printDoubleLinkedList(BinaryTreeNode* pHeadOfList)
{
    BinaryTreeNode* pNode = pHeadOfList;
    printf("The nodes from left to right are:\n");
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->m_dbValue);
        if(pNode->m_pRight == nullptr)
            break;
        pNode = pNode->m_pRight;
    }
    printf("\nThe nodes from right to left are:\n");
    while(pNode != nullptr)
    {
        printf("%d\t", pNode->m_dbValue);
        if(pNode->m_pLeft == nullptr)
            break;
        pNode = pNode->m_pLeft;
    }
    printf("\n");
}
void destroyList(BinaryTreeNode* pHeadOfList)
{
    BinaryTreeNode* pNode = pHeadOfList;
    while(pNode != nullptr)
    {
        BinaryTreeNode* pNext = pNode->m_pRight;
        delete pNode;
        pNode = pNext;
    }
}
void test(const char* testName, BinaryTreeNode* pRootOfTree)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);
    printTree(pRootOfTree);
    BinaryTreeNode* pHeadOfList = convert(pRootOfTree);
    printDoubleLinkedList(pHeadOfList);
}
void test1()
{
    BinaryTreeNode* node1 = creareBinaryTreeNode(10);
    BinaryTreeNode* node2 = creareBinaryTreeNode(6);
    BinaryTreeNode* node3 = creareBinaryTreeNode(14);
    BinaryTreeNode* node4 = creareBinaryTreeNode(4);
    BinaryTreeNode* node5 = creareBinaryTreeNode(8);
    BinaryTreeNode* node6 = creareBinaryTreeNode(12);
    BinaryTreeNode* node7 = creareBinaryTreeNode(16);
    connectTreeNode(node1, node2, node3);
    connectTreeNode(node2, node4, node5);
    connectTreeNode(node3, node6, node7);
    test("test1", node1);
}
int main(int argc, char* argv[])
{
    test1();
    return 0;
}