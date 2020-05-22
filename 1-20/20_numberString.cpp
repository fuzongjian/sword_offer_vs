#include <stdio.h>
#include <string>
/*
题目：表示数值的字符串
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）
如："+100"、"5e2"、"-123"以及"-1E-16"都表示数值
但"12e"、"1a3.14"、"1.2.3"、"+-5"、"12e+5.4"都不是
*/
bool scanUnsignedInteger(const char** str);
bool scanInteger(const char** str);
// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，其中A和C都是整数（可以有正负号，也可以没有），而B是一个无符号整数
bool isNumber(const char* str){
    if(str == nullptr)
        return false;
    bool numberic = scanInteger(&str);
    // 如果出现'.'，接下来是数字的小数部分
    if(*str == '.')
    {
        ++str;
        // 下面一行代码用||的原因
        // 1. 小数可以没有整数部分，例如.123等于0.123
        // 2. 小数点后面可以没有数字，例如233.等于233.0
        // 3. 当然小数点前面和后面都可以有数字，例如1233.33
        numberic = scanUnsignedInteger(&str) || numberic;
    }
    if(*str == 'e' || *str == 'E')
    {
        ++str;
        // 下面一行代码用&&的原因
        // 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1
        // 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.3
        numberic = numberic && scanInteger(&str);
    }
    return numberic && *str == '\0';
}
bool scanUnsignedInteger(const char** str)
{
    const char* before = *str;
    while (**str != '\0' && **str >= '0' && **str <= '9')
        ++(*str);
    // 当str中存在若干0-9的数字时，返回true
    return *str > before;
    
}
// 整数的格式可以用[+|-]B,其中B为无符号整数
bool scanInteger(const char** str)
{
    if(**str == '+' || **str == '-')
        ++(*str);
    return scanUnsignedInteger(str);
}
int main(int argc, char* argv[]){
    // char strings[] = {'12e', "-1E-16", "-.123"};
    //bool status = isNumber("123.45e+6"); // true
    bool status = isNumber("12e"); // false
    printf("status == %d", status);
    return 0;
}