#include <iostream>
#include <cstdio>
#include <string>
/*
题目：正则表达式匹配
请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次。
在本例中，匹配是指字符串的所有字符匹配模式。
*/
bool matchCore(const char* str, const char* pattern);
bool match(const char* str, const char* pattern)
{
    if (str == nullptr || pattern == nullptr)
        return false;
    return matchCore(str, pattern);
}
bool matchCore(const char* str, const char* pattern){
    if (*str == '\0' && *pattern == '\0')
        return true;
    if (*str != '\0' && *pattern == '\0')
        return false;
    if(*(pattern + 1) == '*')
    {
        if(*pattern == *str || (*pattern == '.' && *str != '\0'))
            // 进入有限状态机的下一个状态                   继续留在有限状态机的当前状态      略过一个'*' 
            return matchCore(str + 1, pattern + 2) || matchCore(str + 1, pattern) || matchCore(str, pattern + 2);
        else 
            return matchCore(str, pattern + 2);
    }
    if(*str == *pattern || (*pattern == '.' && *str != '\0'))
        return matchCore(str + 1, pattern + 1);
    return false;
}
int main(int argc, char* argv[]){
    printf("%d \n",match("a", "ab*"));
    printf("%d \n",match("a", "ab*a"));
    printf("%d \n",match("aa", "aa"));
    printf("%d \n",match("aaa", "aa*"));
    printf("%d \n",match("bcbbabab", ".*a*a"));
    return 0;
}