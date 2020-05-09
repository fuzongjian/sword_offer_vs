#include <iostream>
#include <math.h>
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
        int shellNum = 2;
        int gap = round(count / shellNum);
        while (gap > 0)
        {
            for (int i = gap; i < count; i++)
            {
                int temp = num[i];
                int j = i;
                while (j >= gap && num[j - gap] > temp)
                {
                    num[j] = num[j - gap];
                    j = j - gap;
                }
                num[j] = temp;
            }
            gap = round(gap/shellNum);
            Solution::print(num, count, "多次循环: ");
        }
    }
    static void fast_sort(int num[], int left, int right){
        if(left > right)return;
        int i, j, base, temp;
        i = left, j = right;
        base = num[left]; // 取最左边的数为基准数
        while (i < j)   
        {
            while (num[j] >= base && i < j)j--;
            while (num[i] <= base && i < j)i ++;
            if (i < j)  
            {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }
        num[left] = num[i];
        num[i] = base;
        Solution::print(num, 8, "多次循环: ");
        fast_sort(num, left, i - 1);// 递归左边
        fast_sort(num, i + 1,right);// 递归右边
    }
    static void heap_sort(int num[], int count){

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
    // Solution::shell_sort(array, count);
    // 快速排序
    // Solution::fast_sort(array, 0, count-1);
    Solution::heap_sort(array, count);

    Solution::print(array, count, "快速排序: ");
    return 0;
}
