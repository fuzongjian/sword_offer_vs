#include <string>
#include <cstdio>
/*
题目：57_02 为s的连续正数序列
输入一个正数s，打印出所有和为s的连续正数序列（至少打印两个）.
输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以结果打印出3个连续序列1~5、4~6，7~8
*/
// method
void printContinuousSequence(int small, int big);
void findContinuousSequence(int sum)
{
    if(sum < 3)
        return;
    int small = 1, big = 2, middle = (1 + sum) / 2, curSum = small + big;
    while(small < middle)
    {
        if(curSum == sum)
            printContinuousSequence(small, big);
        while(curSum > sum && small < middle)
        {
            curSum -= small;
            small ++;
            if(curSum == sum)
                printContinuousSequence(small, big);
        }
        big ++;
        curSum += big;
    }
}
void printContinuousSequence(int small, int big)
{
    for(int i = small; i <= big; i ++)
        printf("%d ", i);
    printf("\n");
}
int main(int argc, char* argv[])
{
    findContinuousSequence(9);
    findContinuousSequence(100);
    return 0;
}