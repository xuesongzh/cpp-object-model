#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class A {
 public:
    int number;                        //4个字节
    virtual void virtualFunction() {}  //虚函数
};

int main(void) {
    A a;
    int length = sizeof(a);
    cout << "length=" << length << endl;  //8

    char* p1 = reinterpret_cast<char*>(&a);  //强制类型转换，&a的首地址
    char* p2 = reinterpret_cast<char*>(&a.number);
    if (p1 == p2)  //对象和对象中的成员变量位置相同，说明number在对象内存布局上面，虚函数表指针在下面。
    {
        cout << "虚函数表指针位于对象内存的末尾" << endl;
    } else {
        cout << "虚函数表指针位于对象内存的开头位置" << endl;
    }
    //结论：虚函数表指针位于整个对象内存布局的开头位置。

    system("pause");
    return 0;
}
/*
 *3_1虚函数表指针位置分析_位于对象内存布局的开头位置
* (1)虚函数表指针位置分析
* 类：有虚函数，该类会产生一个虚函数表(vtbl)。
* 使用类生成对象的时候，对象中会有一个虚函数表指针(vptr)，用于指向类的虚函数表开始地址。
* 虚函数表在生成可执行程序的时候会保存在可执行程序文件中。
*
* //结论：虚函数表指针位于整个对象内存布局的开头位置。
*
*/
