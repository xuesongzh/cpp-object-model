#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

/*
 *malloc������0���ֽ�
 *����malloc(0)���ص���һ����Ч���ڴ��ַ����Ҳ��Ҫȥ������ڴ棬��Ҫ�޸����ݣ�Ҳ��Ҫȥ����
 */

void func() {
    // void *p = malloc(0);  //new���õ�Ҳ��malloc��char *p = new char[0]

    void *p = malloc(100);
    char *q = (char *)p;
    strcpy_s(q, 100, "������һ������");  //���е��³�����ְ�����������
    free(p);
}

int main() {
    func();
    system("pause");
    return 1;
}
