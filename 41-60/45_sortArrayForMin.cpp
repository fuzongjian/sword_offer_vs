#include <cstdio>
#include <string>
#include <algorithm>
/*
题目：45 把数组排成最小的数
输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
eg：输入数组{3, 32, 321}，排成最小数字 321323
*/
int compare(const void* strNumber1, const void* strNumber2);
// int型整数用十进制表示最多只有10位
const int g_MaxNumberLength = 10;

char* g_StrCombine1 = new char[g_MaxNumberLength * 2 + 1];
char* g_StrCombine2 = new char[g_MaxNumberLength * 2 + 1];
void printMinNumber(const int* numbers, int length)
{
    if(numbers == nullptr || length <= 0)
        return;
    char ** strNumbers = (char**)(new int[length]);
    for(int i = 0; i < length; i ++)
    {
        strNumbers[i] = new char[g_MaxNumberLength + 1];
        sprintf(strNumbers[i], "%d", numbers[i]);
    }

    qsort(strNumbers, length, sizeof(char*), compare);

    for(int i = 0; i < length; i ++)
        printf("%s", strNumbers[i]);
    printf("\n");

    for(int i = 0; i < length; i ++)
        delete[] strNumbers[i];
    delete[] strNumbers;
}
// 如果[strNumber1][strNumber2] > [strNumber2][strNumber1], 返回值大于0
// 如果[strNumber1][strNumber2] = [strNumber2][strNumber1], 返回值等于0
// 如果[strNumber1][strNumber2] < [strNumber2][strNumber1], 返回值小于0
int compare(const void* strNumber1, const void* strNumber2)
{
    // [strNumber1][strNumber2]
    strcpy(g_StrCombine1, *(const char**)strNumber1);
    strcat(g_StrCombine1, *(const char**)strNumber2);
    // [strNumber2][strNumber1]
    strcpy(g_StrCombine2, *(const char**)strNumber2);
    strcat(g_StrCombine2, *(const char**)strNumber1);
    return strcmp(g_StrCombine1, g_StrCombine2);
}
// 测试
void test(const char* testName, int* numbers, int length, const char* expectedResult)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    if(expectedResult != nullptr)
        printf("Expected result is: %s\n", expectedResult);
    printf("Actual result is : ");
    printMinNumber(numbers, length);
    printf("\n");
}

int main(int argc, char* argv[])
{
    int numbers1[] = {3,5,1,4,2};
    test("test1", numbers1, sizeof(numbers1) / sizeof(int), "12345");

    int numbers2[] = {3, 32, 321};
    test("test2", numbers2, sizeof(numbers2) / sizeof(int), "321323");
    return 0;
}