#include <cstdio>
#include <vector>
#include <limits>
#include <string>
using namespace std;
/*
题目：50_02 字符流中第一个只出现一次的字符
实现一个函数用来找出字符流中第一个只出现一次的字符。
eg：当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是'g'；
当从该字符流中读出前六个字符"google"时，第一个只出现一次的字符是'l'
*/
// define
class CharStatistics
{
private:
    int occurrence[256];
    int index;
public:
    CharStatistics() : index(0)
    {
        for(int i = 0; i < 256; i ++)
            occurrence[i] = -1;
    }
    void insert(char ch)
    {
        if(occurrence[ch] == -1)
            occurrence[ch] = index;
        else if(occurrence[ch] >= 0)
            occurrence[ch] = -2;
        index ++;
    }
    char firstAppearOnce()
    {
        char ch = '\0';
        int minIndex = numeric_limits<int>::max();
        for(int i = 0; i < 256; i ++)
        {
            if(occurrence[i] >= 0 && occurrence[i] < minIndex)
            {
                ch = (char)i;
                minIndex = occurrence[i];
            }
        }
        return ch;
    }
};
// test
void test(const char* testName, CharStatistics chars, char expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    if(chars.firstAppearOnce() == expected)
        printf("passed.\n");
    else 
        printf("failed.\n");
}
int main(int argc, char* argv[])
{
    CharStatistics chars;
    test("test1", chars, '\0');

    chars.insert('g');
    test("test2", chars, 'g');

    chars.insert('o');
    test("test2", chars, 'g');

    chars.insert('o');
    test("test2", chars, 'g');

    chars.insert('g');
    test("test2", chars, '\0');
    return 0;
}