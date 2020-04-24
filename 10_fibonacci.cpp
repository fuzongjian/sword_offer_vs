#include <iostream>
using namespace std;
class Solution
{
public:
    static int solution1(int n){
        if (n == 0) return 0;
        if (n == 1) return 1;
        return solution1(n-1) + solution1(n-2);
    }
    static int solution2(int n){
        if (n == 0) return 0;
        if (n == 1) return 1;
        int n1 = 0, n2 = 1, result = 0;
        for (int i = 2; i <= n; i++)
        {
            result = n1 + n2;
            n1 = n2;
            n2 = result;
        }
        return result;
    }
};
int main(){
    cout << Solution::solution1(10) << endl;
    cout << Solution::solution2(10) << endl;
    return 0;
}