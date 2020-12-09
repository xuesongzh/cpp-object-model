#include <stdio.h>

#include <iostream>
#include <vector>

using namespace std;

class Grand  //爷爷类
{
 public:
    int m_grand;
};

class A1 : virtual public Grand {
 public:
    int m_a1;
};

class A2 : virtual public Grand {
 public:
    int m_a2;
};

class C : public A1, public A2 {
 public:
    int m_c;
};

int main() {
    cout << sizeof(Grand) << endl;
    cout << sizeof(A1) << endl;
    cout << sizeof(A2) << endl;
    cout << sizeof(C) << endl;

    C c;  //这里查看内存
    /*
	 003D2089  mov         eax,dword ptr [this]  
	 003D208C  mov         dword ptr [eax],offset C::`vbtable' (03D6B40h)  
	 003D2092  mov         eax,dword ptr [this]  
	 003D2095  mov         dword ptr [eax+8],offset C::`vbtable' (03D6B48h)

	构造函数里添加的给虚基类表指针赋值的代码
	 */
    c.m_grand = 2;
    c.m_a1 = 5;
    c.m_a2 = 6;
    c.m_c = 8;

    //结论：对继承过来的虚基类成员变量的访问相比于其他成员变量的访问速度要慢。
    //没有用到vbptr2，只用到了vbptr1

    /*
	 * 二：虚基类为什么这么设计
	 * 虚基类为了实现爷爷类只有一份拷贝，设计复杂，有这么多偏移和虚基类表指针？为什么这么设计？？？
	 * 为什么这么设计，是个很难回答的问题
	 * 不同的编译器厂商有不同的实现，vc++是通过虚基类表实现
	 * linux下的gcc编译器可能把偏移量放在其他位置，如虚函数表中存储
	 */

    // 这里就会用到vbptr2去给m_grand赋值
    A2 *pa2 = &c;
    pa2->m_grand = 8;
    pa2->m_a2 = 9;

    system("pause");
    return 1;
}

//虚基类是编译期确定的，每个对象的vbptr是一样的