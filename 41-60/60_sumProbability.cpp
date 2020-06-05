#include <cstdio>
#include <math.h>
/*
题目：60 n个骰子的点数
把n个骰子扔在地上，所有骰子朝上一面的点数和为s。
输入n，打印出s的所有可能的出现的概率
*/
int g_maxValue = 6;
void probability(int number, int* nProbabilities);
void probability(int original, int current, int sum, int* nProbabilities);

void printProbility_solution1(int number)
{
    if(number < 1)
        return;
    int maxSum = number * g_maxValue;
    int* pProbabilities = new int[maxSum - number + 1];
    for(int i = number; i <= maxSum; i ++)
        pProbabilities[i - number] = 0;
    probability(number, pProbabilities);
    int total = pow((double)g_maxValue, number);
    for(int i = 0; i <= maxSum; i ++)
    {
        double ratio = (double)pProbabilities[i - number] / total;
        printf("%d: %e\n", i, ratio);
    }
    delete[] pProbabilities;
}
void probability(int number, int* nProbabilities)
{
    for(int i = 1; i <= g_maxValue; i ++)
        probability(number, number, i, nProbabilities);
}
void probability(int original, int current, int sum, int* nProbabilities)
{
    if(current == 1)
        nProbabilities[sum - original]++;
    else
        for(int i = 1; i <= g_maxValue; i ++)
            probability(original, current - 1, i + sum, nProbabilities);
}
void printProbility_solution2(int number)
{
    if(number < 1)
        return;
    int* pProbilities[2];
    pProbilities[0] = new int[g_maxValue * number + 1];
    pProbilities[1] = new int[g_maxValue * number + 1];
    for(int i = 0; i < g_maxValue * number + 1; i ++)
    {
        pProbilities[0][i] = 0;
        pProbilities[1][i] = 0;
    }
    int flag = 0;
    for(int i = 0; i <= g_maxValue; i ++)
        pProbilities[flag][i] = 1;
    for(int k = 2; k <= number; k ++)
    {
        for(int i = 0; i < k; i ++)
            pProbilities[1 - flag][i] = 0;
        for(int i = k; i <= g_maxValue * k; i ++)
        {
            pProbilities[1 - flag][i] = 0;
            for(int j = 1; j <= i && j <= g_maxValue; j ++)
                pProbilities[1 - flag][i] += pProbilities[flag][i - j];
        }
        flag = 1 - flag;
    }
    double total = pow((double)g_maxValue, number);
    for(int i = number; i <= g_maxValue * number; i ++)
    {
        double ratio = (double)pProbilities[flag][i] / total;
        printf("%d: %e\n", i, ratio);
    }
    delete[] pProbilities[0];
    delete[] pProbilities[1];
}
void test(int n)
{
    printf("test for %d begins:\n", n);

    printf("test for solution1\n");
    printProbility_solution1(n);
    printf("test for solution2\n");
    printProbility_solution2(n);
    printf("\n");
}
int main(int argc, char* argv[])
{
    // test(1);
    test(2);
    // test(3);
    return 0;
}