#include <cstdio>
#include <string>
/*
题目：65 不用加减乘除做加法
写一个函数，求两个整数之和，要求在函数体内不得使用+、-、x、÷、四则运算符号
*/
int add(int num1, int num2)
{
    int sum, carry;
    do
    {
        sum = num1 ^ num2;
        carry = (num1 & num2) << 1;
        num1 = sum;
        num2 = carry;
    }while(num2 != 0);
    return num1;
}
void test(int num1, int num2, int excepted)
{
    if(add(num1, num2) == excepted)
        printf("%d + %d is %d. passed.\n", num1, num2, excepted);
    else 
        printf("%d + %d is %d. passed.\n", num1, num2, add(num1, num2));

}
int main(int argc, char* argv[])
{
    test(1, 2, 3);
    test(5, 100, 105);
    return 0;
}