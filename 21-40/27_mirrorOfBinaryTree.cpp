#include <cstdio>
#include <string>
#include <stack>
using namespace std;
/*
题目：27 二叉树的镜像
请完成一个函数，输入一个二叉树，该函数输出它的镜像
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
void mirrorRecursively(BinaryTreeNode* pNode)
{
    if((pNode == nullptr) || (pNode->m_pLeft == nullptr && pNode->m_pRight))
        return;
    BinaryTreeNode* pTemp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = pTemp;

    if(pNode->m_pLeft)
        mirrorRecursively(pNode->m_pLeft);
    if(pNode->m_pRight)
        mirrorRecursively(pNode->m_pRight);
}
void mirrorIteratively(BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return;
    
    std::stack<BinaryTreeNode*> stackTreeNode;
    stackTreeNode.push(pRoot);

    while(stackTreeNode.size() > 0)
    {
        BinaryTreeNode* pNode = stackTreeNode.top();
        stackTreeNode.pop();

        BinaryTreeNode* pTemp = pNode->m_pLeft;
        pNode->m_pLeft = pNode->m_pRight;
        pNode->m_pRight = pTemp;

        if(pNode->m_pLeft)
            stackTreeNode.push(pNode->m_pLeft);
        if(pNode->m_pRight)
            stackTreeNode.push(pNode->m_pRight);
    }
}
void test1()
{
    printf("===test1 start:===\n");
    BinaryTreeNode* node1 = creareBinaryTreeNode(8);
    BinaryTreeNode* node2 = creareBinaryTreeNode(6);
    BinaryTreeNode* node3 = creareBinaryTreeNode(10);
    BinaryTreeNode* node4 = creareBinaryTreeNode(5);
    BinaryTreeNode* node5 = creareBinaryTreeNode(7);
    BinaryTreeNode* node6 = creareBinaryTreeNode(9);
    BinaryTreeNode* node7 = creareBinaryTreeNode(11);
    connectTreeNode(node1, node2, node3);
    connectTreeNode(node2, node4, node5);
    connectTreeNode(node3, node6, node7);
    printTree(node1);
    printf("===== mirrorRecursively =====\n");
    mirrorRecursively(node1);
    printTree(node1);
    printf("===== mirrorIteratively =====\n");
    mirrorIteratively(node1);
    printTree(node1);
}
int main(int argc, char* argv[])
{
    test1();
    return 0;
}