#include <stdio.h>

void mult2_1(int* p, size_t n){
        for(int i = 0; i < n; i++){
                *(p+i) *= 2;
}
}

void mult2_2(int* p, size_t n){
        for(int i = 0; i < n; i++){
                p[i] *= 2;
}
}

int main(){}
