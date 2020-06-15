#include <cstdio>
#include <string>
/*
题目：56_02 数组中唯一出现一次的数字
在一个数组中处理一个数字只出现了一次，其他数字都出现了三次。
请找出那个出现一次的数字
*/
// method
int findNumberAppearOnce(int numbers[], int  length)
{
    if(numbers == nullptr || length <= 0)
        return 0;
    int bitSum[32] = {0};
    for(int i = 0; i < length; i ++)
    {
        int bitMask = 1;
        for(int j = 31; j >= 0; j --)
        {
            int bit = numbers[i] & bitMask;
            if(bit != 0)
                bitSum[j] += 1;
            bitMask = bitMask << 1;
        }
    }
    int result = 0;
    for(int i = 0; i < 32; i ++)
    {
        result = result << 1;
        result += bitSum[i] % 3;
    }
    return result;
}
int main(int argc, char* argv[])
{
    int numbers1[] = {1, 1, 2, 2, 2, 1, 3};
    if(findNumberAppearOnce(numbers1, sizeof(numbers1) / sizeof(int)) == 3)
        printf("passed.\n");
    else 
        printf("failed.\n");
    return 0;
}