
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
    void myselffunc() {}  //ֻ����Derive�ĺ���
    virtual ~Derive() {}
};

int main() {
    //һ��RTTI������ʱ����ʶ�𣩼򵥻ع�--c++����RTTI��Ŀ�ľ���Ϊ���ó��������е�ʱ�򣬸���ָ��������õ�ʵ�����͵��ú���
    Base *pb = new Derive();
    pb->g();

    Derive myderive;
    Base &yb = myderive;  //���������������
    yb.g();

    //c++����ʱ����ʶ��RTTI��Ҫ�����б���������һ���麯�������������û���麯������ô�õ�RTTI�Ͳ�׼ȷ��
    //RTTI�Ϳ�����ִ���ڼ��ѯһ����ָ̬�룬���߶�̬���õ���Ϣ�ˣ�
    //RTTI������typeid��dynamic_cast����������֣�
    cout << typeid(*pb).name() << endl;
    cout << typeid(yb).name() << endl;
    cout << "----------------------------" << endl;
    /*
	    Derive::g()
		Derive::g()
		class Derive
		class Derive
	 */
    //����ת�����ж�����
    Derive *pderive = dynamic_cast<Derive *>(pb);
    if (pderive != NULL) {
        cout << "pbʵ����һ��Derive����" << endl;
        pderive->myselffunc();  //�����Լ�ר������
    }

    //����RTTIʵ��ԭ��--RTTI����������Ϣ�洢���麯�����У����麯����ַ����4���ֽڣ�
    //typeid���ص���һ��������������ã�����������������һ����type_info���ࣩ��
    const std::type_info &tp = typeid(*pb);
    //tp = {_Data={_UndecoratedName=0x01184c8c "class Derive" _DecoratedName=0x007cc158 ".?AVDerive@@" } }
    Base *pb2 = new Derive();
    const std::type_info &tp2 = typeid(*pb2);

    if (tp == tp2) {
        cout << "�ܺã�������ͬ" << endl;
    }

    //�����÷�����̬���ͣ������ڶ�̬����
    cout << typeid(int).name() << endl;
    cout << typeid(Base).name() << endl;
    cout << typeid(Derive).name() << endl;
    Derive *pa3 = new Derive();
    cout << typeid(pa3).name();

    //RTTI�Ĳ����������������Ƿ�����麯�����й�ϵ�����������û���麯����Ҳ�Ͳ����ڻ�����麯����RTTI���޷��õ���ȷ�����
    //���ۣ�RTTI����������Ϣ�洢���麯�����У����麯����ַ����4���ֽ�

    //RTTI��ص�ַ
    printf("tp2��ַΪ:%p\n", &tp2);
    long *pvptr = (long *)pb2;
    long *vptr = (long *)(*pvptr);
    printf("�麯�����׵�ַΪ:%p\n", vptr);
    printf("�麯�����׵�ַ֮ǰһ����ַΪ:%p\n", vptr - 1);  //�����-1ʵ��������������4���ֽ�

    long *prttiinfo = (long *)(*(vptr - 1));
    prttiinfo += 3;  //����12�ֽ�
    long *ptypeinfoaddr = (long *)(*prttiinfo);
    const std::type_info *ptypeinfoaddrreal = (const std::type_info *)ptypeinfoaddr;
    printf("ptypeinfoaddrreal��ַΪ:%p\n", ptypeinfoaddrreal);
    cout << ptypeinfoaddrreal->name() << endl;
    /*
		tp2��ַΪ:000FC150
		�麯�����׵�ַΪ:000F9B70
		�麯�����׵�ַ֮ǰһ����ַΪ:000F9B6C
		ptypeinfoaddrreal��ַΪ:000FC150
		class Derive
	 */

    //����vptr,vtbl,rtti��type_info��Ϣ ����ʱ��
    /*vprt�Ǳ����������뵽�����еģ����������һ����Ա�������ڹ��캯���в�����룬�麯����ָ��ָ���麯����
	 *vtblҲ�Ǳ����ʱ������õ�
	 *rtti��type_info��ϢҲ�ǻ�����ģ������ʹ����ˣ�д���˿�ִ���ļ���
	 */

    //�ܽ�һ�£�����������ʵ����һ�����죬�����嶼�����麯����ʼ��ַΪͻ�ƿ�

    system("pause");
    return 1;
}
