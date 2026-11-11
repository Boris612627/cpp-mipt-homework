#include <stdio.h>

int main(int argc, char* argv[]) {

    FILE* f = fopen(argv[1], "rb");
    if (f == NULL) {
        printf("Файл не открывается\n");
        return 1;
    }

    fseek(f, 0, SEEK_END);
    long size = ftell(f);

    if (size < 3) {
        printf("Меньше 3 байт\n");
        fclose(f);
        return 1;
    }

    fseek(f, -3, SEEK_END);

    for (int i = 0; i < 3; i++) {
        int c = fgetc(f);
        printf("%02x ", c);
    }
    printf("\n");

    fclose(f);
    return 0;
}
