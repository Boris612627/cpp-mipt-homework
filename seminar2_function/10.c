#include <stdio.h>

#define MAX 100

void assign(int a[MAX][MAX], int b[MAX][MAX], int n){
        for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                        a[i][j] = b[i][j];
}
}
}
