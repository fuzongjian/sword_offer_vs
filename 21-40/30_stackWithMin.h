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
    stackWithMin(){}
    virtual ~stackWithMin(){}
    T& top();
    const T& top() const;
    void push(const T& value);
    void pop();

    const T& min() const;

    bool empty() const;
    size_t size() const;
};
template <typename T> void stackWithMin<T>::push(const T& value)
{
    // 把新元素添加到辅助栈
    m_data.push(value);

    // 当新元素比之前的最小元素小时，把新元素插入辅助栈里；否则把之前的最小元素重复插入辅助栈中。
    if(m_min.size() == 0 || value < m_min.top())
        m_min.push(value);
    else 
        m_min.push(m_min.top());
}

template <typename T> void stackWithMin<T>::pop()
{
    assert(m_data.size() > 0 && m_min.size() > 0);
    m_data.pop();
    m_min.pop();
}

template <typename T> const T& stackWithMin<T>::min() const
{
    assert(m_data.size() > 0 && m_min.size() > 0);
    return m_min.top();
}

template <typename T> T& stackWithMin<T>::top()
{
    return m_data.top();
}

template <typename T> const T& stackWithMin<T>::top() const
{
    return m_data.top();
}

template <typename T> bool stackWithMin<T>::empty() const
{
    return m_data.empty();
}

template <typename T> size_t stackWithMin<T>::size() const
{
    return m_data.size();
}