#include <string>
#include <cstdio>
#include <deque>
using namespace std;
template<typename T> class QueueWithMax
{
public:
    QueueWithMax() : currentIndex(0){}

    void push_back(T number)
    {
        while(!maximums.empty() && number >= maximums.back().number)
            maximums.pop_back();

        InternalData internalData = {number, currentIndex};
        data.push_back(internalData);
        maximums.push_back(internalData);
        ++ currentIndex;
    }
    void pop_front()
    {
        if(maximums.empty())
            printf("queue is empty");
        if(maximums.front().index == data.front().index)
            maximums.pop_front();
        data.pop_front();
    }

    T max() const
    {
        if(maximums.empty())
            printf("queue is empty");
        return maximums.front().number;
    }
private:
    struct InternalData
    {
        T number;
        int index;
    };
    deque<InternalData> data;
    deque<InternalData> maximums;
    int currentIndex;
};
// test
void test(const char* testName, const QueueWithMax<int>& queue, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);
    if(queue.max() == expected)
        printf("passed.\n");
    else 
        printf("failed.\n");
}
int main(int argc, char const *argv[])
{
    QueueWithMax<int> queue;
    queue.push_back(2);
    test("test1", queue, 2);
    return 0;
}
