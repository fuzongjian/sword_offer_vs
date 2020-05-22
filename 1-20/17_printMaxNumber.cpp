#include <cstdio>
#include <memory>
/*
题目：打印1到最大的n位数
输入数字n，按顺序打印出从1到最大的n位十进制数，
如输入3，则从1打印到最大的三位数999
*/
void printNumber(char* number);
bool increment(char* number);
void print1ToMaxOfNdigitsRecursively(char* number, int length, int index);
void printSolution_1(int n)
{
    if (n <= 0)
        return;
    char *number = new char[n + 1];
    memset(number, '0', n);
    number[n] = '\0';
    while (!increment(number))
    {
        printNumber(number);
    }
    delete[] number;
}
// 字符串number表示一个数字，在number上增加1，如果做法溢出，则返回true，否则为false
bool increment(char *number)
{
    bool isOverflow = false;
    int nTakeOver = 0;
    int nLength = strlen(number);
    for (int i = nLength - 1; i >= 0; i--)
    {
        int nSum = number[i] - '0' + nTakeOver;
        if (i == nLength - 1)
            nSum ++;
        if (nSum >= 10)
        {
            if (i == 0)
                isOverflow = true;
            else
            {
                nSum -= 10;
                nTakeOver = 1;
                number[i] = '0' + nSum;
            }
            
        }
        else
        {
            number[i] = '0' + nSum;
            break;
        }
    }
    return isOverflow;
}
void printSolution_2(int n){
    if (n <= 0)
        return;

    char* number = new char[n + 1];
    number[n] = '\0';

    for (int i = 0; i < 10; i++)
    {
        number[0] = i + '0';
        print1ToMaxOfNdigitsRecursively(number, n, 0);
    }
    delete[] number;
}
void print1ToMaxOfNdigitsRecursively(char* number, int length, int index)
{
    if (index == length - 1)
    {
        printNumber(number);
        return;
    }
    for (int i = 0; i < 10; i++)
    {
        number[index + 1] = i + '0';
        print1ToMaxOfNdigitsRecursively(number, length, index + 1);
    }
    
    
}
// 公共函数
// 字符串number表示一个数字，数字有若干个0开头；打印出这个数字，并忽略开头的0
void printNumber(char* number){
    bool isBegining0 = true;
    int nLength = strlen(number);

    for (int i = 0; i < nLength; i++)
    {
        if (isBegining0 && number[i] != '0')
            isBegining0 = false;
        if (!isBegining0)
        {
            printf("%c", number[i]);
        }
    }
    printf("\t");
}
int main(int argc, char* argv[]){
    int n = 2;
    printSolution_1(n);
    printSolution_2(n);
    return 0;
}