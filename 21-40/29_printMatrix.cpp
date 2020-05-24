#include <cstdio>
#include <string>
/*
题目：29 顺时针打印矩阵
输入一个矩阵，按照从外到里以顺时针的顺序依次打印出每一个数字
*/
void printMatrixInCircle(int** numbers, int columns, int rows, int start);
void printNumber(int number);
void printMatrixClockWisely(int** numbers, int columns, int rows)
{
    if(numbers == nullptr || columns <= 0 || rows <= 0)
        return;
    int start = 0;
    while(columns > start * 2 && rows > start * 2)
    {
        printMatrixInCircle(numbers, columns, rows, start);
        ++start;
    }
}
void printMatrixInCircle(int** numbers, int columns, int rows, int start)
{
    int endX = columns - 1 - start;
    int endY = rows - 1 - start;
    // 从左到右打印一行
    for(int i = start; i <= endX; i ++)
    {
        int number = numbers[start][i];
        printNumber(number);
    }
    // 从上到下打印一列
    if(start < endY)
    {
        for(int i = start + 1; i <= endY; i ++)
        {
            int number = numbers[i][endX];
            printNumber(number);
        }
    }
    // 从右到左打印一行
    if(start < endX && start < endY)
    {
        for(int i = endX - 1; i >= start; i -- )
        {
            int number = numbers[endY][i];
            printNumber(number);
        }
    }
    // 从下到上打印一行
    if(start < endX && start < endY - 1)
    {
        for(int i = endY - 1; i >= start + 1; i --)
        {
            int number = numbers[i][start];
            printNumber(number);
        }
    }
}
void printNumber(int number)
{
    printf("%d\t", number);
} 
void test(int columns, int rows)
{
    printf("test begin: %d columns, %d rows.\n", columns, rows);
    if(columns < 1 || rows < 1)
        return;
    int** numbers = new int*[rows];
    for(int i = 0; i < rows; i ++){
        numbers[i] = new int[columns];
        for(int j = 0; j < columns; j ++){
            numbers[i][j] = i * columns + j + 1;
        }
    }
    printMatrixClockWisely(numbers, columns, rows);
    printf("\n");
    for(int i = 0; i < rows; i ++)
        delete[] (int*)numbers[i];
    delete[] numbers;
}
int main(int argc, char* argv[])
{
    test(2, 2);
    test(4, 4);
    return 0;
}