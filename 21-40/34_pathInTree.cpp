#include <cstdio>
#include <string>
#include <vector>
/*
题目：34 二叉树中和为某一值的路径
输入一棵二叉树和某一整数，打印出二叉树中结点值的和为输入整数的所有路径。从根结点开始往下一直到叶结点所经过的结点形成一条路径。
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
void findPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int& currentSum);
void findPath(BinaryTreeNode* pRoot, int expectedSum)
{
    if(pRoot == nullptr)
        return;
    std::vector<int> path;
    int currentSum = 0;
    findPath(pRoot, expectedSum, path, currentSum);
}
void findPath(BinaryTreeNode* pRoot, int expectedSum, std::vector<int>& path, int& currentSum)
{
    currentSum += pRoot->m_dbValue;
    path.push_back(pRoot->m_dbValue);
    // 如果是叶结点，并且路径上结点的和等于输入的值，打印这条路径
    bool isLeaf = pRoot->m_pLeft == nullptr && pRoot->m_pRight == nullptr;
    if(currentSum == expectedSum && isLeaf)
    {
        printf("A path is found: ");
        std::vector<int>::iterator iter = path.begin();
        for(; iter != path.end(); ++iter)
            printf("%d\t", *iter);
        printf("\n");
    }
    // 如果不是叶结点，则遍历它的子节点
    if(pRoot->m_pLeft != nullptr)
        findPath(pRoot->m_pLeft, expectedSum, path, currentSum);
    if(pRoot->m_pRight != nullptr)
        findPath(pRoot->m_pRight, expectedSum, path, currentSum);
    // 在返回到父节点之前，在路径上删除当前结点，并在currentSum中减去当前结点的值
    currentSum -= pRoot->m_dbValue;
    path.pop_back();
}
void test(const char* testName, BinaryTreeNode* pRoot, int expectedSum)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    findPath(pRoot, expectedSum);
    printf("\n");
}
void test1()
{
    BinaryTreeNode* node1 = creareBinaryTreeNode(10);
    BinaryTreeNode* node2 = creareBinaryTreeNode(5);
    BinaryTreeNode* node3 = creareBinaryTreeNode(12);
    BinaryTreeNode* node4 = creareBinaryTreeNode(4);
    BinaryTreeNode* node5 = creareBinaryTreeNode(7);
    connectTreeNode(node1, node2, node3);
    connectTreeNode(node2, node4, node5);
    test("test1", node1, 22);
    test("test2", node1, 15);
}
int main(int argc, char* argv[])
{
    test1();
    return 0;
}