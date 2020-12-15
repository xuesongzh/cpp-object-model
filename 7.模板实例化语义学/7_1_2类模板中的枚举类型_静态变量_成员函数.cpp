#include <iostream>

using namespace std;

/*
 * ���������û��ʹ�õ���ģ�壬��ô�������ͻ��MyClass����ģ���Ӷ��������ͺ������û�����һ����
 */

template <typename T>
class MyClass {
 public:
    T m_i;
    T m_j;
    MyClass(T temi = 0, T temj = 0)
        : m_i(temi), m_j(temj) {
    }

    //��ͨ��Ա����
    void myFunction01() const {
        cout << "myFunction01������" << endl;
    }
    void myFunction02() const {
        cout << "myFunction02������" << endl;
    }

    //��ģ���е�ö������
    enum ECURRSTATUS {
        ECUS_Busy,
        ECUS_Free
    };

    //��̬��Ա����--����
    static int m_sti;
    static T m_stj;
};

//��̬��Ա��������
template <typename T>
int MyClass<T>::m_sti = 10;

template <typename T>
T MyClass<T>::m_stj = 15;  //���︳ֵȡ����T�����ͣ�����ָ������Ҫ��15����

void func() {
    //2.1ö������
    MyClass<int>::ECURRSTATUS myEnum;
    myEnum = MyClass<int>::ECUS_Busy;

    MyClass<double>::ECURRSTATUS myEnum02;
    myEnum02 = MyClass<double>::ECUS_Free;
    //���ۣ����е�ö�����������ھ������ģ�����ͣ����Ǻ���ģ���ϵ����

    //2.2��̬��Ա����--�౾��û�б�ʵ������ֻ�ǳ�Ա������ʵ����
    MyClass<int>::m_sti = 14;
    MyClass<float>::m_sti = 15;
    cout << MyClass<int>::m_sti << endl;    //14
    cout << MyClass<float>::m_sti << endl;  //15
    //����������ص����ͱ���

    MyClass<int>::m_stj = 34;
    cout << MyClass<int>::m_stj << endl;  //34

    //2.3��ģ���ʵ����
    MyClass<int>* pobj = NULL;  //����д��û��ʵ�������������

    const MyClass<int>& obj = 0;  //�����˹��캯����ʵ��������ģ��
    /*
	 * վ�ڱ������Ƕȣ�
	 * MyClass<int> temObj(0);
	 * const MyClass<int> &obj = temObj;
	 */

    //2.4��Ա����ʵ��������û�е��ó�Ա����������£��ǲ���ʵ����
    obj.myFunction01();  //const����������const����
}

int main(void) {
    func();
    system("pause");
    return 0;
}