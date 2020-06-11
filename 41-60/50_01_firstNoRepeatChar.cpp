#include <string>
#include <cstdio>
/*
题目：50_01 字符串中第一个只出现一次的字符
在字符串中找出第一个只出现一次的字符。
eg：输入"abaccdeff"，则输出“b”
*/
// method
char firstNoRepeatChar(const char* pString)
{
    if(pString == nullptr)
        return '\0';

    const int tableSize = 256;
    unsigned int hashTable[tableSize];
    for(unsigned int i = 0; i < tableSize; i ++)
        hashTable[i] = 0;

    const char* pHashKey = pString;
    while(*(pHashKey) != '\0')
        hashTable[*(pHashKey++)]++;

    pHashKey = pString;
    while(*pHashKey != '\0')
    {
        if(hashTable[*pHashKey] == 1)
            return *pHashKey;
        pHashKey++;
    }
    return '\0';
}
// test
void test(const char* pString, char expected)
{
    if(firstNoRepeatChar(pString) == expected)
        printf("%s test passed.\n", pString);
    else 
        printf("%s test failed.\n", pString);
}
int main(int argc, char* argv[])
{
    test("qwertyui", 'q');

    test("adfadfc", 'c');
    return 0;
}