#include <stdio.h>

void cube(float* px){
        *px = (*px)*(*px)*(*px);
}

int main(){
        float a = 10;
        cube(&a);
        printf("%f", a);
}

