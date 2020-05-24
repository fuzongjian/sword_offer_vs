#include <cstdio>
#include <string>
#include "30_stackWithMin.h"
void test(const char* testName, const stackWithMin<int>& stack, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    if(stack.min() == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}
int main(int argc, char* argv[])
{
    stackWithMin<int> stack;
    stack.push(3);
    test("test1", stack, 3);

    stack.push(4);
    test("test2", stack, 3);

    stack.push(2);
    test("test3", stack, 2);

    stack.push(3);
    test("test4", stack, 2);

    stack.pop();
    test("test5", stack, 2);
    
    return 0;
}