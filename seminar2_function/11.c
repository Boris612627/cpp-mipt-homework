#include <stdio.h>

#define MAX 100

void multiply(float a[MAX][MAX], float b[MAX][MAX], float c[MAX][MAX], int n){
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        c[i][j] = 0;
                        for(int k = 0; k < n; k++){
                                c[i][j] += a[i][k]*b[k][j];
}
}
}
}

int main(){
        int n;
        scanf("%i", &n);
        float a[MAX][MAX];
        for(int i =0; i < n; i++)
                for(int j = 0; j < n; j++)
                        scanf("%f", &a[i][j]);
        scanf("%i", &n);
        float b[MAX][MAX];
        for(int i =0; i < n; i++)
                for(int j = 0; j < n; j++)
                        scanf("%f", &b[i][j]);
        float c[MAX][MAX] = {0};
        multiply(a, b, c, n);
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        printf("%f ", c[i][j]);
}
                printf("\n");
}
}

