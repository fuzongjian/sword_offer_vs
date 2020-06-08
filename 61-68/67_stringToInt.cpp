#include <string>
#include <cstdio>
/*
题目：67 把字符串转换为整数
请写一个函数StrToInt, 实现把字符串转换为整数这个功能。不能使用atoi或者其他类似的库函数
*/
long long StrToIntCore(const char* str, bool minus);
enum Status{kValid = 0, kInvalid};
int g_nStatus = kValid;
int StrToInt(const char* str)
{
    g_nStatus = kInvalid;
    long long num = 0;
    if(str != nullptr && *str != '\0')
    {
        bool minus = false;
        if(*str == '+')
            str ++;
        else if(*str == '-')
        {
            str ++;
            minus = true;
        }
        if(*str != '\0')
            num = StrToIntCore(str, minus);
    }
    return (int)num;
}
long long StrToIntCore(const char* digit, bool minus)
{
    long long num = 0;
    while(*digit != '\0')
    {
        if(*digit >= '0' && *digit <= '9')
        {
            int flag = minus ? -1 : 1;
            num = num * 10 + flag * (*digit - '0');

            if((!minus && num > 0x7FFFFFFF) ||(minus && num < (signed int)0x80000000))
            {
                num = 0;
                break;
            }
            digit ++;
        }
        else 
        {
            num = 0;
            break;
        }
    }
    if(*digit == '\0')
        g_nStatus = kValid;
    return num;
}
// test
void test(const char* string)
{
    int result = StrToInt(string);
    if(result == 0 && g_nStatus == kInvalid)
        printf("the input %s is invalid.\n", string);
    else 
        printf("number of %s is %d.\n", string, result);
}
int main(int argc, char* argv[])
{
    test(nullptr);
    test("123");
    test("");
    test("a");
    test("+2342");
    return 0;
}