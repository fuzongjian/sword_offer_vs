#include <cstdio>
#include <cstdlib>
#include <string>
/*
题目：61 扑克牌的顺子
从扑克牌中随机抽5张，判断是不是顺子，即这五张牌是不是连续的
规则：2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王可以看成任意数字。
*/
int compare(const void *arg1, const void *arg2);
bool isContinu(int* numbers, int length)
{
    if(numbers == nullptr || length < 1)
        return false;
    qsort(numbers, length, sizeof(int), compare);
    int numberOfZero = 0;
    int numberOfGap = 0;
    // 计算数组中0的个数
    for(int i = 0; i < length && numbers[i] == 0; i ++)
        ++numberOfZero;
    // 统计数组中的间隔数目
    int small = numberOfZero, big = small + 1;
    while(big < length)
    {
        // 有两个数相等，即对子，不可能是顺子
        if(numbers[small] == numbers[big])
            return false;
        numberOfGap += numbers[big] - numbers[small] - 1;
        small = big;
        ++big;
    }
    return (numberOfGap > numberOfZero) ? false : true;
}
int compare(const void *arg1, const void *arg2)
{
    return *(int*)arg1 - *(int*)arg2;
}
// test 
void test(const char* testName, int* numbers, int length, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    if(isContinu(numbers, length) == expected)
        printf("passed.\n");
    else 
        printf("failed.\n");
}
int main(int argc, char* argv[])
{
    int numbers1[] = {1, 3, 2, 5, 4};
    test("test1", numbers1, sizeof(numbers1)/sizeof(int), true);
    int numbers2[] = {0, 3, 5, 7, 0};
    test("test2", numbers2, sizeof(numbers2)/sizeof(int), true);
    return 0;
}