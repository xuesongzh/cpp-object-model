#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class TEST {
 public:
    int m_i;
    int *p;
    //构造函数
    TEST() {
        p = new int(23);
        m_i = 0;
        cout << "构造函数执行" << endl;
    }
    TEST(int value)
        : m_i(value) {
        p = new int(value);
        cout << "带一个参数的构造函数执行" << endl;
    }
    //拷贝构造函数--没有拷贝构造函数会报异常
    TEST(const TEST &t) {
        this->p = new int(t.m_i);  //深拷贝
        this->m_i = t.m_i;
    }
    ~TEST() {
        delete p;
        cout << "析构函数执行" << endl;
    }
};

int main(void) {
    TEST test01(12);
    TEST test02(test01);
    //如果没有拷贝构造函数，两个对象，会释放两次p指向的内存空间，会报异常。

    system("pause");
    return 0;
}

// 自己写了拷贝构造函数一定要实现拷贝构造函数的功能，要对每个成员变量初始化。
// 当有指针类型的成员变量指向其他内存，就需要写拷贝构造函数。深拷贝--动态内存分配。
