#include <cstdio>
#include <string>
/* 题目3_02：不修改数组找出重复的数字
在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至少有一个数字时重复的。
请找出数组中重复的数字，但不能修改输入数组
eg：输入数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应输出就应是2或3
*/ 
// method
int countRange(const int* numbers, int lenght, int start, int end);
int getDuplication(const int* numbers, int length)
{
    if(numbers == nullptr || length <= 0)
        return -1;
    int start = 1, end = length - 1;
    while(end >= start)
    {
        // (end - start) >> 1 先将(end - start)的差值转为二进制，再右移1位，eg：1010右移动1位为101
        int middle = ((end - start) >> 1) + start;
        // 主要是根据中间值查找（有二分法的思想）
        int count = countRange(numbers, length, start, middle);
        printf("middle === %d, count === %d \n", middle, count);
        if(end == start)
        {
            if(count > 1)
                return start;
            else 
                break;
        }
        // 重复数字在前半段
        if(count > (middle - start + 1))
            end = middle;
        // 重复数字在后半段
        else 
            start = middle + 1;
    }
    return -1;
}

int countRange(const int* numbers, int length, int start, int end)
{
    if(numbers == nullptr)
        return 0;
    int count = 0;
    for(int i = 0; i < length; i ++)
        if(numbers[i] >= start && numbers[i] <= end)
            ++count;
    return count;
}
// test
void test(const char* testName, int* numbers, int length, int* duplications, int dupLength)
{
    int result = getDuplication(numbers, length);
    for(int i = 0; i < dupLength; i ++)
    {
        if(result == duplications[i])
        {
            printf("%s passed.\n", testName);
            return;
        }
    }
    printf("%s failed.\n", testName);
}
int main(int argc, char* argv[])
{
    int numbers[] = {2, 3, 5, 4, 3, 2, 6, 7};
    int duplications[] = {2, 3};
    test("test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
    return 0;
}