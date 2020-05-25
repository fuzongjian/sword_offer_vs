#include <cstdio>
#include <string>
/*
题目：33 二叉搜索树   BST：Binary Search Tree
输入一个整数数组，判断该数组是不是某二叉搜索树的后续遍历的结果。
如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。
*/
bool vertifySquenceOfBST(int sequence[], int length)
{
    if(sequence == nullptr || length <= 0)
        return false;
    int root = sequence[length - 1];
    // 在二叉搜索树中左子树的结点小于根结点
    int i = 0;
    for(; i < length - 1; i ++)
    {
        if(sequence[i] > root)
            break;
    }
    // 在二叉搜索树中右子树的结点大于根结点
    int j = i;
    for(; j < length - 1; j ++)
    {
        if(sequence[j] < root)
            return false;
    }
    // 判断左子树是不是二叉搜索树
    bool left = true;
    if(i > 0)
        left = vertifySquenceOfBST(sequence, i);
    // 判断右子树是不是二叉搜索树
    bool right = true;
    if(i < length - 1)
        right = vertifySquenceOfBST(sequence + i, length - i - 1);
    return (left && right);
}
void test(const char* testName, int sequence[], int length, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    if(vertifySquenceOfBST(sequence, length) == expected)
        printf("passed.\n");
    else 
        printf("failed.\n");
}
//            10
//         /      \
//        6        14
//       /\        /\
//      4  8     12  16
void test1()
{
    int data[] = {4, 8, 6, 12, 16, 14, 10};
    test("test1", data, sizeof(data)/sizeof(int), true);
}
void test2()
{
    int data[] = {4, 6, 12, 8, 16, 14, 10};
    test("test2", data, sizeof(data)/sizeof(int), false);
}
int main(int argc, char* argv[])
{
    test1();
    test2();
    return 0;
}