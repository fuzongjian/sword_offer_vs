#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
/*
题目：43 从1到n整数中1出现的次数
输入一个整数n，求从1到n个整数的十进制表示中1出现的次数。
eg：输入12，从1到123这些整数中包含1的数字有1、10、11和12，1一共出现5次。
*/
int numberOf1(unsigned int n);
int numberOf1Between1AndN_solution1(unsigned int n)
{
    int number = 0;
    for(unsigned int i = 1; i <= n; i ++)
        number += numberOf1(i);
    return number;
}
int numberOf1(unsigned int n)
{
    int number = 0;
    while(n)
    {
        if(n % 10 == 1)
            number ++;
        n = n / 10;
    }
    return number;
}
// solution2
int numberOf1(const char* strN);
int powerBase10(unsigned int n);
int numberOf1Between1AndN_solution2(int n)
{
    if(n <= 0)
        return 0;
    char strN[50];
    sprintf(strN, "%d", n);
    return numberOf1(strN);
}
int numberOf1(const char* strN)
{
    if(!strN || *strN < '0' || *strN > '9' || *strN == '\0')
        return 0;
    int first = *strN - '0';
    unsigned int length = static_cast<unsigned int>(strlen(strN));
    if(length == 1 && first == 0)
        return 0;
    if(length == 1 && first > 0)
        return 1;
    // 假设strN是"21345"
    // numFirstDigit是数字10000-19999的第一个位中1的数目
    int numFirstDigit = 0;
    if(first > 1)
        numFirstDigit = powerBase10(length - 1);
    else if(first == 1)
        numFirstDigit = atoi(strN + 1) + 1;
    int numOtherDigits = first * (length - 1) * powerBase10(length - 2);
    int numRecursive = numberOf1(strN + 1);
    return numFirstDigit + numOtherDigits + numRecursive;
}
int powerBase10(unsigned int n)
{
    int result = 1;
    for(unsigned int i = 0; i < n; i ++)
        result *= 10;
    return result;
}
void test(const char* testName, int n, int expected)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);
    if(numberOf1Between1AndN_solution1(n) == expected)
        printf("solution1 passed.\n");
    else 
        printf("solution1 failed.\n");
    if(numberOf1Between1AndN_solution2(n) == expected)
        printf("solution2 passed.\n");
    else 
        printf("solution2 failed.\n");
}
int main(int argc, char* argv[])
{   
    test("test1", 55, 16);

    return 0;
}