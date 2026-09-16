#include <stdio.h>

int count_even(int array[], int n){
        int ans = 0;
        for(int i = 0; i < n; i++){
                if(array[i]%2 == 0) ans += 1;
}
        return ans;
}
int main(){
        int array1[] = {1, 2, 3, 4, 5};
        int size1 = 5;
        printf("%i", count_even(array1, size1));

        int array2[] = {10, 20, 30, 40};
        int size2 = 4;
        printf("%i", count_even(array2, size2));

        int array3[] = {10, 1};
        int size3 = 2;
        printf("%i", count_even(array3, size3));
}
