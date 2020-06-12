#include <cstdio>
#include <string>
/*
题目：53_02 0到n-1中缺失的数字
一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字都在范围0到n-1内；
在范围0到n-1的n个数字中有且只有一个数字不再该数组中，请找出这个数字
*/
// method
int getMissingNumber(const int* numbers, int length)
{
    if(numbers == nullptr || length <= 0)
        return -1;
    int left = 0, right = length - 1;
    while(left <= right)
    {
        int middle = (right + left) >> 1;
        if(numbers[middle] != middle)
        {
            if(middle == 0 || numbers[middle - 1] == middle - 1)
                return middle;
            right = middle - 1;
        }
        else 
            left = middle + 1;
    }
    if(left == length)
        return length;
    // 无效的输入：数组没有按要求排序或者数字不是在0到n-1范围内
    return -1;
}
// test
void test(const char* testName, int numbers[], int length, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    if(getMissingNumber(numbers, length) == expected)
        printf("passed.\n");
    else 
        printf("failed.\n");
}
int main(int argc, char* argv[])
{
    int numbers1[] = {1, 2, 3, 4, 5};
    test("test1", numbers1, sizeof(numbers1) / sizeof(int), 0);

    int numbers2[] = {0, 2, 3, 4, 5};
    test("test2", numbers2, sizeof(numbers2) / sizeof(int), 1);
    return 0;
}