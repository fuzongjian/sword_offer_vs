#include <string>
#include <cstdio>
#include <stdio.h>
#include <exception>
using namespace std;
/*
题目：39 数组中出现次数超过一半的数字
数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字
*/
struct Array
{
    static int randomInRange(int min, int max)
    {
        int random = rand() % (max - min + 1) + min;
        return random;
    }
    static void swap(int* num1, int* num2)
    {
        int temp = *num1;
        *num1 = *num2;
        *num2 = temp;
    }
    static int partition(int data[], int length, int start, int end)
    {
        if(data == nullptr || length <= 0 || start < 0 || end >= length)
        {
            printf("Invalid Parameters");
            return 0;
        }
        int index = randomInRange(start, end);
        swap(&data[index], &data[end]);
        int small = start - 1;
        for(index = start; index < end; ++index)
        {
            if(data[index] < data[end])
            {
                ++ small;
                if(small != index)
                    swap(&data[index], &data[small]);
            }
        }
        ++ small;
        swap(&data[small], &data[end]);
        return small;
    }
};
bool g_bInputInvalid = false;
bool checkInvalidArray(int* numbers, int length)
{
    g_bInputInvalid = false;
    if(numbers == nullptr && length <= 0)
        g_bInputInvalid = true;
    return g_bInputInvalid;
}
bool checkMoreThanHalf(int* numbers, int length, int number)
{
    int times = 0;
    for(int i = 0; i < length; i ++)
    {
        if(numbers[i] == number)
            ++times;
    }
    bool isMoreThanHalf = true;
    if(times * 2 <= length)
    {
        g_bInputInvalid = true;
        isMoreThanHalf = false;
    }
    return isMoreThanHalf;
}
int moreThanHalfNumber_solution1(int* numbers, int length)
{
    if(checkInvalidArray(numbers, length))
        return 0;
    int middle = length >> 1;
    int start = 0;
    int end = length - 1;
    int index = Array::partition(numbers, length, start, end);
    while(index != middle)
    {
        if(index > middle)
        {
            end = index - 1;
            index = Array::partition(numbers, length, start, end);
        }
        else 
        {
            start = index + 1;
            index = Array::partition(numbers, length, start, end);
        }
    }
    int result = numbers[middle];
    if(!checkMoreThanHalf(numbers, length, result))
        return 0;
    return result;
}
int moreThanHalfNumber_solution2(int* numbers, int length)
{
    if(checkInvalidArray(numbers, length))
        return 0;
    int result = numbers[0];
    int times = 1;
    for(int i = 0; i < length; i ++)
    {
        if(times == 0)
        {
            result = numbers[i];
            times = 1;
        }
        else if(numbers[i] == result)
            times ++;
        else 
            times --;
    }
    if(!checkMoreThanHalf(numbers, length, result))
        return 0;
    return result;
}
// 测试
void test(const char* testName, int* numbers, int lenght, int expectedValue, bool expectedFlag)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);
    int* copy = new int[lenght];
    for(int i = 0; i < lenght; i ++)
        copy[i] = numbers[i];
    printf("test for solution1: ");
    int result = moreThanHalfNumber_solution1(numbers, lenght);
    if(result == expectedValue && g_bInputInvalid == expectedFlag)
        printf("Passed.\n");
    else 
        printf("Failed.\n");
    printf("test for solution2: ");
    result = moreThanHalfNumber_solution2(numbers, lenght);
    if(result == expectedValue && g_bInputInvalid == expectedFlag)
        printf("Passed.\n");
    else 
        printf("Failed.\n");
    delete[] copy;
}
int main(int argc, char* argv[])
{
    int numbers1[] = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    test("test1", numbers1, sizeof(numbers1) / sizeof(int), 2 , false);
    int numbers2[] = {1, 2, 3, 2, 4, 2, 5, 2, 3};
    test("test2", numbers2, sizeof(numbers2) / sizeof(int), 0 , true);
    return 0;
}