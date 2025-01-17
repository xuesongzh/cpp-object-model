
#include <stdio.h>

#include <iostream>
#include <vector>

using namespace std;

class Base {
 public:
    virtual void f() {
        cout << "Base::f()" << endl;
    }
    virtual void g() {
        cout << "Base::g()" << endl;
    }
    virtual void h() {
        cout << "Base::h()" << endl;
    }
    virtual ~Base() {}
};

class Derive : public Base {
 public:
    virtual void g() {
        cout << "Derive::g()" << endl;
    }
    void myselffunc() {}  //只属于Derive的函数
    virtual ~Derive() {}
};

int main() {
    //一：RTTI（运行时类型识别）简单回顾--c++引入RTTI的目的就是为了让程序在运行的时候，根据指针或者引用的实际类型调用函数
    Base *pb = new Derive();
    pb->g();

    Derive myderive;
    Base &yb = myderive;  //基类引用子类对象
    yb.g();

    //c++运行时类型识别RTTI，要求父类中必须至少有一个虚函数；如果父类中没有虚函数，那么得到RTTI就不准确；
    //RTTI就可以在执行期间查询一个多态指针，或者多态引用的信息了；
    //RTTI能力靠typeid和dynamic_cast运算符来体现；
    cout << typeid(*pb).name() << endl;
    cout << typeid(yb).name() << endl;
    cout << "----------------------------" << endl;
    /*
	    Derive::g()
		Derive::g()
		class Derive
		class Derive
	 */
    //类型转换来判断类型
    Derive *pderive = dynamic_cast<Derive *>(pb);
    if (pderive != NULL) {
        cout << "pb实际是一个Derive类型" << endl;
        pderive->myselffunc();  //调用自己专属函数
    }

    //二：RTTI实现原理--RTTI对象的相关信息存储在虚函数表中，在虚函数地址上面4个字节，
    //typeid返回的是一个常量对象的引用，这个常量对象的类型一般是type_info（类）；
    const std::type_info &tp = typeid(*pb);
    //tp = {_Data={_UndecoratedName=0x01184c8c "class Derive" _DecoratedName=0x007cc158 ".?AVDerive@@" } }
    Base *pb2 = new Derive();
    const std::type_info &tp2 = typeid(*pb2);

    if (tp == tp2) {
        cout << "很好，类型相同" << endl;
    }

    //其他用法，静态类型；不属于多态类型
    cout << typeid(int).name() << endl;
    cout << typeid(Base).name() << endl;
    cout << typeid(Derive).name() << endl;
    Derive *pa3 = new Derive();
    cout << typeid(pa3).name();

    //RTTI的测试能力跟基类中是否存在虚函数表有关系，如果基类中没有虚函数，也就不存在基类的虚函数表，RTTI就无法得到正确结果；
    //结论：RTTI对象的相关信息存储在虚函数表中，在虚函数地址上面4个字节

    //RTTI相关地址
    printf("tp2地址为:%p\n", &tp2);
    long *pvptr = (long *)pb2;
    long *vptr = (long *)(*pvptr);
    printf("虚函数表首地址为:%p\n", vptr);
    printf("虚函数表首地址之前一个地址为:%p\n", vptr - 1);  //这里的-1实际上是往上走了4个字节

    long *prttiinfo = (long *)(*(vptr - 1));
    prttiinfo += 3;  //跳过12字节
    long *ptypeinfoaddr = (long *)(*prttiinfo);
    const std::type_info *ptypeinfoaddrreal = (const std::type_info *)ptypeinfoaddr;
    printf("ptypeinfoaddrreal地址为:%p\n", ptypeinfoaddrreal);
    cout << ptypeinfoaddrreal->name() << endl;
    /*
		tp2地址为:000FC150
		虚函数表首地址为:000F9B70
		虚函数表首地址之前一个地址为:000F9B6C
		ptypeinfoaddrreal地址为:000FC150
		class Derive
	 */

    //三：vptr,vtbl,rtti的type_info信息 构造时机
    /*vprt是编译器给加入到对象中的，是属于类的一个成员变量，在构造函数中插入代码，虚函数表指针指向虚函数表。
	 *vtbl也是编译的时候给做好的
	 *rtti的type_info信息也是基于类的，编译后就存在了，写到了可执行文件中
	 */

    //总结一下：各个编译器实现有一定差异，但总体都是以虚函数表开始地址为突破口

    system("pause");
    return 1;
}
