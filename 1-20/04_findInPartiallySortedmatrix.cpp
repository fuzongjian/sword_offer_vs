#include <cstdio>
#include <string>
/* 面试题4：二维数组中的查找
在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/ 
// method
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
}
int main(int argc, char* argv[])
{
    test1();
    return 0;
}