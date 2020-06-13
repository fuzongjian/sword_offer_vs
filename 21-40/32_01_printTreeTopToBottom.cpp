#include <string>
#include <deque>
#include <cstdio>
using namespace std;
/*
题目：32_01 不分行从上往下打印二叉树
从上往下打印出二叉树的每个结点，同一层的节点按从左到右的顺序打印
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
// method
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
void printFromTopToBottom(BinaryTreeNode* pRoot)
{
    if(pRoot == nullptr)
        return;
    std::deque<BinaryTreeNode *>dequeTreeeNode;
    dequeTreeeNode.push_back(pRoot);
    while(dequeTreeeNode.size())
    {
        BinaryTreeNode * pNode = dequeTreeeNode.front();
        dequeTreeeNode.pop_front();

        printf("%d ", pNode->m_dbValue);

        if(pNode->m_pLeft)
            dequeTreeeNode.push_back(pNode->m_pLeft);
        if(pNode->m_pRight)
            dequeTreeeNode.push_back(pNode->m_pRight);
    }
}
// test
void test(const char* testName, BinaryTreeNode* pRoot)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    printTree(pRoot);
    printf("The nodes from top to bottom, from left to right are: \n");
    printFromTopToBottom(pRoot);
    printf("\n\n");
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
    test("test1", node1);

    return 0;
}