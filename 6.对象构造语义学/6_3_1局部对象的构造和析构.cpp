#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

//һ���ֲ�����Ĺ��������
//ֻҪ���˶���������򣬱������ܻ����ʵ��ĵط�������ö������������Ĵ��룻
//���ۣ�ʹ�õ�ʱ���壬��Ҫ�ڿ�ͷ���壬������һ�������򣬿��ܶ���ù��캯��
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

void func() {
    A obja;  //���飺�����ֶ��壬���ھֲ�������ߵ�m_i�����ֵ��
    //������ڿ�ͷ��������һ�������򣬾�Ҫ���������������ȵ�ʹ�õ�ʱ��Ҫ�ٴε��ù��캯��������ù��������
    obja.m_i = 10;

    int mytest = 1;
    if (mytest == 0)  //swtich case return;
    {
        return;
    }

    return;
}

int main() {
    func();
    system("pause");
    return 1;
}
