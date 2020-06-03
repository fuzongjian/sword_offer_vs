#include <cstdio>
/*
题目：49 丑数
我们把只包含因子2、3、5的数称做为抽数。
求按从小到大的顺序的第1500个丑数。例如6、8都是丑数，但14不是，因为它包含因子7。习惯上我们把1当做第一个丑数。
*/
// solution1
bool isUgly(int number)
{
    while(number % 2 == 0)
        number /= 2;
    while(number % 3 == 0)
        number /= 3;
    while(number % 5 == 0)
        number /= 5;
    return (number == 1) ? true : false;
}
int getUglyNumber_solution1(int index)
{
    if(index <= 0)
        return 0;
    int number = 0, uglyFound = 0;
    while (uglyFound < index)
    {
        ++ number;
        if(isUgly(number))
            ++ uglyFound;
    }
    return number;
}
// solution2
int Min(int number1, int number2, int number3);
int getUglyNumber_solution2(int index)
{
    if(index <= 0)
        return 0;
    int *pUglyNumbers = new int[index];
    pUglyNumbers[0] = 1;
    int nextUglyIndex = 1;

    int * pMultiply2 = pUglyNumbers;
    int * pMultiply3 = pUglyNumbers;
    int * pMultiply5 = pUglyNumbers;

    while(nextUglyIndex < index)
    {
        int min = Min(*pMultiply2*2, *pMultiply3*3, *pMultiply5*5);
        pUglyNumbers[nextUglyIndex] = min;

        while(*pMultiply2 * 2 <= pUglyNumbers[nextUglyIndex])
            ++ pMultiply2;
        while(*pMultiply3 * 3 <= pUglyNumbers[nextUglyIndex])
            ++ pMultiply3;
        while(*pMultiply5 * 5 <= pUglyNumbers[nextUglyIndex])
            ++ pMultiply5;

        ++ nextUglyIndex; 
    }
    int ugly = pUglyNumbers[nextUglyIndex - 1];
    delete[] pUglyNumbers;
    return ugly;
}
int Min(int number1, int number2, int number3)
{
    int min = (number1 < number2) ? number1 : number2;
    min = (min < number3) ? min : number3;
    return min;
}
void test(int index, int expected)
{
    if(getUglyNumber_solution1(index) == expected)
        printf("solution1 passed.\n");
    else    
        printf("solution1 failed.\n");

    if(getUglyNumber_solution2(index) == expected)
        printf("solution2 passed.\n");
    else    
        printf("solution2 failed.\n");
}
int main(int argc, char* argv[])
{
    test(2, 2);
    test(11, 15);
    return 0;
}