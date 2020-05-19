#include <iostream>
#include <cmath>
using namespace std;
/*
题目：
给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘积是多少？
例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到最大的乘积18。
*/
// 动态规划
int maxProductAfterCutting_solution1(int length){
    if(length < 2) return 0;
    if(length == 2) return 1;
    if(length == 3) return 2;
    int* products = new int[length + 1];
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;
    int max = 0;
    for (int i = 4; i <= length; i++)
    {
        max = 0;
        for (int j = 1; j <= i / 2; j++)
        {
            int product = products[j] * products[i - j];
            if (max < product)
            {
                max = product;
            }
            products[i] = max;
        }
    }
    max = products[length];
    delete[] products;
    return max;
}
// 贪心算法
int maxProductAfterCutting_solution2(int length){
    if(length < 2) return 0;
    if(length == 2) return 1;
    if(length == 3) return 2;
    // 尽可能多的减去长度为3的绳子段
    int itemsOf3 = length / 3;
    // 当绳子最后剩下的长度为4的时候，不能再减去长度为3的绳子段
    // 此时更好的方法是把绳子剪成长度为2的两段， 因为 2*2 > 1 * 3
    if (length - itemsOf3 * 3 == 1)
    {
        itemsOf3 -= 1;
    }
    int itemOf2 = (length - itemsOf3 * 3) / 2;
    return (int)(pow(3, itemsOf3)) * (int)(pow(2, itemOf2));
}
int main(int argc, char* argv[]){

    int length = 10;
    bool status1 = maxProductAfterCutting_solution1(length) == 36;
    bool status2 = maxProductAfterCutting_solution2(length) == 36;
    cout<<status1<<"---"<<status2<<endl;
    return 0;
}