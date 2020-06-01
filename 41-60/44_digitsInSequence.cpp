#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
/*
题目：44 数字序列中某一位的数字
数字以01234567891011121314151617...的格式序列化到一个字符串序列。
eg：第5位（从0开始计数）是5，第13位是1，第19位是4，等等。请写一个函数求任意位对应的数字
*/
int countOfIntegers(int digits);
int digitAtIndex(int index, int digits);
int beginNumber(int digits);
int digitAtIndex(int index)
{
     if(index < 0)
        return -1;
    int digits = 1;
    while(true)
    {
        int numbers = countOfIntegers(digits);
        if(index < numbers * digits)
            return digitAtIndex(index, digits);
        index -= digits * numbers;
        digits ++;   
    }
    return -1;
}
int countOfIntegers(int digits)
{
    if(digits == 1)
        return 10;
    int count = (int)pow(10, digits - 1);
    return 9 * count;
}
int digitAtIndex(int index, int digits)
{
    int number = beginNumber(digits) + index / digits;
    int indexFromRight = digits - index % digits;
    for(int i = 1; i < indexFromRight; i ++)
        number /= 10;
    return number % 10;
}
int beginNumber(int digits)
{
    if(digits == 1)
        return 0;
    return (int)pow(10, digits - 1);
}
void test(const char* testName, int inputIndex, int expectedOutput)
{
    if(digitAtIndex(inputIndex) == expectedOutput)
        cout << testName << " passed." << endl;
    else 
        cout << testName << " failed." << endl;
}
int main(int argc, char* argv[])
{
    test("test1", 0, 0);
    test("test2", 9, 9);
    test("test3", 10, 1);
    test("test4", 189, 9);
    return 0;
}