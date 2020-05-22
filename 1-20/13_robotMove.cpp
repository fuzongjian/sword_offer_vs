#include <iostream>
#include <cstdio>
using namespace std;
/*
题目：
地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它每一次可以向左、右、上、下移动一格，
但不能进入行坐标和列坐标的数位之和
大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
*/
int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited);
bool check(int threshold, int rows, int cols, int row, int col, bool* visited);
int getDigitSum(int number);
int movingCount(int threshold, int rows, int cols){
    if (threshold < 0 || rows <= 0 || cols <= 0)    
    {
        return 0;
    }
    bool *visited = new bool[rows * cols];
    for (int i = 0; i < rows * cols; i++)
    {
        visited[i] = false;
    }
    int count = movingCountCore(threshold, rows, cols, 0, 0, visited);
    delete[] visited;
    return count;
}
int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited){
    int count = 0;
    if (check(threshold, rows, cols, row, col, visited))
    {
        visited[row * cols + col] = true;
        count = 1 + movingCountCore(threshold, rows, cols, row - 1, col, visited)
                  + movingCountCore(threshold, rows, cols, row, col - 1, visited)
                  + movingCountCore(threshold, rows, cols, row + 1, col, visited)
                  + movingCountCore(threshold, rows, cols, row, col + 1, visited);
    }
    return count;
}
bool check(int threshold, int rows, int cols, int row, int col, bool* visited){
    if (row >= 0 && row < rows && col >= 0 && col < cols && getDigitSum(row) + getDigitSum(col) <= threshold && !visited[row * cols + col])
    {
        return true;
    }
    return false;
}
int getDigitSum(int number){
    int sum = 0;
    while (number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}
int main(int argc, char* argv[]){
    bool status1 = movingCount(5,10,10) == 21;// 多行多列
    bool status2 = movingCount(10, 1, 100) == 29;// 一行,只能到达部分方格
    bool status3 = movingCount(15,10, 1) == 10; //一行,能到达所有方格
    cout<<status1<<"---"<<status2<<"---"<<status3<<endl;
    return 0;
}