#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Base1 {
 public:
    virtual void myVirtulFunction01() {
        cout << "Base1 myVirtualFunction01()" << endl;
    }
    virtual void myVirtulFunction02() {
        cout << "Base1 myVirtualFunction02()" << endl;
    }
};

class Base2 {
 public:
    virtual void myVirtulFunction03() {
        cout << "Base2 myVirtualFunction03()" << endl;
    }
    virtual void myVirtulFunction04() {
        cout << "Base2 myVirtualFunction04()" << endl;
    }
};

//子类
class Derived : public Base1, public Base2 {
 public:
    //覆盖父类1的虚函数
    virtual void myVirtulFunction02() override {
        cout << "Derive myVirtualFunction02()" << endl;
    }

    //覆盖父类2的虚函数
    virtual void myVirtulFunction04() override {
        cout << "Derive myVirtualFunction04()" << endl;
    }

    //子类的虚函数
    virtual void deriveVirtulFunction05() {
        cout << "DeriveVirtualFunction05()" << endl;
    }

    virtual void deriveVirtulFunction06() {
        cout << "DeriveVirtualFunction06()" << endl;
    }
};

int main(void) {
    cout << sizeof(Base1) << endl;    //4
    cout << sizeof(Base2) << endl;    //4
    cout << sizeof(Derived) << endl;  //8--有两个虚函数表指针

    Derived derive;
    Base1 &b1 = derive;
    Base2 &b2 = derive;
    Derived &derive2 = derive;

    typedef void (*Func)(void);
    long *pder = (long *)(&derive);
    long *vptr1 = (long *)(*pder);  //获取子类对象的第一个vptr指针
    //long*vptr1 = reinterpret_cast<long*>(derive);//error,这种强制类型转换不行

    long *pder2 = pder + 1;          //跳过4个字节，就是第二个虚函数表指针
    long *vptr2 = (long *)(*pder2);  //获取子类对象的第二个vptr指针

    Func f1 = (Func)vptr1[0];  //0x004c123a {virtualFunction.exe!Base1::myVirtulFunction01(void)}
    Func f2 = (Func)vptr1[1];  //0x004c13d9 {virtualFunction.exe!Derived::myVirtulFunction02(void)}
    Func f3 = (Func)vptr1[2];  //0x004c10cd {virtualFunction.exe!Derived::deriveVirtulFunction05(void)}
    Func f4 = (Func)vptr1[3];  //0x004c11ae {virtualFunction.exe!Derived::deriveVirtulFunction06(void)}
    Func f5 = (Func)vptr1[4];  //0x00000000
    Func f6 = (Func)vptr1[5];
    Func f7 = (Func)vptr1[6];
    Func f8 = (Func)vptr1[7];

    Func f21 = (Func)vptr2[0];  //0x004c11b3 {virtualFunction.exe!Base2::myVirtulFunction03(void)}
    Func f22 = (Func)vptr2[1];  //0x004c1433 {virtualFunction.exe!Derived::myVirtulFunction04(void)}
    Func f23 = (Func)vptr2[2];  //0x00000000
    Func f24 = (Func)vptr2[3];

    b1.myVirtulFunction02();       //调用子类函数
    b2.myVirtulFunction04();       //调用子类函数
    derive2.myVirtulFunction02();  //调用子类函数

    cout << "------------------" << endl;
    f1();
    f2();
    f3();
    f4();
    cout << "------------------" << endl;
    f21();
    f22();

    system("pause");
    return 0;
}
/*
* (1)多重继承虚函数表分析
*	1.一个对象，如果有多个基类则有多个虚函数表指针(注意是两个虚函数表指针，不是两个虚函数表)
*	2.在多继承中，对应各个基类vptr指针按照继承顺序依次放置在类的内存空间中。
*		且子类与第一个基类共用一个vptr，第二个基类有自己的vptr指针。
*	3.示意图适合vs2017，不一定适合g++编译器。
*	总结：
*		1.子类对象derive有两个虚函数表指针，vptr1,vptr2。
*		2.类Derived有两个虚函数表，因为它继承自两个基类。
*		3.子类和第一个基类共用一个vptr，因为vptr指向第一个虚函数表。
*		因为我们注意到类Derived的虚函数表1里面的4个函数，有Base1的函数。
*		4.子类的虚函数覆盖了父类中的同名虚函数。
*		
*		
* (2)总结：虚函数表是属于类的，虚函数表指针是属于对象的。
* 一个类的虚函数表可以有多个，一个类对象的虚函数表指针也可以有多个。
*/
