#include <cstdio>
#include <string>
/*
题目：63 股票的最大利润
假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖交易该股票可能获得的利润是多少？
eg：一只股票在某些时间节点的价格为{9, 11, 8, 5, 7, 12, 16, 14}.如果我们在价格为5的时候买入价格为16的时候卖出，则能获得最大的利润11
*/
int maxDiff(const int* numbers, unsigned length)
{
    if(numbers == nullptr && length < 2)
        return 0;
    int min = numbers[0];
    int maxDiff = numbers[1] - min;
    for(int i = 2; i < length; i ++)
    {
        if(numbers[i - 1] < min)
            min = numbers[i - 1];
        int currentDiff = numbers[i] - min;
        if(currentDiff > maxDiff)
            maxDiff = currentDiff;
    }
    return maxDiff;
}
// test
void test(const char* testName, const int* numbers, unsigned int length, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    if(maxDiff(numbers, length) == expected)
        printf("Passed. \n");
    else 
        printf("Failed.\n");
}
int main(int argc, char* argv[])
{
    int numbers1[] = {4, 1, 3, 2, 5};
    test("test1", numbers1, sizeof(numbers1) / sizeof(int), 4);
    int numbers2[] = {1, 2, 4, 5, 11, 16, 9};
    test("test2", numbers2, sizeof(numbers2) / sizeof(int), 15);
    return 0;
}