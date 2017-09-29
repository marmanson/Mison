#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    for(int i=0;i<64; i++) {
        printf("sta = sta | ((i64(!(str[index + %d] ^ ch))) << %d);\n", i, 63-i);
    }
    return 0;
}