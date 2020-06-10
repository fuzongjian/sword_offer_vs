#include <string>
#include <cstdio>
/* 题目5：替换空格
请实现一个函数，把字符串中的每个空格替换成"%20"
eg:输入"We are happy"，则输出"We%20are%20happy"
*/ 
// method
void replaceBlank(char str[], int length)
{
    if(str == nullptr && length <= 0)
        return;
    // originalLength为字符串str的原始长度
    int originalLength = 0, numberOfBlank = 0;
    int i = 0;
    while(str[i] != '\0')
    {
        ++ originalLength;
        if(str[i] == ' ')
            ++numberOfBlank;
        ++ i;
    }
    // newLength 为替换空格之后的长度
    int newLength = originalLength + numberOfBlank * 2;
    if(newLength > length)
        return;
    int indexOfOriginal = originalLength;
    int indexOfNew = newLength;
    while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
    {
        if(str[indexOfOriginal] == ' ')
        {
            str[indexOfNew --] = '0';
            str[indexOfNew --] = '2';
            str[indexOfNew --] = '%';
        }
        else 
        {
            str[indexOfNew --] = str[indexOfOriginal];
        }
        -- indexOfOriginal;
    }
}
// test

int main(int argc, char* argv[])
{
    char string1[100] = "hello world";
    replaceBlank(string1, 100);
    printf("%s\n", string1);
    char string2[100] = "We are happy";
    replaceBlank(string2, 100);
    printf("%s\n", string2);
    return 0;
}