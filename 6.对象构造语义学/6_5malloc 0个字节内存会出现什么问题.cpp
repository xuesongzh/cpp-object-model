#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

/*
 *malloc来分配0个字节
 *即便malloc(0)返回的是一个有效的内存地址，你也不要去动这个内存，不要修改内容，也不要去读；
 */

void func() {
    // void *p = malloc(0);  //new调用的也是malloc，char *p = new char[0]

    void *p = malloc(100);
    char *q = (char *)p;
    strcpy_s(q, 100, "这里是一个测试");  //这行导致程序出现暗疾和隐患；
    free(p);
}

int main() {
    func();
    system("pause");
    return 1;
}
