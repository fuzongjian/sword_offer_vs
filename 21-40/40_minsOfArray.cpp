#include <cstdio>
#include <set>
#include <vector>
#include <iostream>
#include <functional>
using namespace std;
/*
题目：40 最小的k个数
输入n个整数，找出其中最小的k个数。
eg：输入4、5、1、6、2、7、3、8，这个8个数中最小的4个数字是1、2、3、4.
*/
struct Array
{
    static int randomInRange(int min, int max)
    {
        int random = rand() % (max - min + 1) + min;
        return random;
    }
    static void swap(int* num1, int* num2)
    {
        int temp = *num1;
        *num1 = *num2;
        *num2 = temp;
    }
    static int partition(int data[], int length, int start, int end)
    {
        if(data == nullptr || length <= 0 || start < 0 || end >= length)
        {
            printf("Invalid Parameters");
            return 0;
        }
        int index = randomInRange(start, end);
        swap(&data[index], &data[end]);
        int small = start - 1;
        for(index = start; index < end; ++index)
        {
            if(data[index] < data[end])
            {
                ++ small;
                if(small != index)
                    swap(&data[index], &data[small]);
            }
        }
        ++ small;
        swap(&data[small], &data[end]);
        return small;
    }
};
// solutin one
void getLeastNumbers_solution1(int* input, int n, int* output, int k)
{
    if(input == nullptr || output == nullptr || k > n || n <= 0 || k <= 0)
        return;
    int start = 0, end = n - 1, index = Array::partition(input, n, start, end);
    while(index != k - 1)
    {
        if(index > k - 1)
        {
            end = index - 1;
            index = Array::partition(input, n, start, end);
        }
        else 
        {
            start = index + 1;
            index = Array::partition(input, n, start, end);
        }
    }
    for(int i = 0; i < k; i ++)
        output[i] = input[i];
}
// solution two
typedef multiset<int, std::greater<int> >       intSet;
typedef multiset<int, std::greater<int> >::iterator setIterator;
void getLeastNumbers_solution2(const vector<int>& data, intSet& leastNumbers, int k)
{
    leastNumbers.clear();
    if(k < 1 || data.size() < k)
        return;
    vector<int>::const_iterator iter = data.begin();
    for(; iter != data.end(); iter++)
    {
        if((leastNumbers.size()) < k)
            leastNumbers.insert(*iter);
        else 
        {
            setIterator iterGreatest = leastNumbers.begin();
            if(*iter < *(leastNumbers.begin()))
            {
                leastNumbers.erase(iterGreatest);
                leastNumbers.insert(*iter);
            }
        }
    } 
}
//  测试
void test(const char* testName, int* data, int n, int* expectedResult, int k)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);
    vector<int> vectorData;
    for(int i = 0; i < n; i ++)
        vectorData.push_back(data[i]);
    if(expectedResult == nullptr)
        printf("The input is invalid, we don't expect any result.\n");
    else
    {
        printf("Expected result: \n");
        for(int i = 0; i < k; i ++)
            printf("%d\t", expectedResult[i]);
        printf("\n");
    }
    printf("Result for solution1: \n");
    int* output = new int[k];
    getLeastNumbers_solution1(data, n, output, k);
    if(expectedResult != nullptr)
    {
        for(int i = 0; i < k; i ++)
            printf("%d\t", output[i]);
        printf("\n");
    }
    delete[] output;
    printf("Result for solution2: \n");
    intSet leastNumbers;
    getLeastNumbers_solution2(vectorData, leastNumbers, k);
    printf("The actual output numbers are: \n");
    for(setIterator iter = leastNumbers.begin(); iter != leastNumbers.end(); iter ++)
        printf("%d\t", *iter);
    printf("\n\n");
}
int main(int argc, char* argv[])
{
    int data[] = {4, 5, 1, 6, 2, 7, 3, 8};
    int expected[] = {1, 2, 3, 4};
    test("test1", data, sizeof(data) / sizeof(int), expected, sizeof(expected) / sizeof(int));
    return 0;
}