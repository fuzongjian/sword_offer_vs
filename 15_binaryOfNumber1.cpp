#include <iostream>
#include <cstdio>
using namespace std;
/*
题目：
请实现一个函数 ，输入一个整数，输出该数二进制中1的个数。
把9表示成二进制1001，有2位1，即输入9，该函数就输出2
*/
int numberOf1_solution1(int n)
{
    int count = 0;
    unsigned int flag = 1;
    while (flag)
    {
        if(n & flag)
        {
            count ++;    
        }
        flag = flag << 1;
    }
    return count;
}
int numberOf1_solution2(int n)
{
    int count = 0;
    while (n)
    {
        ++count;
        n = (n - 1) & n;
    }
    return count;
}

int main(int argc, char* argv[]){
    cout<<numberOf1_solution1(12)<<"---"<<numberOf1_solution2(12)<<endl;
    return 0;
}