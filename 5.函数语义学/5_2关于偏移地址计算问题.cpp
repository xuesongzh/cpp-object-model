#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AdvTeacher {
    char name[64];
    int age;
    int p;
    char* pName;
} AdvTeacher;

int main(void) {
    int i = 0;
    AdvTeacher t1;
    AdvTeacher* p = NULL;
    p = &t1;

    {
        int offset1 = (int)&(p->age) - (int)p;        //& (t1.age)�����age����ʵλ�õĵ�ַ
        int offset2 = (int)&(((AdvTeacher*)0)->age);  //��p-p=0  �����0��λ����age��ƫ����,�����0��p-p,�ƶ���0λ��������
                                                      //����(AdvTeacher *)���ͽ���0(p-p)��ʼ���ڴ�ռ��λ��
        printf("offset1:%d \n", offset1);             //�ѽṹ��Ԫ�ص��ڴ���䷽ʽӳ�䵽�ڴ�λ0��λ�ã�
        printf("offset2:%d \n", offset2);
    }

    printf("helloworld\n");
    system("pause");
    return 0;
}
/*
offset1:64
offset2:64
helloworld


�ܽ᣺����Լ�������һ��ͷ�ļ���������Ľṹ�����λ�ò�������޸�
��ı�ƫ�����Ĵ�С��
*/