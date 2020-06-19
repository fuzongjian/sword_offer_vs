#include <cstdio>
#include <string>
/* 题目3：找出数组中重复的数字
在一个长度为n的数组里的所有数组都在0到n-1范围内，数组中某些数字时重复的，但不知道有几个数字重复，
也不知道每个数字重复了几次，请找出数组中任意一个重复的数字。
eg：输入长度为7的数字{2, 3, 1, 0, 2, 5, 3}，即对应的输出是重复数字2或者3
*/ 
// method
bool duplicate(int numbers[], int length, int* duplication)
{
    if(numbers == nullptr || length <= 0)
        return false;
    
    for(int i = 0; i < length; i ++)
    {
        while(numbers[i] != i)
        {
            if(numbers[i] == numbers[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }
            // 交换numbers[i]和numbers[numbers[i]]
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;
        }
    }
    return false;
}
// test
bool contains(int array[], int length, int number)
{
    for(int i = 0; i < length; i ++)
        if(array[i] == number)
            return true;
    return false;
}

int main(int argc, char* argv[])
{
    int numbers1[] = {2, 1, 3, 1, 4}, duplications[] = {1};
    int duplication;
    bool status = duplicate(numbers1, sizeof(numbers1) / sizeof(int), &duplication);
    if((status == true) && contains(duplications, sizeof(duplications) / sizeof(int), duplication))
        printf("test1 passed.\n");
    else
        printf("test1 failed.\n");

    int numbers2[] = {2, 4, 2, 1, 4}, duplications2[] = {2, 4};
    bool status2 = duplicate(numbers2, sizeof(numbers2) / sizeof(int), &duplication);
    if((status == true) && contains(duplications2, sizeof(duplications2) / sizeof(int), duplication))
          printf("test2 passed.\n");
    else
        printf("test2 failed.\n");

}