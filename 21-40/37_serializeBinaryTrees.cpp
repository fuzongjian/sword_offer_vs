#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
/*
题目：37 序列化二叉树
请实现两个函数，分别用来序列化和反序列化二叉树
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
void serialize(const BinaryTreeNode* pRoot, ostream& stream)
{
    if(pRoot == nullptr)
    {
        stream << "$,";
        return;
    }
    stream << pRoot->m_dbValue << ',';
    serialize(pRoot->m_pLeft, stream);
    serialize(pRoot->m_pRight, stream);
}
bool ReadStream(istream& stream, int* number)
{
    if(stream.eof())
        return false;
    char buffer[32];
    buffer[0] = '\0';

    char ch;
    stream >> ch;
    int i = 0;
    while(!stream.eof() && ch != ',')
    {
        buffer[i++] = ch;
        stream >> ch;
    }
    bool isNumberic = false;
    if(i > 0 && buffer[0] != '$')
    {
        *number = atoi(buffer);
        isNumberic = true;
    }
    return isNumberic;
}
void deserialize(BinaryTreeNode** pRoot,istream& stream)
{
    int number;
    if(ReadStream(stream, &number))
    {
        *pRoot = new BinaryTreeNode();
        (*pRoot)->m_dbValue = number;
        (*pRoot)->m_pLeft = nullptr;
        (*pRoot)->m_pRight = nullptr;

        deserialize(&((*pRoot)->m_pLeft), stream);
        deserialize(&((*pRoot)->m_pRight), stream);
    }
}
// test
bool isSameTree(const BinaryTreeNode* pRoot1, const BinaryTreeNode* pRoot2)
{
    if(pRoot1 == nullptr && pRoot2 == nullptr)
        return true;
    if(pRoot1 == nullptr || pRoot2 == nullptr)
        return false;
    if(pRoot1->m_dbValue != pRoot2->m_dbValue)
        return false;
    return isSameTree(pRoot1->m_pLeft, pRoot2->m_pLeft) && isSameTree(pRoot1->m_pRight, pRoot2->m_pRight);
}
void test(const char* testName, const BinaryTreeNode* pRoot)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);
    printTree(pRoot);
    char* fileName = "test.txt";
    ofstream fileOut;
    fileOut.open(fileName);

    serialize(pRoot, fileOut);
    fileOut.close();

    ifstream fileIn1;
    char ch;
    fileIn1.open(fileName);
    while(!fileIn1.eof())
    {
        fileIn1 >> ch;
        cout << ch;
    }
    fileIn1.close();
    cout << endl;

    ifstream fileIn2;
    fileIn2.open(fileName);
    BinaryTreeNode* pNewRoot = nullptr;
    deserialize(&pNewRoot, fileIn2);
    fileIn2.close();

    printTree(pNewRoot);
    if(isSameTree(pRoot, pNewRoot))
        printf("The deserialized tree is same as the oritinal tree.\n\n");
    else
        printf("The deserialized tree is NOT same as the oritinal tree.\n\n");
}
void test1()
{
    BinaryTreeNode * node1 = creareBinaryTreeNode(8);
    BinaryTreeNode * node2 = creareBinaryTreeNode(6);
    BinaryTreeNode * node3 = creareBinaryTreeNode(10);
    BinaryTreeNode * node4 = creareBinaryTreeNode(5);
    BinaryTreeNode * node5 = creareBinaryTreeNode(7);
    BinaryTreeNode * node6 = creareBinaryTreeNode(9);
    BinaryTreeNode * node7 = creareBinaryTreeNode(11);

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