#include <string>
#include <cstdio>
#include <vector>
#include <math.h>
using namespace std;
//  需要重新修改
/*
题目：66 构建乘积数组
给定一个数组A[0,1 ,..., n-1]，请构建一个数组B[0,1,...,n-1]，其中B中的元素B[i] = A[0] x A[1] x ...x A[i - 1]xA[i+1]x...xA[n-1]。不能使用除法
*/
static void buildProductionArray(const vector<double>& input, vector<double>& output)
{
    int length1 = input.size(), length2 = output.size();
    if(length1 == length2 && length2 > 1)
    {
        output[0] = 1;
        for(int i = 0; i < length1; i ++)
            output[i] = output[i - 1] * input[i - 1];
        double temp = 1;
        for(int i = length1 - 2; i >= 0; i --)
        {
            temp *= input[i + 1];
            output[i] *= temp;
        }
    }
}
// test
static bool equalArrays(const vector<double>& input, const vector<double>& output)
{
    int length1 = input.size(), length2 = input.size();
    if(length1 != length2)
        return false;
    for(int i = 0; i < length1; i ++)
    {
        if(abs(input[i] - output[i]) > 0.0000001)
            return false;
    }
    return true;
}
static void test(const char* testName, const vector<double>& input, vector<double>& output, const vector<double>& expected)
{
    printf("%s begins: ", testName);
    buildProductionArray(input, output);
    if(equalArrays(output, expected))
        printf("passed.\n");
    else 
        printf("failed.\n");
}
static void test1(){
    double input[] = {1, 2, 3, 4, 5};
    double output[] = {0, 0, 0, 0, 0};
    double expected[] = {120, 60, 40, 30, 24};
    test("test1", vector<double>(input, input + sizeof(input)/sizeof(double)), vector<double>(output, output + sizeof(output)/sizeof(double)), 
    vector<double>(expected, expected + sizeof(expected)/sizeof(double)));
}
int main(int argc, char* argv[])
{
    test1();
    return 0;
}