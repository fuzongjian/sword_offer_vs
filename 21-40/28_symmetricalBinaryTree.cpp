#include <cstdio>
#include <string>
/*
题目：28 对称的二叉树
请实现一个函数，用来判断一棵二叉树是不是对称的，如果一棵二叉树和它的镜像一样，那么它就是堆成的
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
bool isSymmetical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);
bool isSymmetical(BinaryTreeNode* pRoot)
{
    return isSymmetical(pRoot, pRoot);
}
bool isSymmetical(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2){
    if(pRoot1 == nullptr && pRoot2 == nullptr)
        return true;
    if(pRoot1 == nullptr || pRoot2 == nullptr)
        return false;
    if(pRoot1->m_dbValue != pRoot2->m_dbValue)
        return false;
    return isSymmetical(pRoot1->m_pLeft, pRoot2->m_pRight) && isSymmetical(pRoot1->m_pRight, pRoot2->m_pLeft);
}
void test1()
{
    BinaryTreeNode* node1 = creareBinaryTreeNode(8);
    BinaryTreeNode* node2 = creareBinaryTreeNode(6);
    BinaryTreeNode* node3 = creareBinaryTreeNode(6);
    BinaryTreeNode* node4 = creareBinaryTreeNode(5);
    BinaryTreeNode* node5 = creareBinaryTreeNode(7);
    BinaryTreeNode* node6 = creareBinaryTreeNode(7);
    BinaryTreeNode* node7 = creareBinaryTreeNode(5);
    connectTreeNode(node1, node2, node3);
    connectTreeNode(node2, node4, node5);
    connectTreeNode(node3, node6, node7);

    printf("test1 === %d\n", isSymmetical(node1) == true);
}
void test2()
{
    BinaryTreeNode* node1 = creareBinaryTreeNode(8);
    BinaryTreeNode* node2 = creareBinaryTreeNode(6);
    BinaryTreeNode* node3 = creareBinaryTreeNode(6);
    BinaryTreeNode* node4 = creareBinaryTreeNode(5);
    BinaryTreeNode* node5 = creareBinaryTreeNode(7);
    BinaryTreeNode* node6 = creareBinaryTreeNode(7);
    connectTreeNode(node1, node2, node3);
    connectTreeNode(node2, node4, node5);
    connectTreeNode(node3, node6, nullptr);

    printf("test2 === %d\n", isSymmetical(node1) == false);
}
int main(int argc, char* argv[])
{
    test1();
    test2();
    return 0;
}