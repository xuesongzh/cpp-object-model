#include <iostream>
#include <vector>
#include <ctime>

using namespace std;


	//һ�����������б�������ѭ�������Ż�	
	//debug,release
	//��1���Ż�ѭ������ѭ���Ż���1����䣻
	//��2���ڱ����ڼ䣬������Ҳ����������������Щ����������ڱ����ڼ���ܸ㶨��

	__int64 mytest(int mv)
	{
		__int64 icout = 0;
		for (int i = 1; i < 1000000; i++)
		{
			icout += 1;
			/*if (i == 10000 && mv == 999)//��һ���߼��ж�--�⼸�д���ʱΪ�˷�ֹ�������Ż���ֱ�Ӽ��ܺ�(��������ǰ�Ѻ�ֵ���������)
			{
				printf("------\n");
			}*/
		}
		//icout += ѭ�����ٴ�֮��ĺ�ֵ
		return icout;
	}

	void func()
	{
		clock_t start, end;
		__int64 mycout = 1;
		start = clock();
		for (int i = 0; i <= 1000; i++)
		{
			//mycout += mytest(i); //���̶�����ʱ�������������ֲ����̶��ĺ���������Ϊһ�ֲ���ı��ʽ
			mycout += mytest(6);
		}
		//�Ż���һ����䣺mycout += ѭ��1000�εĺ�ֵ
		end = clock();
		cout << " ��ʱ(���룩��" << end - start << endl;
		cout << " mycout:" << mycout << endl;
	}


int main()
{
	func();
	/*
	 *debug�汾��
	    ��ʱ(���룩��2653
		mycout:1000999000
	Released�汾��
		 ��ʱ(���룩��0
		mycout:1000999000
	 */
	
	system("pause");
	return 1;
}



