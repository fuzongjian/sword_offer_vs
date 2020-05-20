#include <iostream>
#include <cmath>
using namespace std;
/*
题目：
实现函数double Power(double base, int exponent),求base的exponent
次方，不得使用库函数，同时不需要考虑大数问题
*/
bool g_InvalidInput = false;
bool equal(double num1, double num2);
double powerWithUnsignedExponent(double base, unsigned int exponent);
double Power(double base, int exponent){
    g_InvalidInput = false;
    if (equal(base, 0.0) && exponent < 0)
    {
        g_InvalidInput = true;
        return 0.0;
    }
    unsigned int absExponent = (unsigned int)(exponent);
    if (exponent < 0)
    {   
        absExponent = (unsigned int)(-exponent);
    }
    double result = powerWithUnsignedExponent(base, absExponent);
    if (exponent < 0)
    {
        result = 1.0 / result;
    }
    return result;
}
double powerWithUnsignedExponent(double base, unsigned int exponent)
{
    if (exponent == 0) return 1;
    if (exponent == 1) return base;
    double result = powerWithUnsignedExponent(base, exponent >> 1);
    result *= result;
    if ((exponent & 0x1) == 1)
    {
        result *= base;
    }
    return result;
}
bool equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
        return true;
    else
        return false;
}
int main(int argc, char* argv[])
{   // 底数、指数都为正
    double result1 = Power(2, 3);
    // 底数为负，指数为正
    double result2 = Power(-2,3);
    cout<<result1<<"____"<<result2<<endl;
    return 0;
}