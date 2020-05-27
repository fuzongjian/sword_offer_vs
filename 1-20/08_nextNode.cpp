#include <stdio.h>
#include <string>
/*
题目8：二叉树的下一个结点
给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
树中结点除了有两个分别指向左右子节点的指针外，还有一个指向父结点的指针
*/
struct BinaryTreeNode
{
    int                 m_nValue;
    BinaryTreeNode*     m_pLeft;
    BinaryTreeNode*     m_pRight;
    BinaryTreeNode*     m_pParent;
};
BinaryTreeNode* createBinaryTreeNode(int value)
{
    BinaryTreeNode* pNode = new BinaryTreeNode();
    pNode->m_nValue = value;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;
    pNode->m_pParent = nullptr;
    return pNode;
}
void connectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
        if(pLeft != nullptr)
            pLeft->m_pParent = pParent;
        if(pRight != nullptr)
            pRight->m_pParent = pParent;
    }
}
void printTreeNode(BinaryTreeNode* pNode)
{
    if(pNode != nullptr)
    {
        printf("value of this node is: %d\n", pNode->m_nValue);
        if(pNode->m_pLeft != nullptr)
            printf("value of its left child is: %d.\n", pNode->m_pLeft->m_nValue);
        else 
            printf("left child is null.\n");
        if(pNode->m_pRight != nullptr)
            printf("value of its right child is: %d.\n", pNode->m_pRight->m_nValue);
        else 
            printf("right child is null.\n");
    }
    else 
    {
        printf("this node is null.\n");
    }
    printf("\n");
}
void printTree(BinaryTreeNode* pRoot)
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
void destroyTree(BinaryTreeNode* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTreeNode* pLeft = pRoot->m_pLeft;
        BinaryTreeNode* pRight = pRoot->m_pRight;
        delete pRoot;
        pRoot = nullptr;

        destroyTree(pLeft);
        destroyTree(pRight);
    }
}
// 实际操作函数
BinaryTreeNode* getNext(BinaryTreeNode* pNode)
{
    if(pNode == nullptr)
        return nullptr;
    BinaryTreeNode* pNext = nullptr;
    if(pNode->m_pRight != nullptr)
    {
        BinaryTreeNode* pRight = pNode->m_pRight;
        while(pRight->m_pLeft != nullptr)
            pRight = pRight->m_pLeft;
        pNext = pRight;
    }
    else if(pNode->m_pParent != nullptr)
    {
        BinaryTreeNode* pCurrent = pNode;
        BinaryTreeNode* pParent = pNode->m_pParent;
        while(pParent != nullptr && pCurrent == pParent->m_pRight)
        {
            pCurrent = pParent;
            pParent = pParent->m_pParent;
        }
        pNext = pParent;
    }
    return pNext;
}
void test(const char* testName, BinaryTreeNode* pNode, BinaryTreeNode* expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    BinaryTreeNode* pNext = getNext(pNode);
    if(pNext == expected)
        printf("Passed.\n");
    else 
        printf("Failed.\n");
}
void test1(){
    BinaryTreeNode* node1  = createBinaryTreeNode(8);
    BinaryTreeNode* node2 = createBinaryTreeNode(6);
    BinaryTreeNode* node3 = createBinaryTreeNode(10);
    BinaryTreeNode* node4 = createBinaryTreeNode(5);
    BinaryTreeNode* node5 = createBinaryTreeNode(7);
    BinaryTreeNode* node6 = createBinaryTreeNode(9);
    BinaryTreeNode* node7 = createBinaryTreeNode(11);
    connectTreeNodes(node1, node2, node3);
    connectTreeNodes(node2, node4, node5);
    connectTreeNodes(node3, node6, node7);
    test("test1", node1, node6);
}
int main(int argc, char* argv[])
{
    test1();
    return 0;
}