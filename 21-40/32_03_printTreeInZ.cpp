#include <cstdio>
#include <stack>
#include <string>
using namespace std;
/*
题目：32_03 之字行打印二叉树
请实现一个函数按照之字形顺序打印二叉树，及第一行按照从左到右顺序打印，第二行从右往左打印，以此类推
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
void printInZ(BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return;
    std::stack<BinaryTreeNode*> levels[2];
    int current = 0, next = 1;

    levels[current].push(pRoot);
    while(!levels[0].empty() || !levels[1].empty())
    {
        BinaryTreeNode* pNode = levels[current].top();
        levels[current].pop();
        printf("%d ", pNode->m_dbValue);
        if(current == 0)
        {
            if(pNode->m_pLeft != nullptr)
                levels[next].push(pNode->m_pLeft);
            if(pNode->m_pRight != nullptr)
                levels[next].push(pNode->m_pRight);
        }
        else 
        {
            if(pNode->m_pRight != nullptr)
                levels[next].push(pNode->m_pRight);
            if(pNode->m_pLeft != nullptr)
                levels[next].push(pNode->m_pLeft);
        }
        if(levels[current].empty())
        {
            printf("\n");
            current = 1 - current;
            next = 1 - next;
        }
    }
}
//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
int main(int argc, char* argv[])
{
    BinaryTreeNode * node1 = creareBinaryTreeNode(10);
    BinaryTreeNode * node2 = creareBinaryTreeNode(6);
    BinaryTreeNode * node3 = creareBinaryTreeNode(14);
    BinaryTreeNode * node4 = creareBinaryTreeNode(4);
    BinaryTreeNode * node5 = creareBinaryTreeNode(8);
    BinaryTreeNode * node6 = creareBinaryTreeNode(12);
    BinaryTreeNode * node7 = creareBinaryTreeNode(16);

    connectTreeNode(node1, node2, node3);
    connectTreeNode(node2, node4, node5);
    connectTreeNode(node3, node6, node7);


    printf("Expected result is: \n");
    printf("10 \n");
    printf("14 6 \n");
    printf("4 8 12 16\n");
    printf("Actual result is: \n");
    printInZ(node1);

    return 0;
}