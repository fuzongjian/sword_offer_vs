#include <string>
#include <list>
#include <vector>
using namespace std;
/*
题目：68 树中两个节点的最低公共祖先
输入两个树接地那，求他们最低公共祖先
*/
// define
struct TreeNode
{
    int                         m_nValue;
    std::vector<TreeNode*>      m_vChildren;
};
class List
{
public:
    static TreeNode* createTreeNode(int value)
    {
        TreeNode * pNode = new TreeNode();
        pNode->m_nValue = value;
        return pNode;
    }
    static void connectTreeNodes(TreeNode* pParent, TreeNode* pChild)
    {
        if(pParent != nullptr)
            pParent->m_vChildren.push_back(pChild);
    }
    static void printTreeNode(const TreeNode* pNode)
    {
        if(pNode != nullptr)
        {
            printf("value of this node is: %d.\n", pNode->m_nValue);
            printf("its children is as the following:\n");
            std::vector<TreeNode*>::const_iterator i = pNode->m_vChildren.begin();
            while(i < pNode->m_vChildren.end())
            {
                if(*i != nullptr)
                    printf("%d\t", (*i)->m_nValue);
            }
            printf("\n");
        }
        else
        {
            printf("this node is nullptr.\n");
        }
        printf("\n");
    }
    static void printTree(const TreeNode* pRoot)
    {
        printTreeNode(pRoot);
        if(pRoot != nullptr)
        {
            std::vector<TreeNode*>::const_iterator i = pRoot->m_vChildren.begin();
            while(i < pRoot->m_vChildren.end())
            {
                printTree(*i);
                ++i;
            }
        }
    }
    static void destroyTree(TreeNode* pRoot)
    {
        if(pRoot != nullptr)
        {
            std::vector<TreeNode*>::iterator i = pRoot->m_vChildren.begin();
            while(i < pRoot->m_vChildren.end())
            {
                destroyTree(*i);
                ++ i;
            }
            delete pRoot;
        }
    }
};

// method
bool getNodePath(const TreeNode* pRoot, const TreeNode* pNode, list<const TreeNode*>& path)
{
    if(pRoot == pNode)
        return true;
    path.push_back(pRoot);
    bool found = false;
    vector<TreeNode*>::const_iterator i = pRoot->m_vChildren.begin();
    while(!found && i < pRoot->m_vChildren.end())
    {
        found = getNodePath(*i, pNode, path);
        ++i;
    }
    if(!found)
        path.pop_back();
    return found;
}
const TreeNode* getLastCommonNode(const list<const TreeNode*>& path1, const list<const TreeNode*>& path2)
{
    list<const TreeNode*>::const_iterator iterator1 = path1.begin();
    list<const TreeNode*>::const_iterator iterator2 = path2.begin();
    const TreeNode* pLast = nullptr;
    while(iterator1 != path1.end() && iterator2 != path2.end())
    {
        if(*iterator1 == *iterator2)
            pLast = *iterator1;
        iterator1++;
        iterator2++;
    }
    return pLast;
}
const TreeNode* getLastCommonParent(const TreeNode* pRoot, const TreeNode* pNode1, const TreeNode* pNode2)
{
    if(pRoot == nullptr || pNode1 == nullptr || pNode2 == nullptr)
        return nullptr;
    list<const TreeNode*> path1;
    getNodePath(pRoot, pNode1, path1);

    list<const TreeNode*> path2;
    getNodePath(pRoot, pNode2, path2);

    return getLastCommonNode(path1, path2);
}
// test
void test(const char* testName, const TreeNode* pRoot, const TreeNode* pNode1, const TreeNode* pNode2, TreeNode* pExpected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    const TreeNode* pResult = getLastCommonParent(pRoot, pNode1, pNode2);

    if((pExpected == nullptr && pResult == nullptr)||(pExpected != nullptr && pResult != nullptr && pResult->m_nValue == pExpected->m_nValue))
        printf("passed.\n");
    else 
        printf("failed.\n");
}
// 形状普通的树
//              1
//            /   \
//           2     3
//       /       \
//      4         5
//     / \      / |  \
//    6   7    8  9  10
void test1()
{
    TreeNode * node1 = List::createTreeNode(1);
    TreeNode * node2 = List::createTreeNode(2);
    TreeNode * node3 = List::createTreeNode(3);
    TreeNode * node4 = List::createTreeNode(4);
    TreeNode * node5 = List::createTreeNode(5);
    TreeNode * node6 = List::createTreeNode(6);
    TreeNode * node7 = List::createTreeNode(7);
    TreeNode * node8 = List::createTreeNode(8);
    TreeNode * node9 = List::createTreeNode(9);
    TreeNode * node10 = List::createTreeNode(10);

    List::connectTreeNodes(node1, node2);
    List::connectTreeNodes(node1, node3);

    List::connectTreeNodes(node2, node4);
    List::connectTreeNodes(node2, node5);

    List::connectTreeNodes(node4, node6);
    List::connectTreeNodes(node4, node7);

    List::connectTreeNodes(node5, node8);
    List::connectTreeNodes(node5, node9);
    List::connectTreeNodes(node5, node10);
    test("test1", node1, node6, node8, node2);
}
void test2()
{
    TreeNode* node1 = List::createTreeNode(1);
    TreeNode* node2 = List::createTreeNode(2);
    TreeNode* node3 = List::createTreeNode(3);
    TreeNode* node4 = List::createTreeNode(4);
    TreeNode* node5 = List::createTreeNode(5);

    List::connectTreeNodes(node1, node2);
    List::connectTreeNodes(node2, node3);
    List::connectTreeNodes(node3, node4);
    List::connectTreeNodes(node4, node5);
    test("test2", node1, node5, node4, node3);
}
int main(int argc, char* argv[])
{
    test1();
    test2();
    return 0;
}