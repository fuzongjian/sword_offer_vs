#include <cstdio>
#include <string>
/*
题目：42 连续子数组的最大和
输入一个整型数组，数组里有正数也有负数，数组中一个或连续的多个整数组组成一个子数组；
求所有子数组的和的最大值，要求时间复杂度为O(n)
*/
bool g_InvalidInput = false;
bool findMaxSumOfSubArray(int *pData, int nLength)
{
    if((pData == nullptr) || (nLength <= 0))
    {
        g_InvalidInput = true;
        return 0;
    }
    g_InvalidInput = false;
    int nCurSum = 0;
    int nMaxSum = 0x80000000;
    for(int i = 0; i < nLength; i ++)
    {
        if(nCurSum <= 0)
            nCurSum = pData[i];
        else 
            nCurSum += pData[i];
        if(nCurSum > nMaxSum)
            nMaxSum = nCurSum;
    }
    return nMaxSum;
}
// test
void test(const char* testName, int* pData, int nLength, int expected, bool expectedFlag)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);
    int result = findMaxSumOfSubArray(pData, nLength);
    if((result == expected) && (expectedFlag == g_InvalidInput))
        printf("Passed.\n");
    else 
        printf("Failed.\n");
}
void test1()
{
    int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
    test("test1", data, sizeof(data) / sizeof(int), 18, false);
}
int main(int argc, char* argv[])
{
    test1();
    return 0;
}