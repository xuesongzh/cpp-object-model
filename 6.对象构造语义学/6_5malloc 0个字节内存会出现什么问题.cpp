#include <iostream>
#include <vector>
#include <ctime>
#include<algorithm>

using namespace std;


/*
 *һ���ر�˵������C++�����ŵ���ͨ C++98/11/14/17���������������뵽���ſγ�����
 *����malloc������0���ֽ�
 *	���ֳ���Ա�����ֳ���Ա����������ֳ���Ա���ڲ������û�����׵Ķ������Բ�ȥ�ã�����һ�㲻���ô�
 *	���ֳ���Ա�����෴��������ϵͳû�б�ʲô�쳣���;��������÷�����ȷ�ģ�
 *	����malloc(0)���ص���һ����Ч���ڴ��ַ����Ҳ��Ҫȥ������ڴ棬��Ҫ�޸����ݣ�Ҳ��Ҫȥ����
 */


	void func()
	{
		//void *p = malloc(0); //new���õ�Ҳ��malloc������

		void *p = malloc(100); //new���õ�Ҳ��malloc������
							   //char *p = new char[0];
		char *q = (char *)p;
		strcpy_s(q, 100, "������һ������"); //���е��³�����ְ�����������
		free(p);


		int abc;
		abc = 1;
	}


int main()
{
	func();
	system("pause");
	return 1;
}



