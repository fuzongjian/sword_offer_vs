#include <cstdio>
#include <string>
/*
题目：57_01 和为s的两个数字
输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得他们的和正好是s。如果多对数字的和等于s，输出任意一对即可
*/
// method
bool findNumbersWithSum(int data[], int length, int sum, int* num1, int* num2)
{
    bool found = false;
    if(length < 1 || num1 == nullptr || num2 == nullptr)
        return found;
    int ahead = length - 1, behind = 0;
    while(ahead > behind)
    {
        long long curSum = data[ahead] + data[behind];
        if(curSum == sum)
        {
            *num1 = data[behind];
            *num2 = data[ahead];
            found = true;
            break;
        }
        else if(curSum > sum)
            ahead --;
        else 
            behind ++;
    }
    return found;
}
int main(int argc, char* argv[])
{
    int data[] = {1, 2, 4, 7, 11, 15};
    int num1, num2;
    bool status = findNumbersWithSum(data, sizeof(data) / sizeof(int), 15, &num1, &num2);
    if(status)
        printf("passed. num1 === %d, num2 === %d", num1, num2);
    else 
        printf("failed.\n");
    return 0;
}