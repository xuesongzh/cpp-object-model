#include <stdio.h>

#include <iostream>
#include <vector>

using namespace std;
class MYACLS {
 public:
    int m_i;
    void myfunc(int abc) {
        m_i += abc;
    }
};

//�������ӽ�linux
//void _ZN6MYACLS6myfuncEi(MYACLS *const this, int abc) //����������ⰲ��һ��thisָ�룬һ����ӵ������Ŀ�ͷ
//{
//	this->m_i += abc;
//}

void gmyfunc(MYACLS *ptmp, int abc) {
    ptmp->m_i += abc;
}

int main() {
    MYACLS myacls;
    myacls.myfunc(18);  //���ó�Ա����
    //_ZN6MYACLS6myfuncEi(&myacls,18)

    gmyfunc(&myacls, 18);  //����ȫ�ֺ���

    /*
    * c++������Ƶ�ʱ����һ��Ҫ��Ҫ���������ͨ��Ա�����ĵ��ò�Ӧ�ñ�ȫ�ֺ���Ч�ʲ
    * �����������Ҫ�󣬱������ڲ�ʵ�����ǽ��Գ�Ա����myfunc()�ĵ���ת�����˶� ȫ�ֺ����ĵ��ã�
    * ��Ա�����ж������ڴ��ַ���Ǹ������ߵģ����ڱ����ʱ���ȷ���õģ�
    *
    * a������������������һ��thisָ���βΣ�ָ�����ʵ�������ɵĶ���
    * b)�����Ա�����Ĵ�ȡ����ͨ��thisָ�������У���������this->m_i + abc;
    */
    printf("MYACLS::myfunc�ĵ�ַ=%p\n", &MYACLS::myfunc);  //002A102D

    system("pause");
    return 1;
}
