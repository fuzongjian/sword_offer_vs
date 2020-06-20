#include <string>
#include <cstdio>
/* 题目1：赋值运算符
如下为类型CMyString的声明，请为该类型添加赋值运算符函数
*/ 
// define
class CMyString
{
private:
    char* m_pData;
public:
    CMyString(char* pData = nullptr);
    CMyString(const CMyString* str);
    ~CMyString();

    CMyString& operator = (const CMyString& str);
    void print();
};

CMyString::CMyString(char* pData)
{
    if(pData == nullptr)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else 
    {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, pData);
    }
}
CMyString& CMyString::operator=(const CMyString& str)
{
    if(this == &str)
        return *this;
    delete []m_pData;
    m_pData = nullptr;

    m_pData = new char[strlen(str.m_pData) + 1];
    strcpy(m_pData, str.m_pData);
    return *this;
}
void CMyString::print()
{
    printf("%s\n", m_pData);
}
CMyString::~CMyString()
{
    delete[] m_pData;
}
// test
void test1()
{
    printf("Test1 begins: \n");
    char *text = "Hello world";
    CMyString str1(text);
    CMyString str2;
    str2 = str1;

    printf("The expected result is %s.\n", text);

    printf("The actual result is: ");
    str2.print();
}
int main(int argc, char* argv[])
{
    test1();
    return 0;
}