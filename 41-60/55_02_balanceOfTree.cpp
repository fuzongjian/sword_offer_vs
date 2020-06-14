#include <string>
#include <cstdio>
/*
题目：55_02 平衡二叉树
输入一棵二叉树的根结点，判断该树是不是平衡二叉树。
如果某二叉树中任意结点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
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
// solution one
bool isBalance_solution1(const BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return true;
    int left = treeDepth(pRoot->m_pLeft);
    int right = treeDepth(pRoot->m_pRight);
    int diff = left - right;
    if(diff > 1 || diff < -1)
        return false;
    return isBalance_solution1(pRoot->m_pLeft) && isBalance_solution1(pRoot->m_pRight);
}
// method two
bool isBalanced(const BinaryTreeNode* pRoot, int* pDepth);
bool isBalance_solution2(const BinaryTreeNode* pRoot)
{
    int depth = 0;
    return isBalanced(pRoot, &depth);
}
bool isBalanced(const BinaryTreeNode* pRoot, int* pDepth)
{
    if(pRoot == nullptr)
    {
        *pDepth = 0;
        return true;
    }
    int left, right;
    if(isBalanced(pRoot->m_pLeft, &left) && isBalanced(pRoot->m_pRight, &right))
    {
        int diff = left - right;
        if(diff <= 1 && diff >= -1)
        {
            *pDepth = 1 + (left > right ? left : right);
            return true;
        }
    }
    return false;
}

//             1
//         /      \
//        2        3
//       /\       / \
//      4  5     6   7
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
    connectTreeNode(node3, node6, node7);

    if(isBalance_solution1(node1))
        printf("solution1 passed.\n");
    else 
        printf("solution1 failed.\n");

     if(isBalance_solution2(node1))
        printf("solution2 passed.\n");
    else 
        printf("solution2 failed.\n");
    return 0;
}