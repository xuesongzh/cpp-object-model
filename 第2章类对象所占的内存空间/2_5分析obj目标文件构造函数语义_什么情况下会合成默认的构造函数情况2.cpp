#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;

class MBTXPARENT
{
public:
	MBTXPARENT()
	{
		cout << "ppppppppppppppppppppppp" << endl;
	}
};

class MBTX:public MBTXPARENT
{
public:
	int m_i;
	int m_j;
};

int main(void)
{
	MBTX mb;//����Ĺ��캯��������ϳɵĹ��캯������
	
	system("pause");
	return 0;
}
/*
* (1)���⣺������������Щ��Ҫ��ʱ��������Ǻϳ�Ĭ�ϵĹ��캯��������
* ���2�������ȱʡ���캯��������û���κι��캯��,��������������ʱ��
*	��Ϊ����ȱʡ�Ĺ��캯�������ã��������������ϳɳ�һ��Ĭ�ϵĹ��캯����
*	�ϳɵ�Ŀ����Ϊ���������е��ø���Ĺ��캯������ɸ����Ա�ĳ�ʼ��������
*	���仰˵��������Ϊ����ϳ�Ĭ�ϵĹ��캯�����������а�����룬�����丸���ȱʡ���캯����
*
*	ʹ��dumpbin���߲鿴���£�
		60501020 flags
		         Code
		         COMDAT; sym= "public: __thiscall MBTX::MBTX(void)" (??0MBTX@@QAE@XZ)
		         16 byte align
		         Execute Read

		RAW DATA #9
		  00000000: 55 8B EC 81 EC CC 00 00 00 53 56 57 51 8D BD 34  U.��.����...SVWQ.?4
		  00000010: FF FF FF B9 33 00 00 00 B8 CC CC CC CC F3 AB 59  ???13...?����������?Y
		  00000020: 89 4D F8 8B 4D F8 E8 00 00 00 00 8B 45 F8 5F 5E  .M?.M?��.....E?_^
		  00000030: 5B 81 C4 CC 00 00 00 3B EC E8 00 00 00 00 8B E5  [.?��...;����.....?
		  00000040: 5D C3                                            ]?

		RELOCATIONS #9
		                                                Symbol    Symbol
		 Offset    Type              Applied To         Index     Name
		 --------  ----------------  -----------------  --------  ------
		 00000027  REL32                      00000000        88  ??0MBTXPARENT@@QAE@XZ (public: __thiscall MBTXPARENT::MBTXPARENT(void))


* (2)
* (3)
* (4)
* (5)
* (6)(7)
*/
