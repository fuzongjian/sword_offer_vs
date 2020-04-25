#include <iostream>
#include <stack>
#include <exception>
using namespace std;
class FQueue
{
private:
    /* data */
    stack <int> stack1;
    stack <int> stack2;
public:
    void appendTail(int n){
        stack1.push(n);
    }
    int deleteHead(){
        int result = -1;
        if (stack1.empty() && stack2.empty()){
            return result;
        }
        if (stack2.empty())
        {
            while (!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        result = stack2.top();
        stack2.pop();
        return result;
    }
};
void Test(int actual, int expected){
    if (actual == expected )
    {
        printf("Test passed.\n");
    }
    else 
    {
        printf("Test failed.\n");
    }
    
}
int main(int argc, char* argv[]){
    FQueue queue;
    queue.appendTail(1);
    queue.appendTail(2);
    queue.appendTail(3);
    Test(1,queue.deleteHead());

    Test(2, queue.deleteHead());


    return 0;
}