#include <cstdio>
#include <string>
void testOprator()
{
    int a = 20, b = 10;
    // int middle = (a + b) >> 1;
    // (a -b) = 10 二进制位为1010，右移1位，即为0101，转为十进制为5，5 + 10 = 15 
    int middle = ((a - b) >> 1) + b;

    printf("%d \n", middle);
}
int main(int argc, char* argv[])
{
    testOprator();
    return 0;
}