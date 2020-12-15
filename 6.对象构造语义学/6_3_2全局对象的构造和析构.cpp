#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

/*二：全局对象的构造和析构
 *全局变量是放在数据段里的
 *全局对象，在不给初值的情况下，编译器默认会把全局对象所在内存全部清0；没有赋初值在BSS段
 *全局变量在编译阶段就会把空间分配出来（全局变量的地址在编译期间就确定好的，地址不会改变）
 *
 *
 *结论：
 *全局对象构造和析构的步骤：
 *	a)全局对象g_aobj获得地址（编译时确定好的，内存也是编译时分配好的，内存是运行期间一直存在）
 *	b)把全局对象g_aobj的内存内容清0的能力（也叫静态初始化）
 *	c)调用全局对象g_aobj所对应的类A的构造函数
 *	d)main()
 *	{
 *	//......
 *	}
 *	....
 *	e)调用全局对象g_aobj所对应类A的析构函数
 */

class A {
 public:
    A() {
        cout << "A::A()" << endl;
    }
    ~A() {
        cout << "A::~A()" << endl;
    }
    int m_i;
};

A g_aobj;  //全局对象，该全局对象在main函数执行之前就被构造完毕，可以在main函数中直接使用了
           //在main函数执行完毕后，才被析构掉的

void func() {
    printf("g_aobj全局对象的地址=%p\n", &g_aobj);
}

int main() {
    g_aobj.m_i = 6;
    func();
    system("pause");
    return 1;
}