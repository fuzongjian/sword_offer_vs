#include <string>
#include <vector>
#include <cstdio>
#include <deque>
using namespace std;
/*
题目：59_01 滑动窗口的最大值
给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。
eg：如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，
那么一共存在6个滑动窗口，他们的最大值分别为{4, 4, 6, 6, 6, 5}
*/
// method
vector<int> maxInScreens(const vector<int>& num, unsigned int size)
{
    vector<int> maxInScreens;
    if(num.size() > size && size >= 1)
    {
        deque<int> index;
        for(unsigned int i = 0; i < size; i ++)
        {
            while(!index.empty() && num[i] >= num[index.back()])
                index.pop_back();
            index.push_back(i);
        }
        for(unsigned int i = size; i < num.size(); i ++)
        {
            maxInScreens.push_back(num[index.front()]);
            while(!index.empty() && num[i] >= num[index.back()])
                index.pop_back();
            if(!index.empty() && index.front() <= (int)(i - size))
                index.pop_front();
            index.push_back(i);
        }
        maxInScreens.push_back(num[index.front()]);
    }
    return maxInScreens;
}
// test
void test(const char* testName, const vector<int>& num, unsigned int size, const vector<int>& expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    vector<int> result = maxInScreens(num, size);
    vector<int>::const_iterator iterResult = result.begin();
    vector<int>::const_iterator iterExpected = expected.begin();
    while(iterResult < result.end() && iterExpected < expected.end())
    {
        if(*iterResult != *iterExpected)
            break;
        ++ iterResult;
        ++ iterExpected;
    }
    if(iterResult == result.end() && iterExpected == expected.end())
        printf("passed.\n");
    else 
        printf("failed.\n");
}
void test1()
{
    int num[] = {2, 3, 4, 2, 6, 2, 5, 1};
    vector<int> vecNumbers(num, num + sizeof(num) / sizeof(int));
    
    int expected[] = {4, 4, 6, 6, 6, 5};
    vector<int> vecExpected(expected, expected + sizeof(expected) / sizeof(int));

    unsigned int size = 3;
    test("test1", vecNumbers, size, vecExpected);
}
int main(int argc, char* argv[])
{
    test1();
    return 0;
}