#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

typedef string mytype;

class A {
    //typedef int mytype;
 public:
    void myFunction(mytype temvalue);  //����mytype��string����

 public:
    typedef int mytype;
    mytype value;  //�ȶ������ͣ�����m_value��int����
};

void A::myFunction(::mytype temvalue) {
    //value = temvalue;//error ��string����ת��Ϊint����0
}

int main(void) {
    system("pause");
    return 0;
}

/*
* ���ۣ����ڳ�Ա�������������ڵ�һ������mytype���͵�ʱ�򱻾����ġ�
* ���Ե�һ������mytpye��ʱ�򣬱�����������typedef string mytype���ͰѲ�������string���͡�
* ���ۣ�Ϊ�������о��翴��mytype���ͣ����Ͷ������һ��Ҫ���嵽���ʼ��λ�á�
*/
