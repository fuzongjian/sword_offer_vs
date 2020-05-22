#include <cstdio>
#include <string>
/*
题目：调整数组顺序使奇数位于偶数前面
输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组的前半部分，所有偶数位于数组的后半部分。
*/
void reorder(int *pData, unsigned int length, bool(*func)(int));
bool isEven(int n);
void solution_1(int *pData, unsigned int length)
{
    if(pData == nullptr || length == 0)
        return;
    int *pBegin = pData;
    int *pEnd = pData + length - 1;
    while(pBegin < pEnd)
    {
        while(pBegin < pEnd && (*pBegin & 0x1) != 0)
            pBegin ++;
        while(pBegin < pEnd && (*pEnd & 0x1) == 0)
            pEnd --;
        if(pBegin < pEnd)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}
void solution_2(int *pData, unsigned int length)
{
    reorder(pData, length, isEven);
}
void reorder(int *pData, unsigned int length, bool(*func)(int))
{
    if(pData == nullptr || length == 0)
        return;
    int *pBegin = pData;
    int *pEnd = pData + length - 1;

    while(pBegin < pEnd)
    {
        // 向后移动pBegin
        while(pBegin < pEnd && !func(*pBegin))
            pBegin ++;
        // 向前移动pEnd
        while(pBegin < pEnd && func(*pEnd))
            pEnd --;
        if(pBegin < pEnd)
        {
            int temp = *pBegin;
            *pBegin = *pEnd;
            *pEnd = temp;
        }
    }
}
bool isEven(int n)
{
    return (n & 1) == 0;
}
void printArray(int numbers[], int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d\t", numbers[i]);
    }
    printf("\n");
    
}
int main(int argc, char* argv[]){
    int number1[] = {1,2,3,4,5,6,7};
    int length = sizeof(number1)/sizeof(int);
    printArray(number1, length);
    solution_1(number1, length);
    printArray(number1, length);
    return 0;
}