#include <iostream>
#include <cstdio>
using namespace std;
int MinInOrder(int* numbers, int index1, int index2);
int Min(int* numbers, int length){
    if (numbers == nullptr || length == 0)
    {
        return 0;
    }
    int index1 = 0, index2 = length - 1, indexMid = index1;
    while (numbers[index1] >= numbers[index2])
    {
        if (index2 - index1 == 1)
        {
            indexMid = index2;
            break;
        }
        indexMid = (index1 + index2) / 2;
        if (numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1]) 
        {
            return MinInOrder(numbers, index1, index2);
        }
        if (numbers[indexMid] >= numbers[index1])   
        {
            index1 = indexMid;
        }else if (numbers[indexMid] <= numbers[index2])
        {
            index2 = indexMid;
        }        
    }
    return numbers[indexMid];
}
int MinInOrder(int* numbers, int index1, int index2){
    int result = numbers[index1];
    for (int i = index1 + 1; i <= index2; ++i)
    {
        if (result > numbers[i])
        {
            result = numbers[i];
        }
        
    }
    return result;
}
int main(int argc, char* argv[]){
    int array1[] = {0};
    int result = Min(array1, sizeof(array1) / sizeof(int));
    int status = result == 0;
    cout <<status<<endl;
    return 0;
}