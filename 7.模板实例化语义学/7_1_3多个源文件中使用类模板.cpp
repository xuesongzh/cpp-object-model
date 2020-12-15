#include <iostream>

#include "MyTemplate.h"
using namespace std;
template class MyClass<int>;                       //显示实例化类模板
template void MyClass<int>::myFunction02() const;  //实例化具体的成员函数

int main(void) {
    MyClass<int> myobj;
    myobj.m_i = 10;
    myobj.m_j = 20;
    myobj.myFunction01();
    myobj.myFunction02();
    myobj.myVirtualFunction01();
    system("pause");
    return 0;
}
/*
 * 多个源文件中使用类模板
 * 一般多个文件都会用到类模板，所以放在.h文件中
 * 在多个cpp生成的obj文件中，可能产生多个重复的实例化类，但是链接的时候只会保留一个MyClass<int>类的实体，其余的会被忽略掉。
 *
 * 虚函数的实例化
 *	为什么虚函数没有被调用，也会被实例化出来？？
 *	因为有虚函数，编译器就会产生虚函数表，虚函数表里是各个虚函数的地址，那么必须要实例化每个虚函数出来。
 */