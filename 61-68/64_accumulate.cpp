#include <string>
#include <cstdio>
/*
题目：64 求1+2+...+n
求1+2+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句(A ? b : c)
*/
// method one
class Temp
{
private:
    static unsigned int N;
    static unsigned int Sum;
public:
    Temp() {++ N; Sum += N;}
    static void reset(){N = 0; Sum = 0;}
    static unsigned int getSum(){ return Sum; }
};
unsigned int Temp::N = 0;
unsigned int Temp::Sum = 0;
unsigned int sum_solution1(unsigned int n)
{
    Temp::reset();
    Temp *a = new Temp[n];
    delete []a;
    a = NULL;
    return Temp::getSum();
}
// method two
class A;
A* Array[2];
class A
{
    public:
        virtual unsigned int sum(unsigned int n)
        {
            return 0;
        }
};
class B: public A
{
    public:
        virtual unsigned int sum(unsigned int n)
        {
            return Array[!!n]->sum(n - 1) + n;
        }
};
int sum_solution2(int n)
{
    A a;
    B b;
    Array[0] = &a;
    Array[1] = &b;
    int value = Array[1]->sum(n);
    return value;
 }
// method three
typedef unsigned int (*fun)(unsigned int);
unsigned int solution3_teminator(unsigned int n)
{
    return 0;
}
unsigned int sum_solution3(unsigned int n)
{
    static fun f[2] = {solution3_teminator, sum_solution3};
    return n + f[!!n](n - 1);
}
void test(int n, int expected)
{
    printf("test for %d begins: \n", n);
    if(sum_solution1(n) == expected)
        printf("solution1 passed.\n");
    else 
        printf("solution1 failed.\n");

    if(sum_solution2(n) == expected)
        printf("solution2 passed.\n");
    else 
        printf("solution2 failed.\n");


    if(sum_solution3(n) == expected)
        printf("solution3 passed.\n");
    else 
        printf("solution3 failed.\n");
}
int main(int argc, char* argv[])
{
    test(3, 6);
    return 0;
}