#include <cstdio>
#include <string>
#include <stack>
/*
题目：31 栈的压入、弹出序列
输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序，假设压入栈的所有数字均不相等。
如：1、2、3、4、5是某栈的压入序列，序列4、5、、3、2、1是该压入栈序列对应的一个弹出序列，但4、3、5、1、2就不可能是该压入栈序列的弹出序列
*/
bool isPopOrder(const int* pPush, const int* pPop, int nLength)
{
    bool bPossible = false;
    if(pPush != nullptr && pPop != nullptr && nLength > 0)
    {
        const int* pNextPush = pPush;
        const int* pNextPop = pPop;

        std::stack<int> stackData;
        while(pNextPop - pPop < nLength)
        {
            // 当辅助栈的栈顶元素不是要弹出的元素， 先压入一些数字入栈
            while(stackData.empty() || stackData.top() != *pNextPop)
            {
                // 如果所有数字都压入辅助栈了，退出循环
                if(pNextPush - pPush == nLength)
                    break;
                stackData.push(*pNextPush);
                pNextPush ++;
            }
            if(stackData.top() != *pNextPop)
                break;
            stackData.pop();
            pNextPop ++;
        }
        if(stackData.empty() && pNextPop - pPop == nLength)
            bPossible = true;
    }
    return bPossible;
}
void test(const char* testName, const int* pPush, const int* pPop, int nLength, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    if(isPopOrder(pPush, pPop, nLength) == expected)
        printf("Passed.\n");
    else 
        printf("Failed.\n");
}
void test1()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 5, 3, 2, 1};
    test("test1", push, pop, nLength, true);
}
void test2()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {3, 5, 4, 2, 1};
    test("test2", push, pop, nLength, true);
}
void test3()
{
    const int nLength = 5;
    int push[nLength] = {1, 2, 3, 4, 5};
    int pop[nLength] = {4, 3, 5, 1, 2};
    test("test2", push, pop, nLength, false);
}
int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    return 0;
}