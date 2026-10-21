#include <stdio.h>
#include <stdlib.h>

float* get_geometric_progression(float a, float r, int n){
        float* p = (float*)malloc(sizeof(float)*n);
        float st = a;
        for(int i = 0; i < n; i++){
                p[i] = st;
                st = st*r;
        }
        return p;
}


int main(){
        float* p = get_geometric_progression(1.0, 3.0, 10);
        for(int i = 0; i < 10; i++){
                printf("%f\n", p[i]);
        }
        free(p);
}
