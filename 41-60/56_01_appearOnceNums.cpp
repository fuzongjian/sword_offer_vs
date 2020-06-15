#include <string>
#include <cstdio>
/*
题目：56_01 数组中只穿一次的两个数字
一个整型数组里除了两个数字之外，其他的数字都出现了两次。
请写程序找出这两个只出现一次的数字，要求时间复杂度为O(n)，空间复杂度为O(1)
*/
unsigned int findFirstBitIs1(int num);
bool isBit1(int num, unsigned int indexBit);
void findNumsAppearOnece(int data[], int length, int* num1, int* num2)
{
    if(data == nullptr || length < 2)
        return;
    int resultExclusiveOR = 0;
    for(int i = 0; i < length; i ++)
        resultExclusiveOR ^= data[i];

    unsigned int indexOf1 = findFirstBitIs1(resultExclusiveOR);
    *num1 = *num2 = 0;
    for(int j = 0; j < length; j ++)
    {
        if(isBit1(data[j], indexOf1))
            *num1 ^= data[j];
        else 
            *num2 ^= data[j];
    }
}
// 找到num从右边数起第一个是1的位
unsigned int findFirstBitIs1(int num)
{
    int indexBit = 0;
    while(((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
    {
        num = num >> 1;
        ++indexBit;
    }
    return indexBit;
}
bool isBit1(int num, unsigned int indexBit)
{
    num = num >> indexBit;
    return (num & 1);
}
int main(int argc, char* argv[])
{
    int data1[] = {2, 4, 3, 6, 3, 2, 5, 5};
    int result1, result2;
    findNumsAppearOnece(data1, sizeof(data1) / sizeof(int), &result1, &result2);
    // 返回的结果4和6顺序不一定
    printf("%d %d", result1 == 6, result2 == 4);

    return 0;
}