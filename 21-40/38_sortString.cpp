#include <string>
#include <cstdio>
/*
题目：38 字符串的排列
输入一个字符串，打印出该字符串中字符的所有排列。
eg：输入字符串abc，则输出abc、acb、bac、bca、cab、cba
*/
void premutation(char* pStr, char* pBegin);
void premutation(char* pStr)
{
    if(pStr == nullptr)
        return;
    premutation(pStr, pStr);
}
void premutation(char* pStr, char* pBegin)
{
    if(*pBegin == '\0')
        printf("%s\n", pStr);
    else 
    {
        for(char* pCh = pBegin; *pCh != '\0'; ++pCh)
        {
            char temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
            premutation(pStr, pBegin + 1);
            temp = *pCh;
            *pCh = *pBegin;
            *pBegin = temp;
        }

    }
}
void test(char* pStr)
{
    if(pStr == nullptr)
        printf("test for nullptr begins: \n");
    else 
        printf("test for %s begins:\n", pStr);
    premutation(pStr);
}
int main(int argc, char* argv[])
{
    char string1[] = "abcd";
    test(string1);
    return 0;
}