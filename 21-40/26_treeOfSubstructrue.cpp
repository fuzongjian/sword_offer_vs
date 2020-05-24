#include <cstdio>
#include <string>
/*
题目：26 树的子结构
输入两棵二叉树A和B，判断B是不是A的子结构
*/
struct BinaryTreeNode
{
    double              m_dbValue;
    BinaryTreeNode*     m_pLeft;
    BinaryTreeNode*     m_pRight;
};
BinaryTreeNode* createBinaryTreeNode(double dbValue)
{
    BinaryTreeNode * pNode = new BinaryTreeNode();
    pNode->m_dbValue = dbValue;
    pNode->m_pLeft = nullptr;
    pNode->m_pRight = nullptr;
    return pNode;
}
void connectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight)
{
    if(pParent != nullptr)
    {
        pParent->m_pLeft = pLeft;
        pParent->m_pRight = pRight;
    }
}
void destoryTree(BinaryTreeNode* pRoot)
{
    if(pRoot != nullptr)
    {
        BinaryTreeNode* pLeft = pRoot->m_pLeft;
        BinaryTreeNode* pRight = pRoot->m_pRight;
        delete pRoot;
        pRoot = nullptr;

        destoryTree(pLeft);
        destoryTree(pRight);
    }
}
bool doesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2);
bool equal(double num1, double num2);
bool hasSubtree(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    bool result = false;
    if(pRoot1 != nullptr && pRoot2 != nullptr)
    {
        if(equal(pRoot1->m_dbValue, pRoot2->m_dbValue))
            result = doesTree1HaveTree2(pRoot1, pRoot2);
        if(!result)
            result = hasSubtree(pRoot1->m_pLeft, pRoot2);
        if(!result)
            result = hasSubtree(pRoot1->m_pRight, pRoot2);
    }
    return result;
}
bool doesTree1HaveTree2(BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2)
{
    if(pRoot2 == nullptr)
        return true;
    if(pRoot1 == nullptr)
        return false;
    if(!equal(pRoot1->m_dbValue, pRoot2->m_dbValue))
        return false;
    return doesTree1HaveTree2(pRoot1->m_pLeft, pRoot2->m_pLeft) && doesTree1HaveTree2(pRoot1->m_pRight, pRoot2->m_pRight);
}
bool equal(double num1, double num2)
{
   if((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}
//====================测试代码====================
// -Wc++11-compat-deprecated-writable-strings
void test(char* testName, BinaryTreeNode* pRoot1, BinaryTreeNode* pRoot2, bool expected)
{
    if(hasSubtree(pRoot1, pRoot2) == expected)
        printf("%s passed.\n", testName);
    else 
        printf("%s failed.\n", testName);
}
void test1()
{
    BinaryTreeNode* aNode1 = createBinaryTreeNode(8);
    BinaryTreeNode* aNode2 = createBinaryTreeNode(8);
    BinaryTreeNode* aNode3 = createBinaryTreeNode(7);
    BinaryTreeNode* aNode4 = createBinaryTreeNode(9);
    BinaryTreeNode* aNode5 = createBinaryTreeNode(2);
    BinaryTreeNode* aNode6 = createBinaryTreeNode(4);
    BinaryTreeNode* aNode7 = createBinaryTreeNode(7);
    connectTreeNodes(aNode1, aNode2, aNode3);
    connectTreeNodes(aNode2, aNode4, aNode5);
    connectTreeNodes(aNode5, aNode6, aNode7);

    BinaryTreeNode* bNode1 = createBinaryTreeNode(8);
    BinaryTreeNode* bNode2 = createBinaryTreeNode(9);
    BinaryTreeNode* bNode3 = createBinaryTreeNode(2);
    connectTreeNodes(bNode1, bNode2, bNode3);

    test("test1", aNode1, bNode1, true);
}
void test2()
{
     BinaryTreeNode* aNode1 = createBinaryTreeNode(8);
    BinaryTreeNode* aNode2 = createBinaryTreeNode(8);
    BinaryTreeNode* aNode3 = createBinaryTreeNode(7);
    BinaryTreeNode* aNode4 = createBinaryTreeNode(9);
    BinaryTreeNode* aNode5 = createBinaryTreeNode(3);
    BinaryTreeNode* aNode6 = createBinaryTreeNode(4);
    BinaryTreeNode* aNode7 = createBinaryTreeNode(7);
    connectTreeNodes(aNode1, aNode2, aNode3);
    connectTreeNodes(aNode2, aNode4, aNode5);
    connectTreeNodes(aNode5, aNode6, aNode7);

    BinaryTreeNode* bNode1 = createBinaryTreeNode(8);
    BinaryTreeNode* bNode2 = createBinaryTreeNode(9);
    BinaryTreeNode* bNode3 = createBinaryTreeNode(2);
    connectTreeNodes(bNode1, bNode2, bNode3);

    test("test2", aNode1, bNode1, false);
}
int main(int argc, char* argv[])
{
    test1();
    test2();
    return 0;
}