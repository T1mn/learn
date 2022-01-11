#include <stdio.h>

int main(){
    int a = 2;
    int b = 3;
    int c = a + b;
#ifdef DEBUG
    std::printf("a+b=%2d", c);
#endif
}