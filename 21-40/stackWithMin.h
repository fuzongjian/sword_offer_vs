#pragma once
#include <stack>
#include <assert.h>
using namespace std;
/*
题目：30 包含min函数的栈
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min函数，在该栈中，调用min、push、pop的时间复杂度都是0(1)
*/
template <typename T> class stackWithMin
{
private:
    std::stack<T>   m_data;  // 数据栈，存放栈的所有元素
    std::stack<T>   m_min;   // 辅助栈，存放栈的最小元素
public:
    
};

