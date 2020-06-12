#include <cstdio>
#include <string>
/*
题目：53_01 数字在排序数组中出现的次数
统计一个数字在排序数组中出现的次数。
eg:输入排序数组{1, 2 ,3, 3, 3, 3, 4, 5}和数字3，3出现了4次，因此输出4
*/
// method
int getFirstK(const int* data, int length, int  k, int start, int end);
int getLastK(const int* data, int length, int k, int start, int end);
int getNumberOfK(const int* data, int length, int k)
{
    int number = 0;
    if(data != nullptr && length > 0)
    {
        int first = getFirstK(data, length, k, 0, length - 1);
        int last = getLastK(data, length, k, 0, length - 1);
        if(first > - 1 && last > -1)
            number = last - first + 1;
    }
    return number;
}
/* 找出数组第一个k的下标。如果数组中不存在k， 则返回-1 */
int getFirstK(const int* data, int length, int  k, int start, int end)
{
    if(start > end)
        return -1;
    int middleIndex = (start + end) / 2;
    int middleData = data[middleIndex];
    if(middleData == k)
    {
        if((middleIndex > 0 && data[middleIndex - 1] != k) || middleIndex == 0)
            return middleIndex;
        else 
            end = middleIndex - 1;
    }
    else if(middleData > k)
        end = middleIndex - 1;
    else 
        start = middleIndex + 1;
    return getFirstK(data, length, k, start, end);
}
/* 找到数组中最后一个k的下标，如果数组中不存在k，则返回-1 */
int getLastK(const int* data, int length, int k, int start, int end)
{
    if(start > end)
        return -1;
    int middleIndex = (start + end) / 2;
    int middleData = data[middleIndex];

    if(middleData == k)
    {
        if((middleIndex < length - 1 && data[middleIndex + 1] != k) || middleIndex == length - 1)
            return middleIndex;
        else
            start = middleIndex + 1;
    }
    else if(middleData < k)
        start = middleIndex + 1;
    else 
        end = middleIndex - 1;
    return getLastK(data, length, k, start, end);
}
// test
void test(const char* testName, int data[], int length, int k, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    if(getNumberOfK(data, length, k) == expected)
        printf("passed.\n");
    else 
        printf("failed.\n");
}

int main(int argc, char* argv[])
{
    int data1[] = {1, 2, 3, 3, 3, 3, 4, 5};
    test("test1", data1, sizeof(data1) / sizeof(int), 3, 4);
     int data2[] = {1, 2, 3, 3, 3, 3, 4, 5};
    test("test2", data1, sizeof(data1) / sizeof(int), 6, 0);
    return 0;
}