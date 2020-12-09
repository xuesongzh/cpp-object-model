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

//����
class Derived : public Base1, public Base2 {
 public:
    //���Ǹ���1���麯��
    virtual void myVirtulFunction02() override {
        cout << "Derive myVirtualFunction02()" << endl;
    }

    //���Ǹ���2���麯��
    virtual void myVirtulFunction04() override {
        cout << "Derive myVirtualFunction04()" << endl;
    }

    //������麯��
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
    cout << sizeof(Derived) << endl;  //8--�������麯����ָ��

    Derived derive;
    Base1 &b1 = derive;
    Base2 &b2 = derive;
    Derived &derive2 = derive;

    typedef void (*Func)(void);
    long *pder = (long *)(&derive);
    long *vptr1 = (long *)(*pder);  //��ȡ�������ĵ�һ��vptrָ��
    //long*vptr1 = reinterpret_cast<long*>(derive);//error,����ǿ������ת������

    long *pder2 = pder + 1;          //����4���ֽڣ����ǵڶ����麯����ָ��
    long *vptr2 = (long *)(*pder2);  //��ȡ�������ĵڶ���vptrָ��

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

    b1.myVirtulFunction02();       //�������ຯ��
    b2.myVirtulFunction04();       //�������ຯ��
    derive2.myVirtulFunction02();  //�������ຯ��

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
* (1)���ؼ̳��麯�������
*	1.һ����������ж���������ж���麯����ָ��(ע���������麯����ָ�룬���������麯����)
*	2.�ڶ�̳��У���Ӧ��������vptrָ�밴�ռ̳�˳�����η���������ڴ�ռ��С�
*		���������һ�����๲��һ��vptr���ڶ����������Լ���vptrָ�롣
*	3.ʾ��ͼ�ʺ�vs2017����һ���ʺ�g++��������
*	�ܽ᣺
*		1.�������derive�������麯����ָ�룬vptr1,vptr2��
*		2.��Derived�������麯������Ϊ���̳����������ࡣ
*		3.����͵�һ�����๲��һ��vptr����Ϊvptrָ���һ���麯����
*		��Ϊ����ע�⵽��Derived���麯����1�����4����������Base1�ĺ�����
*		4.������麯�������˸����е�ͬ���麯����
*		
*		
* (2)�ܽ᣺�麯������������ģ��麯����ָ�������ڶ���ġ�
* һ������麯��������ж����һ���������麯����ָ��Ҳ�����ж����
*/
