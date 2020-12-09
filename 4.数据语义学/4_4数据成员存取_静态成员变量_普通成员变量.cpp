#include <stdio.h>

#include <ctime>
#include <iostream>
using namespace std;

class FAC {
 public:
    int m_fai;
    int m_faj;
};

class MYACLS : public FAC {
 public:
    int m_i;
    static int m_si;  //���������Ƕ���
    int m_j;

    void myfunc() {
        m_i = 5;
        m_j = 6;
    }
};

int MYACLS::m_si = 10;  //����Ƕ���

int main() {
    /*
	 * 1.��̬��Ա�����Ĵ�ȡ
	 * ��ľ�̬��Ա���������Ե���һ��ȫ������������ֻ����Ŀռ��ڿɼ�������ʱ�� ����::��̬��Ա������
	 * ���еľ�̬��Ա����ֻ��һ��ʵ�壬�����ڿ�ִ���ļ������ݶεģ�
	 */

    MYACLS myobj;
    MYACLS *pmyobj = new MYACLS();

    //��̬��Ա�ķ��ʣ���3�л�����û���κβ��
    cout << MYACLS::m_si << endl;  //ͨ��������
    cout << myobj.m_si << endl;    //ͨ����������
    cout << pmyobj->m_si << endl;  //ͨ������ָ��

    //�������ͨ��Ա����--ÿ���������ͨ��Ա������ַ��ͬ
    printf("myobj.m_i = %p\n", &myobj.m_i);
    printf("pmyobj->m_i = %p\n", &pmyobj->m_i);

    //��̬��Ա�����ĵ�ַ��ͬ
    printf("MYACLS::m_si = %p\n", &MYACLS::m_si);
    printf("myobj.m_si = %p\n", &myobj.m_si);
    printf("pmyobj->m_si = %p\n", &pmyobj->m_si);

    //2.�Ǿ�̬��Ա�����Ĵ�ȡ����ͨ�ĳ�Ա���������������Ķ����С���ȡͨ������������ָ�룩

    pmyobj->myfunc();
    //�������Ƕ�--����һ�����صĲ���thisָ�룺
    //MYACLS::myfunc(MYACLS *const this)
    //{
    //this->m_i = 5;
    //this->m_j = 6;
    //}

    //������ͨ��Ա�ķ��ʷ�ʽ���������ǰ��������׵�ַ���ϳ�Ա������ƫ��ֵ
    // &myobj + 4  = &myobj.m_j
    printf("MYACLS::m_i = %d\n", &MYACLS::m_i);  //ƫ��8�ֽ� ----�̳еĸ�������2��int���������Ե�һ������ƫ��8
    printf("MYACLS::m_j = %d\n", &MYACLS::m_j);  //ƫ��12�ֽ�

    pmyobj->myfunc();
    pmyobj->m_faj = 7;

    //ͨ������Ͷ���ָ�������ʲô������û���������𣬵�������࣬������ȥ����үү��ʱ�������޷�ֱ�ӷ���ƫ��ֵ
    myobj.m_i = 15;
    pmyobj->m_i = 15;

    system("pause");
    return 1;
}
/*1.��̬��Ա�����Ĵ�ȡ
 *	��̬��Ա�������������ݶ�.data�Σ���ռ����Ŀռ䣬���ʿ���ʹ���������������֣�����ָ�롣
 *
 *2.��ͨ��Ա�������ն���洢�ڴ�����������С�
 *����ʱʹ��������ַ�ӳ�Ա����ƫ��ֵ���з��ʡ�
 *ע�⣺
 *	1.������麯�����麯����ָ��ռ��ͷ4���ֽڡ�
 *	2.�̳еĸ���ĳ�Ա�������麯��ָ����棬Ȼ��������Լ��ĳ�Ա������
 *
 *	�麯����ָ��
 *	�����Ա����
 *	���Ա����
 * 
 */
