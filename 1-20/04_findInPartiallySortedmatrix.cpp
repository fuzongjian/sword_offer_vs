#include <cstdio>
#include <string>
/* 题目4：二维数组中的查找1
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/ 
// method
// 线性查找
bool find(int* matrix, int rows, int columns, int number)
{
    bool found = false;
    if(matrix != nullptr && rows > 0 && columns > 0)
    {
        int row = 0;
        int column = columns - 1;
        while(row < rows && column >= 0)
        {
            if(matrix[row * columns + column] == number)
            {
                found = true;
                break;
            }
            else if(matrix[row * columns + column] > number)
                --column;
            else 
                ++ row;
        }
    }
    return found;
}
bool binary(int* arr, int left, int right, int target);
// 二分法查找 其实就是针对每一行进行二分查找
bool findInBinary(int matrix[][4], int rows, int columns, int number)
{
    int array = matrix[0][0];
    // 每一行为单位进行比较
    for(int i = 0; i < rows; i ++)
    {   //&matrix[i][0] 每一行的首地址     
        if(binary(&matrix[i][0], 0, columns, number))
        {
            printf("binary search passed.\n");
            return true;
        }
    }
    return false;
}
bool binary(int* arr, int left, int right, int target)
{
    if(left >right) return false;
    int mid = right - (right - left) / 2;
    if(arr[mid] == target)
        return true;
    else if(arr[mid] > target)
        return binary(arr, left, mid - 1, target);
    else 
        return binary(arr, mid + 1, right, target);
}

// test
void test(const char * testName, int* matrix, int rows, int columns, int number, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    bool result = find(matrix, rows, columns, number);
    if(result == expected)
        printf("passed.\n");
    else 
        printf("failed.\n");
}
void test1()
{
    int matrix[][4] = {
        {1, 2, 8, 9},
        {2, 4, 9, 12},
        {4, 7, 10, 13},
        {6, 8, 11, 15}
    };
    test("test1", (int*)matrix, 4, 4, 7, true);

    findInBinary(matrix, 4, 4, 7);
}

int main(int argc, char* argv[])
{
    test1();
    
    return 0;
}