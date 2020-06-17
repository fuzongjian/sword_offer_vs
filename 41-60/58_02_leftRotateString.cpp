#include <string>
#include <cstdio>
/*
题目：58_02 左选择字符串
字符串的坐旋转操作是把字符串前面的若干字符转移到字符串的尾部。
定义一个函数实现字符串坐旋转操作的功能；
eg：输入字符串"abcdefg"和数字2，该函数将返回左旋转2位得到"cdefgab"
*/
// method
void reverse(char *pBegin, char *pEnd)
{
    if(pBegin == nullptr || pEnd == nullptr)
        return;
    while(pBegin < pEnd)
    {
        char temp = *pBegin;
        *pBegin = *pEnd;
        *pEnd = temp;
        pBegin ++;
        pEnd --;
    }
}
char* leftRotateString(char* pStr, int n)
{
    if(pStr != nullptr)
    {
        int nLength = static_cast<int>(strlen(pStr));
        if(nLength > 0 && n > 0 && n < nLength)
        {
            char* pFirstStart = pStr;
            char* pFirstEnd = pStr + n - 1;
            char* pSecondStart = pStr + n;
            char* pSecondEnd = pStr + nLength - 1;
            // 翻转字符串前面n个字符
            reverse(pFirstStart, pFirstEnd);
            // 翻转字符串的后面部分
            reverse(pSecondStart, pSecondEnd);
            // 翻转整个字符串
            reverse(pFirstStart, pSecondEnd);
        }
    }
    return pStr;
}
int main(int argc, char* argv[])
{
    char input[] = "abcdefg";
    char expected[] = "cdefgab";
    char *result = leftRotateString(input, 2);
    if(strcmp(result, expected) == 0)
        printf("passed.\n");
    else   
        printf("failed.\n");
    return 0;
}