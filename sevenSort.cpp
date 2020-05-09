#include <iostream>
using namespace std;

class Solution
{
private:
    /* data */
public:
    static void print(int num[], int count, string out){
        cout<<out;
        for (int i = 0; i < count; i++)
        {
            cout<<num[i]<<" ";
        }
        cout<<endl;
    }
    static void boddle_sort(int num[], int count){
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count - i - 1 ; j++)
            {
                if (num[j] > num[j+1])
                {
                    int temp = num[j];
                    num[j] = num[j+1];
                    num[j+1] = temp;
                }
                
            }
            Solution::print(num, count, "多次循环: ");
        }
    }
    static void select_sort(int num[], int count){
        for (int i = 0; i < count; i++)
        {
            int min = i;
            for (int j = i+1; j < count; j++){
                if (num[j] < num[min])
                {
                    min = j;
                }
            }
            if (i != min)
            {
                int temp = num[i];
                num[i] = num[min];
                num[min] = temp;
            }
            Solution::print(num, count, "多次循环: ");
        }
    }
    static void insert_sort(int num[], int count){
        int i, j;
        for (i = 1; i < count; i++)
        {
            if (num[i] < num[i - 1])
            {
                int temp = num[i];
                for (j = i; j > 0; j--)
                {
                    if (num[j-1] > temp)num[j] = num[j - 1];else break;
                }
                num[j] = temp;
            }
            Solution::print(num, count, "多次循环: ");
        }
    }
    static void binaryInsert_sort(int num[], int count){
        int i, j;
        for (i = 1; i < count; i++)
        {
            if (num[i] < num[i - 1])
            {
                int temp = num[i];
                int left = 0, right = i - 1;
                while (left <= right)
                {
                    int mid = (left + right)/2;
                    if (num[mid] < temp)left = mid + 1;
                    else right = mid - 1;
                }
                for (j = i; j > left; j--)
                {
                    num[j] = num[j - 1];
                }
                num[left] = temp;
            }
            Solution::print(num, count, "多次循环: ");
        }
    }
    static void shell_sort(int num[], int count){

    }
};
int main(){
    // 七种常见的排序
    int array[] = {9,1,2,5,4,6,8,7};
    int count = (int)sizeof(array) / sizeof(*array);
    Solution::print(array, count, "排序之前: ");
    // 冒泡排序
    // Solution::boddle_sort(array, count);
    // 选择排序
    // Solution::select_sort(array, count);
    // 插入排序
    // Solution::insert_sort(array, count);
    // 二分插入排序
    // Solution::binaryInsert_sort(array, count);
    // 希尔排序
    Solution::shell_sort(array, count);

    Solution::print(array, count, "二分插入排序: ");
    return 0;
}
