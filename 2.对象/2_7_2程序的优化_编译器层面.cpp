#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class CTemValue {
 public:
    int value1;
    int value2;

 public:
    CTemValue(int v1 = 0, int v2 = 0)
        : value1(v1), value2(v2)  //���캯��
    {
        cout << "�����˹��캯��" << endl;
        cout << "value1=" << value1 << endl;
        cout << "value2=" << value2 << endl;
    }
    CTemValue(const CTemValue &ct)
        : value1(ct.value1), value2(ct.value2) {
        cout << "�����˿������캯��" << endl;
    }
    virtual ~CTemValue() {
        cout << "��������������" << endl;
    }
};

//�������ӽ�
CTemValue DoubleMyself(CTemValue &t) {
    CTemValue tem;
    tem.value1 = t.value1 * 2;
    tem.value2 = t.value2 * 2;
    return tem;

    //�Ż���
    //return CTemValue(t.value1 * 2, t.value2 * 2);//����һ����ʱ����ֱ�ӷ���
}

//�������ӽ�
void DoubleMyself(CTemValue &obj, CTemValue &t) {
    obj.CTemValue::CTemValue(t.value1 * 2, t.value2 * 2);
    return;
}

int main(void) {
    CTemValue ts1(10, 20);
    //CTemValue ts2=DoubleMyself(ts1);//ʹ��һ�����������գ��ͻ���һ����������
    DoubleMyself(ts1);
    /*
	* �������ӽ�
	* CTemValue ts1;
	* ts1.CTemValue::CTemValue(10,20);
	* CTemValue temObj;
	* DoubleMyself(temObj,ts1);
	*/

    system("pause");
    return 0;
}
/*
 *��linuxƽִ̨��������룬���Ż�֮���һ��������һ�ο������������
* (1)����������
* linux�����g++����������Է�����ʱֵ�����Ż���NRV�Ż�(named Return Value)
*	ROV�Ż���return Value Optimization��
*	�ر��Ż���
*	g++ -fno-elide-constructors �ļ���.cpp -o �����ļ�����
* (2)��Windowsƽ̨����Ŀ�����һ�--�����ԡ�--��c/c++��--"�Ż�"
*	���������ɡ�--����������ʱ��顱--��Ĭ��ֵ��
* (3)�Ż�˵����
*	1.�������Ƿ������Ż�����Ҫ������
*	2.������ܸ��ӣ�������������Ż�
*	3.��Ҫ�����Ż��������Ż����ܵ��³�������ڹ��캯������ʵ��ĳЩ���ܣ����Ǳ��Ż���û��ִ�С�
*	
*/
