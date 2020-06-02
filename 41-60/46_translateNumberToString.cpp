#include <string>
#include <iostream>
using namespace std;
/*
题目：46 把数字翻译成字符串
给定一个数字，我们按照如下规则把它翻译为字符串：0翻译成"a"，1翻译成"b",....,11翻译成"l",一个数字可能有多个翻译。
eg：12258有5中不同的翻译，它们分别是"bccfi"、"bwfi"、"bczi"、"mcfi"和"mzi",请实现一个函数用来计算一个数字有多少不同的翻译方法。
eg：输入数组{3, 32, 321}，排成最小数字 321323
*/
int getTranslationCount(const string& number);
int getTranslationCount(int number)
{
    if(number < 0)
        return 0;
    string numberInString = to_string(number);
    return getTranslationCount(numberInString);
}
int getTranslationCount(const string& number)
{
    int length = number.length();
    int* counts = new int[length];
    int count = 0;
    for(int i = length - 1; i >= 0; i --)
    {
        count = 0;
        if(i < length - 1)
            count = counts[i + 1];
        else 
            count = 1;
        if(i < length - 1)
        {
            int digit1 = number[i] - '0';
            int digit2 = number[i + 1] - '0';
            int converted = digit1 * 10 + digit2;
            if(converted >= 10 && converted <= 25)
            {
                if(i < length - 2)
                    count += counts[i + 2];
                else 
                    count += 1;
            }
        }
        counts[i] = count;
    }
    count = counts[0];
    delete[] counts;
    return count;
}
void test(const char* testName, int number, int expected)
{
    if(getTranslationCount(number) == expected)
        cout << testName << " passed." << endl;
    else 
        cout << testName << " failed." << endl;
}
int main(int argc, char* argv[])
{
    test("test1", 0, 1);
    test("test2", 10, 2);
    test("test3", 125, 3);
    return 0;
}