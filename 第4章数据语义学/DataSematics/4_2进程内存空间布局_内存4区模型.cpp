#include <iostream>
#include <ctime>
#include <stdio.h>
#include<cstdlib>
using namespace std;

int *ptest = new int(120);
int g1;//δ��ʼ����ȫ�������߳�ʼ��Ϊ0��ȫ��������.BSS��(����ϵͳ�Զ���û�г�ʼ���ı����Զ���ֵ0)
int g2;

int g3 = 12;//��ʼ���������ݶ�
int g4 = 32;
int g5;
int g6 = 0;
static int g7;
static int g8 = 0;
static int g9 = 10;
void mygfunc()
{
	return;
}

//����һ����
class MYACLS
{
public:
	int m_i;
	static int m_si; //�������Ƕ��壬��������ڴ�ռ�
	int m_j;
	static int m_sj;
	int m_k;
	static int m_sk;
	//static void myclsfunc() {}
};
int MYACLS::m_sj = 0; //����Ƕ��壻��ľ�̬��Ա����Ҳ��洢�����ݶ�

int main()
{
	


	int i = 7;//ջ�з�����ڴ�ÿ�ζ������ڴ棬��ַÿ�θı�
	printf("i��ַ=%p\n", &i);


	printf("ptest��ַ=%p\n", &ptest);
	printf("g1��ַ=%p\n", &g1);
	printf("g2��ַ=%p\n", &g2);
	printf("g3��ַ=%p\n", &g3);
	printf("g4��ַ=%p\n", &g4);
	printf("g5��ַ=%p\n", &g5);
	printf("g6��ַ=%p\n", &g6);
	printf("g7��ַ=%p\n", &g7);
	printf("g8��ַ=%p\n", &g8);
	printf("g9��ַ=%p\n", &g9);
	printf("MYACLS::m_sj��ַ=%p\n", &(MYACLS::m_sj));

	printf("mygfunc()��ַ=%p\n", mygfunc);
	printf("main()��ַ=%p\n", main);


	cout << (void*)mygfunc << endl;
	
	system("pause");
	return 0;
}
/*
 * 4_2�����ڴ�ռ䲼��--�ڴ�����iģ��
 * ��ͬ���������ڴ��л��в�ͬ�� ����ʱ��������λ��
 * ������һ����ִ���ļ�ʱ������ϵͳ�ͻ�������ִ���ļ����ص��ڴ棻��ʱ������һ������ĵ�ַ�ռ䣨�ڴ�ռ䣩
 * 
 * linux�и�nm����:�ܹ��г���ִ���ļ��е�ȫ�ֱ�����ŵĵ�ַ
 *	1.�ȱ������ִ���ļ�
 *	2.nm ��ִ���ļ�����
 *
 i��ַ=009DF718
 ptest��ַ=008CB300
 g1��ַ=008CB2E8
 g2��ַ=008CB2EC
 g3��ַ=008CB000
 g4��ַ=008CB004
 g5��ַ=008CB2F0
 g6��ַ=008CB2F4
 g7��ַ=008CB304
 g8��ַ=008CB2F8
 g9��ַ=008CB008
 MYACLS::m_sj��ַ=008CB2FC
 mygfunc()��ַ=008C11DB
 main()��ַ=008C132F
 008C11DB
 �밴���������. . .


 */

