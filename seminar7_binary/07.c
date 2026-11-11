#include <stdio.h>

int main(int argc, char* argv[]) {

    FILE* f = fopen(argv[1], "rb");
    if (f == NULL) {
        printf("Файл не открывается\n");
        return 1;
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    
    printf("Размер: %ld байт\n", size);

    fclose(f);
    return 0;
}
