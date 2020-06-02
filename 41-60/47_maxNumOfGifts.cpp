#include <algorithm>
#include <iostream>
using namespace std;
/*
题目：47 礼物的最大值
在一个M*N的棋盘的每一格都放一个礼物，每个礼物都有一定的价值（价值大于0）。你可以从棋盘的左上角开始拿礼物，并每次向左或者向下移动一格直到到达棋盘的右下角。
给定一个棋盘及其上面的礼物，请计算你最多能拿到多少价值的礼物？
*/
int getMaxNum_solution1(const int* values, int rows, int cols)
{
    if(values == nullptr || rows <= 0 || cols <= 0)
        return 0;
    int** maxValues = new int*[rows];
    for(int i = 0; i < rows; i ++)
        maxValues[i] = new int[cols];
    for(int i = 0; i < rows; i ++)
    {
        for(int j = 0; j < cols; j ++)
        {
            int left = 0;
            int up = 0;
            if(i > 0)
                up = maxValues[i - 1][j];
            if(j > 0)
                left = maxValues[i][j - 1];
            maxValues[i][j] = std::max(left, up) + values[i * cols + j];
        }
    }
    int maxValue = maxValues[rows - 1][cols - 1];
    for(int i = 0; i < rows; i ++)
        delete[] maxValues[i];
    delete[] maxValues;
    return maxValue;
}
int getMaxNum_solution2(const int* values, int rows, int cols)
{
    if(values == nullptr || rows <= 0 || cols <= 0)
        return 0;
    int* maxValues = new int[cols];
    for(int i = 0; i < rows; i ++)
    {
        for(int j = 0; j < cols; j ++)
        {
            int left = 0, up = 0;
            if(i > 0)
                up = maxValues[j];
            if(j > 0)
                left = maxValues[j - 1];
            maxValues[j] = std::max(left, up) + values[i * cols + j];
        }
    }
    int maxValue = maxValues[cols - 1];
    delete[] maxValues;
    return maxValue;
}
void test(const char* testName, const int* values, int rows, int cols, int expected)
{  
    if(getMaxNum_solution1(values, rows, cols) == expected)
        cout << testName << ": solution1 passed." << endl;
    else 
        cout << testName << ": solution1 failed." << endl;

    if(getMaxNum_solution2(values, rows, cols) == expected)
        cout << testName << ": solution2 passed." << endl;
    else 
        cout << testName << ": solution2 failed." << endl;
}
int main(int argc, char* argv[])
{
    int values1[][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    test("test1", (const int*)values1, 3, 3, 29);

    int values2[][4] = {
        {1, 10, 3, 8},
        {12, 2, 9, 6},
        {5, 7, 4, 11},
        {3, 7, 16, 5}
    };
    test("test2", (const int *)values2, 4, 4, 53);
    return 0;
}