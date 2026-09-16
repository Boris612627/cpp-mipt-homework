#include <stdio.h>

void reverse(int array[], int size){
        int j;
        int a;
        for(int i = 0; i < size/2; i++){
                j = size - i -1;
                a = array[i];
                array[i] = array[j];
                array[j] = a;
}
}

int main(){
        int array1[] = {10, 20, 30, 40, 50};
        int size1 = 5;
        reverse(array1, size1);
        for(int i =0; i < size1; i++){
                printf("%i ", array1[i]);

}
        printf("\n");

        int array2[] = {60, 20, 80, 10};
        int size2 = 4;
        reverse(array2, size2);
        for(int i =0; i < size2; i++){
                printf("%i ", array2[i]);

}
        printf("\n");

}
