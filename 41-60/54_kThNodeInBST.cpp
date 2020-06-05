#include <string>
#include <cstdio>
/*
题目：54 二叉搜索树的第k个结点
给定一棵二叉搜索树，请找出其中的第k大的结点
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
// 方法
const BinaryTreeNode* kthNodeCore(const BinaryTreeNode* pRoot, unsigned int& k);
const BinaryTreeNode* kthNode(const BinaryTreeNode* pRoot, unsigned int k)
{
    if(pRoot == nullptr || k == 0)
        return nullptr;
    return kthNodeCore(pRoot, k);
}
const BinaryTreeNode* kthNodeCore(const BinaryTreeNode* pRoot, unsigned int& k)
{
    const BinaryTreeNode* target = nullptr;
    if(pRoot->m_pLeft != nullptr)
        target = kthNodeCore(pRoot->m_pLeft, k);
    if(target == nullptr)
    {
        if(k == 1)
            target = pRoot;
        k --;
    }
    if(target == nullptr && pRoot->m_pRight != nullptr)
        target = kthNodeCore(pRoot->m_pRight, k);
    return target;
}
// test
void test(const char* testName, const BinaryTreeNode* pRoot, unsigned int k, bool isNull, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    const BinaryTreeNode* pTarget = kthNode(pRoot, k);
    if((isNull && pTarget == nullptr) || (!isNull && pTarget->m_dbValue == expected))
        printf("Passed.\n");
    else 
        printf("Failed.\n");
}
int main(int argc, char* argv[])
{
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

    test("test1", node1, 0, true, -1);
    test("test2", node1, 1, false, 5);
    test("test3", node1, 2, false, 6);
    return 0;
}