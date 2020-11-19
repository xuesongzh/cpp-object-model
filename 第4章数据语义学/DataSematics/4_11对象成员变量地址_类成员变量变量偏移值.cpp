#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class MYACLS
{
public:
	int m_i;
	int m_j;
	int m_k;
};

void myfunc(int MYACLS::*mempoint, MYACLS &obj)
{
	obj.*mempoint = 260; //ע��д��
}

int main()
{
	//һ�������Ա�����ڴ��ַ����ָ��_�Ǹ�������ָ��
	MYACLS myobj;
	myobj.m_i = myobj.m_j = myobj.m_k = 0;
	printf("myobj.m_i = %p\n", &myobj.m_i); //����ĳ�Ա���������������ڴ��ַ�ġ�

	//���Ϸ����ڴ�
	MYACLS *pmyobj = new MYACLS();
	printf("pmyobj->m_i = %p\n", &pmyobj->m_i);
	printf("pmyobj->m_j = %p\n", &pmyobj->m_j);

	int *p1 = &myobj.m_i;
	int *p2 = &pmyobj->m_j;

	*p1 = 15;
	*p2 = 30;

	printf("p1��ַ=%p,p1ֵ=%d\n", p1, *p1);
	printf("p2��ַ=%p,p2ֵ=%d\n", p2, *p2);
	/*
	 myobj.m_i = 004FF8C0
	 pmyobj->m_i = 0070E438
	 pmyobj->m_j = 0070E43C
	 p1��ַ=004FF8C0,p1ֵ=15
	 p2��ַ=0070E43C,p2ֵ=30
	 */

	//������Ա������ƫ��ֵ����ָ�루�;��������û�й�ϵ��--���Ƕ����
	cout << "��ӡ��Ա����ƫ��ֵ----------------" << endl;
	printf("MYACLS::m_iƫ��ֵ = %d\n", &MYACLS::m_i); //��ӡƫ��ֵ�������õ�%d
	printf("MYACLS::m_jƫ��ֵ = %d\n", &MYACLS::m_j);
	//�ó�Ա����ָ������ӡƫ��ֵҲ���ԣ���д��
	//���Ҫ֪������Ա����ָ����߱���� ʵ�����Ǹ�ƫ��ֵ�����Ǹ�ʵ���ڴ��ַ����
	int MYACLS::*mypoint = &MYACLS::m_j;
	printf("MYACLS::m_jƫ�Ƶ�ַ = %d\n", mypoint);

	mypoint = &MYACLS::m_i; //����ע�⣬����ʹ��ʱֱ�������֣�����ʱ����Ҫ��MYACLS::
	printf("MYACLS::m_iƫ�Ƶ�ַ = %d\n", mypoint);
	/*
	 MYACLS::m_iƫ��ֵ = 0
	MYACLS::m_jƫ��ֵ = 4
	MYACLS::m_jƫ�Ƶ�ַ = 4
	MYACLS::m_iƫ�Ƶ�ַ = 0
	 */

	//����û��ָ���κ����ݳ�Ա������ָ��
	//ͨ�� һ�����������߶���ָ���߸�  ��Ա����ָ�� ������ĳ������ĳ�Ա������
	cout << "****************************" << endl;
	myobj.m_i = 13;
	myobj.*mypoint = 22;
	pmyobj->*mypoint = 19;

	myfunc(mypoint, myobj);
	myfunc(mypoint, *pmyobj);
	cout << "sizeof(mypoint) =" << sizeof(mypoint) << endl; //��Ա����ָ��Ҳ�Ǹ�4�ֽڣ�

	//���ۣ���Ա����ָ��ָ���Ա�����׵�ַ����000000000���㸳ֵΪ0������������1����Ϊ0xffff ffff
	int *ptest = 0;
	int MYACLS::*mypoint2;
	mypoint2 = 0; //��Ա����ָ�븳ֵΪ0�������������1
	mypoint2 = NULL; //0xffffffff
	printf("mypoint2 = %d\n", mypoint2);//-1

	//if(mypoint2 == mypoint) //��������һ����0��һ����-1
	int MYACLS::*mypoint10 = &MYACLS::m_i;
	if (mypoint == mypoint10) //������
	{
		cout << "����" << endl;
	}

	//mypoint2 += 1;//���������ü�
	//mypoint2++;
	//mypoint2 = ((&MYACLS::m_i) + 1);

	/*
	 * sizeof(mypoint) =4
		mypoint2 = -1
		����
	 */

	system("pause");

	return 1;
}

