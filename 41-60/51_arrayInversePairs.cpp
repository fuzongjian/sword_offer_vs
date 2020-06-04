#include <string>
#include <cstdio>
/*
题目：51 数组中的逆序对
在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。
输入一个数组，求出这个数组中的逆序对的总数
*/
int inversePairsCore(int* data, int* copy, int start, int end);
int inversPairs(int* data, int length)
{
    if(data == nullptr || length < 0)
        return 0;
    int* copy = new int[length];
    for(int i = 0; i < length; i ++)
        copy[i] = data[i];
    int count = inversePairsCore(data, copy, 0, length - 1);
    delete[] copy;
    return count;
}
int inversePairsCore(int* data, int* copy, int start, int end)
{
    if(start == end)
    {
        copy[start] = data[start];
        return 0;
    }
    int length = (end - start) / 2;
    int left = inversePairsCore(copy, data, start, start + length);
    int right = inversePairsCore(copy, data, start + length + 1, end);
    // i初始化为前半段最后一个数字的下标
    int i = start + length;
    // j初始化为后半段最后一个数字的下标
    int j = end;
    int indexCopy = end, count = 0;
    while(i >= start && j >= start + length + 1)
    {
        if(data[i] > data[j])
        {
            copy[indexCopy--] = data[i--];
            count += j - start - length;
        }
        else 
            copy[indexCopy--] = data[j--];
    }
    for(; i >= start; i--)
        copy[indexCopy--] = data[i];
    for(; j >= start + length + 1; j --)
        copy[indexCopy--] = data[j];
    return left + right + count;
}
void test(const char* testName, int* data, int lenght, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    if(inversPairs(data, lenght) == expected)
        printf("Passed.\n");
    else 
        printf("Failed.\n");
}
int main(int argc, char* argv[])
{
    int data1[] = {1, 2, 3, 4, 7, 6, 5};
    test("test1", data1, sizeof(data1) / sizeof(int), 3);
    int data2[] = {1, 2, 3, 4, 5, 6, 7};
    test("test2", data2, sizeof(data2) / sizeof(int), 0);
    int data3[] = {7, 6, 5, 4, 3, 2, 1};
    test("test3", data3, sizeof(data3) / sizeof(int), 21);
    return 0;
}