#include <stdio.h>

#include <iostream>

using namespace std;

class Base {  //sizeof = 8�ֽ�
 public:
    int m_i1;
    char m_c1;
    char m_c2;
    char m_c3;
};

//���̳�--��һ����Base��ɶ����
class Base1 {
 public:
    int m_i1;
    char m_c1;
};
class Base2 : public Base1 {
 public:
    char m_c2;
};
class Base3 : public Base2 {
 public:
    char m_c3;
};

int main() {
    //����̳й�ϵ�󣬿��ܻ�����ڴ�ռ�Ķ������ӡ�Base3��������8���ֽ�

    cout << sizeof(Base1) << endl;                //8
    cout << sizeof(Base2) << endl;                //12
    cout << sizeof(Base3) << endl;                //16
    printf("Base3::m_mi1 = %d\n", &Base3::m_i1);  //0
    printf("Base3::m_mc1 = %d\n", &Base3::m_c1);  //4
    printf("Base3::m_mc2 = %d\n", &Base3::m_c2);  //8
    printf("Base3::m_mc3 = %d\n", &Base3::m_c3);  //12

    //linux��windows�����ݲ��ֲ�һ��(8,12,12)��˵����
    //a)�������ڲ��ϵĽ������Ż���
    //b)��ͬ���̱�������ʵ��ϸ��Ҳ��һ����
    //c)�ڴ濽����Ҫ������

    //������memcpy�ڴ濽����Base2����ֱ��Base3����
    Base2 mybase2obj;
    Base3 mybase3obj;

    system("pause");
    return 1;
}
