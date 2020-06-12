#include <cstdio>
#include <string>
/*
题目：53_03 数组中数值和下标相等的元素
假设一个单调递增的数组里的每个元素都是整数并且是唯一的；请实现一个函数找出数组中任意数值等于其下标的元素。
eg：在数组{-3, -1, 1, 3, 5}中，数字3和它的下标相等
*/
// method
int getEqualNumAdnIndex(const int* numbers, int length)
{
    if(numbers == nullptr || length <= 0)
        return -1;
    int left = 0, right = length - 1;
    while(left <= right)
    {
        int middle = left + ((right - left) >> 1);
        if(numbers[middle] == middle)
            return middle;
        if(numbers[middle] > middle)
            right = middle - 1;
        else 
            left = middle + 1;
    }
    return -1;
}
// test
void test(const char* testName, int numbers[], int length, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    if(getEqualNumAdnIndex(numbers, length) == expected)
        printf("passed.\n");
    else 
        printf("failed.\n");
}
int main(int argc, char* argv[])
{
    int numbers1[] = {-3, -1, 1, 3, 5};
    test("test1", numbers1, sizeof(numbers1)/sizeof(int), 3);
    return 0;
}