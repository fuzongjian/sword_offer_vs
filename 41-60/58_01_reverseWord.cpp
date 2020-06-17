#include <string>
#include <cstdio>
/*
题目：58_01 反转单词顺序
输入一个英文句子，反转句子中单词的顺序，但单词字符的顺序不变。
为简单起见，标点符号和普通字母一样处理，例如输入字符串"I am a student."
则输出"student. a am I"
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
char* reverseSentence(char* pData)
{
    if(pData == nullptr)
        return nullptr;
    char *pBegin = pData;
    char *pEnd = pData;
    while(*pEnd !='\0')
        pEnd ++;
    pEnd --;
    // 反转整个句子
    reverse(pBegin, pEnd);
    // 反转句子中的每个单词
    pBegin = pEnd = pData;
    while(*pBegin != '\0')
    {
        if(*pBegin == ' ')
        {
            pBegin ++;
            pEnd ++;
        }
        else if(*pEnd == ' ' || *pEnd == '\0')
        {
            reverse(pBegin, --pEnd);
            pBegin = ++pEnd;
        }
        else 
            pEnd ++;
    }
    return pData;
}
int main(int argc, char* argv[])
{
    char input1[] = "I am a student.";
    char* result = reverseSentence(input1);
    if(strcmp(input1, result) == 0)
        printf("passed.\n");
    else 
        printf("failed.");

    return 0;
}