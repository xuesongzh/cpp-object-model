#include<iostream>
#include<cstdlib>
#include<functional>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
	system("pause");
	return 0;
}
/*
* (1)��������
* vs2015������Ա������ʾ��
* cl.exe �������ӹ���
*	1.�л���cpp���ڵ�·��
*	2.E:\ProjectCode\��3���麯��\virtualFunction>cl /d1 reportSingleClassLayoutDerived 3_4���ؼ̳��麯�������.cpp
���� x86 �� Microsoft (R) C/C++ �Ż������� 19.00.24215.1 ��
��Ȩ����(C) Microsoft Corporation����������Ȩ����


3_4���ؼ̳��麯�������.cpp
D:\Microsoft Visual Studio 14.0\VC\INCLUDE\xlocale(341): warning C4530: ʹ���� C++ �쳣������򣬵�δ����չ�����塣��ָ
�� /EHsc

class Derived   size(8):
+---
0      | +--- (base class Base01)
0      | | {vfptr}
| +---
4      | +--- (base class Base02)
4      | | {vfptr}
| +---
+---

Derived::$vftable@Base01@:
| &Derived_meta
|  0
0      | &Base01::myVirtulFunction01
1      | &Derived::myVirtulFunction02
2      | &Derived::deriveVirtulFunction05
3      | &Derived::deriveVirtulFunction06

Derived::$vftable@Base02@:
| -4
0      | &Base02::myVirtulFunction03
1      | &Derived::myVirtulFunction04

Derived::myVirtulFunction02 this adjustor: 0
Derived::myVirtulFunction04 this adjustor: 4
Derived::deriveVirtulFunction05 this adjustor: 0
Derived::deriveVirtulFunction06 this adjustor: 0
D:\Microsoft Visual Studio 14.0\VC\INCLUDE\exception(359): warning C4577: ��δָ���쳣����ģʽ�������ʹ���� "noexcept"
����һ�������쳣ʱ��ֹ��ָ�� /EHsc
Microsoft (R) Incremental Linker Version 14.00.24215.1
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:3_4���ؼ̳��麯�������.exe
3_4���ؼ̳��麯�������.obj

linux  g++ -fdump-class-hierarchy -fsyntax-only �ļ�����.cpp����.class�ļ�


* (2)vptr vtbl����ʱ��
* vptrָ����ʲôʱ�򴴽������ģ���
*	vptr���Ŷ����ߣ����Զ���ʲôʱ�򴴽�������vptr��ʲôʱ�򴴽�������
*	ʵ���ϣ������������麯�����࣬�ڱ����ʱ�򣬱�����������صĹ��캯���й�������Ϊvptr��ֵ�Ĵ��롣
*	���Ǳ�����Ϊ�ڱ����ڼ����ӵĴ��롣
*	���������е�ʱ�����������Ĵ��룬�϶�Ҫִ�й��캯�������캯���и�vptrָ�븳ֵ��
*
*	vtbl�Ĵ����͸�ֵʱ������
*	ʵ���ϣ��麯�����Ǳ������ڱ����ڼ��Ϊÿ����ȷ�����˶�Ӧ���麯����vtbl�����ݡ�
*	Ȼ���ڱ����ڼ����Ӧ����Ĺ��캯������Ӹ�vptr��ֵ�Ĵ��롣
*	�����������е���������ʱ����ù��캯�������а� �麯�����ַ��ֵ���麯����ָ�롣
* (3)�������д����麯������麯���ڴ�ʾ��ͼ
* (4)
* (5)
* (6)(7)
*/
