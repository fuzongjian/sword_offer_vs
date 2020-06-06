#include <cstdio>
#include <string>
#include <list>
using namespace std;
/*
题目：62 圆圈中最后剩下的数字
0,1,...n-1这个n个数字排成一个圆圈，从数字0开始每次从这个圆圈里删除第m个数字，求这个圆圈里剩下的最后的数字
*/
int lastRemain_solution1(unsigned int n, unsigned int m)
{
    if(n < 1 || m < 1)
        return -1;
    unsigned int i = 0;
    list<int> numbers;
    for(i = 0; i < n; i ++)
        numbers.push_back(i);
    list<int>::iterator current = numbers.begin();
    while(numbers.size())
    {
        for(int i = 1; i < m; i ++)
        {
            current ++;
            if(current == numbers.end())
                current = numbers.begin();
        }
        list<int>::iterator next = ++ current;
        if(next == numbers.end())
            next = numbers.begin();
        -- current;
        numbers.erase(current);
        current = next;
    }
    return *(current);
}
int lastRemain_solution2(unsigned int n, unsigned int m)
{
    if(n < 1 || m < 1)
        return -1;
    int last = 0;
    for(int i = 2; i <= n; i ++)
        last = (last + m) % i;
    return last;
}
// test 
void test(const char* testName, unsigned int n, unsigned int m, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    if(lastRemain_solution1(n, m) == expected)
        printf("Solution1 passed. ");
    else 
        printf("Solution1 failed. ");

    if(lastRemain_solution2(n, m) == expected)
        printf("Solution2 passed.\n");
    else 
        printf("Solution2 failed.\n");
}
int main(int argc, char* argv[])
{
    test("test1", 5, 3, 3);
    test("test2", 5, 2, 2);
    return 0;
}