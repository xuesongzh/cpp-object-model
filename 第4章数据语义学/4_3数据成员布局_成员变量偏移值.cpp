#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define GET(A,m) (int)(&((A*)0)->m) 
//����һ����
#pragma pack(1) //���뷽ʽ����Ϊ1�ֽڶ��루�����룩
class MYACLS
{
public:
	int m_i;//4
	static int m_si; //�������Ƕ���

	int m_j;//4
	static int m_sj;

	int m_k;//4
	static int m_sk;

	char m_c;  //1�ֽ�
	int m_n;   //4�ֽ�

private:
	int m_pria;//4
	int m_prib;//4

public:
	void printMemPoint()
	{
		cout << "��ӡ��Ա����ƫ��ֵ------------" << endl;
		printf("MYACLS::m_i = %d\n", &MYACLS::m_i);//�������������Ǵ�ӡƫ��ֵ
		printf("MYACLS::m_j = %d\n", &MYACLS::m_j);
		printf("MYACLS::m_k = %d\n", &MYACLS::m_k);
		printf("MYACLS::m_c = %d\n", &MYACLS::m_c);
		printf("MYACLS::m_n = %d\n", &MYACLS::m_n);

		printf("MYACLS::m_pria = %d\n", &MYACLS::m_pria);
		printf("MYACLS::m_prib = %d\n", &MYACLS::m_prib);
		cout << "-------------------------" << endl;

		cout << GET(MYACLS, m_prib) << endl;

	}
public:
	virtual void myfv() {}//�麯��ָ��ռ��4�ֽ�
};
#pragma pack() //ȡ��ָ�����룬�ָ�ȱʡ���룻


int MYACLS::m_sj = 0; //����Ƕ��壻,�洢�ڳ�������ݶ��С�

int main()
{
	//һ���۲��Ա������ַ����
	MYACLS myobj;//������ջ�ϵ��ڴ����
	cout << sizeof(myobj) << endl;//29

	//1.�鿴�ڴ棬���ڴ����ǰ��ն���˳��
	myobj.m_i = 2;
	myobj.m_k = 8;
	myobj.m_j = 5;

	printf("myobj.m_i = %p\n", &myobj.m_i);
	printf("myobj.m_j = %p\n", &myobj.m_j);
	printf("myobj.m_k = %p\n", &myobj.m_k);
	printf("myobj.m_c = %p\n", &myobj.m_c);
	printf("myobj.m_n = %p\n", &myobj.m_n);

	MYACLS *pmyobj = new MYACLS();//�����ڶ��ϵĶ���
	printf("pmyobj->m_i = %p\n", &pmyobj->m_i);
	printf("pmyobj->m_j = %p\n", &pmyobj->m_j);
	printf("pmyobj->m_k = %p\n", &pmyobj->m_k);
	printf("pmyobj->m_c = %p\n", &pmyobj->m_c);
	printf("pmyobj->m_n = %p\n", &pmyobj->m_n);
	//�Ƚ�����ֵĳ�Ա�������ڴ����и��ߵĵ�ַ��

	cout << "************************************************" << endl;
	pmyobj->printMemPoint();

	//��Ա����ָ��Ķ��巽��
	int MYACLS::*mypoint = &MYACLS::m_n;
	printf("pmyobj->m_nƫ��ֵ = %d\n", mypoint);

	system("pause");
	return 1;
}
/*
 *4_3���ݳ�Ա����_��Ա����ƫ��ֵ
 * 1.��ͨ��Ա�����Ĵ洢˳�� �ǰ��������еĶ���˳����ϵ������ģ�
 * 
 * �ඨ����pubic,private,protected�ؼ��ֵ���������Ӱ��������sizeof��
 * 
 * 2���߽�������ֽڶ���
 * ĳЩ���ػᵼ�³�Ա����֮�����в����������Ǳ߽�������ֽڶ��룩��������Ŀ�������Ч�ʣ����������Զ�������
 * ����������Ա����֮���һЩ�ֽڣ�ʹ��������sizoef�ֽ����ճ� һ��4����������8����������
 *
 * Ϊ��ͳһ�ֽڶ������⣬����һ�������һ�ֽڶ���(������)�������ֽڶ�����Խ�4�ֽڶ������8�ֽڶ���
 * ���麯��ʱ�����������ඨ��������vptr�麯����ָ�룺�ڲ������ݳ�Ա��
 * 3����Ա����ƫ��ֵ�Ĵ�ӡ
 * ��Ա����ƫ��ֵ�����������Ա�����ĵ�ַ��������׵�ַƫ�ƶ��٣�
 * �����麯����ʱ���麯����ָ����󶥲�4���ֽڡ���������m_iƫ��4���ֽ�

 29
 myobj.m_i = 009FF724
 myobj.m_j = 009FF728
 myobj.m_k = 009FF72C
 myobj.m_c = 009FF730
 myobj.m_n = 009FF731
 pmyobj->m_i = 00D448EC
 pmyobj->m_j = 00D448F0
 pmyobj->m_k = 00D448F4
 pmyobj->m_c = 00D448F8
 pmyobj->m_n = 00D448F9
 ************************************************
 ��ӡ��Ա����ƫ��ֵ------------
 MYACLS::m_i = 4//�麯����ָ��ռ��4���ֽڣ����Ե�һ�����������ĸ���ַ
 MYACLS::m_j = 8
 MYACLS::m_k = 12
 MYACLS::m_c = 16
 MYACLS::m_n = 17
 MYACLS::m_pria = 21
 MYACLS::m_prib = 25
 -------------------------
 25
 pmyobj->m_nƫ��ֵ = 17
 �밴���������. . .



 */

