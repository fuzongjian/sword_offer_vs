#include <string>
#include <iostream>
using namespace std;
/*
题目：48 最长不含重复字符的子字符串
请从字符串中找出一个最长的不包含重复字符串的子字符串，计算该最长子字符串的长度。
假设字符串中只包含从'a'到'z'的字符
*/
// 方法一  蛮力法
bool hasDuplication(const string& str, int position[]);
int maxSubstringOfNoDup_solution1(const string& str)
{
    int longest = 0;
    int* position = new int[26];
    for(int start = 0; start < str.length(); start ++)
    {
        for(int end = start; end < str.length(); end ++)
        {
            int count = end - start + 1;
            const string& substring = str.substr(start, count);
            if(!hasDuplication(substring, position))
            {
                if(count > longest)
                    longest = count;
            }
            else 
                break;
        }
    }
    delete[] position;
    return longest;
}
bool hasDuplication(const string& str, int position[])
{
    for(int i = 0; i < 26; i ++)
        position[i] = -1;
    for(int i = 0; i < str.length(); i ++)
    {
        int indexInPosition = str[i] - 'a';
        if(position[indexInPosition] >= 0)
            return true;
        position[indexInPosition] = indexInPosition;
    }
    return false;
}
// 方法二 动态规划
int maxSubstringOfNoDup_solution2(const string& str)
{
    int curLength = 0, maxLength = 0;
    int* position = new int[26];
    for(int i = 0; i < 26; i ++)
        position[i] = -1;
    for(int i = 0; i < str.length(); i ++)
    {
        int prevIndex = position[str[i] - 'a'];
        if(prevIndex < 0 || i - prevIndex > curLength)
            ++ curLength;
        else 
        {
            if(curLength > maxLength)
                maxLength = curLength;
            curLength = i - prevIndex;
        }
        position[str[i] - 'a'] = i;
    }
    if(curLength > maxLength)
        maxLength = curLength;
    delete[] position;
    return maxLength;
}
void test(const string& input, int expected)
{
    if(maxSubstringOfNoDup_solution1(input) == expected)
        cout << "solution1 passed. with input: " << input << endl;
    else 
        cout << "solution1 failded. with input: " << input << endl;

    if(maxSubstringOfNoDup_solution2(input) == expected)
        cout << "solution2 passed. with input: " << input << endl;
    else 
        cout << "solution2 failded. with input: " << input << endl;
}
int main(int argc, char* argv[])
{
    const string input1 = "abcacfrar";
    test(input1, 4);

    const string input2 = "aaabbbccc";
    test(input2, 2);

    const string input3 = "abcdcbaf";
    test(input3, 5);
    return 0;
}