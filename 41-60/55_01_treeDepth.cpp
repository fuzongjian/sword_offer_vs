#include <string>
#include <cstdio>
/*
题目：55_01 二叉树的深度
输入一棵二叉树的跟节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，求路径的长度为树的深度。
*/
// define
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
// method
int treeDepth(const BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return 0;
    int nLeft = treeDepth(pRoot->m_pLeft);
    int nRight = treeDepth(pRoot->m_pRight);
    return (nLeft > nRight) ? (nLeft + 1) : (nRight + 1);
}
// test

int main(int argc, char* argv[])
{
    BinaryTreeNode * node1 = creareBinaryTreeNode(1);
    BinaryTreeNode * node2 = creareBinaryTreeNode(2);
    BinaryTreeNode * node3 = creareBinaryTreeNode(3);
    BinaryTreeNode * node4 = creareBinaryTreeNode(4);
    BinaryTreeNode * node5 = creareBinaryTreeNode(5);
    BinaryTreeNode * node6 = creareBinaryTreeNode(6);
    BinaryTreeNode * node7 = creareBinaryTreeNode(7);

    connectTreeNode(node1, node2, node3);
    connectTreeNode(node2, node4, node5);
    connectTreeNode(node3, nullptr, node6);
    connectTreeNode(node5, node7, nullptr);

    if(treeDepth(node1) == 4)
        printf("passed.\n");
    else
        printf("failed.\n");
    return 0;
}