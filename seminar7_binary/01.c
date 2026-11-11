#include <stdio.h>
#include <string.h>

int main() {
    unsigned char a[16] = {
        0x00, 0x10, 0x20, 0x30, 0x40, 0x50, 0x60, 0x70,
        0x80, 0x90, 0xA0, 0xB0, 0xC0, 0xD0, 0xE0, 0xF0
    };

    for(int i = 0; i < 16; i++) {
        printf("%02x ", a[i]);
    }
    printf("\n");

    for(int i = 0; i < 16; i++) {
        printf("%u ", a[i]);
    }
    printf("\n");

    for(int i = 0; i < 16; i++) {
        char p;
        if(a[i] >= 32 && a[i] <= 126) {
            p = a[i];
        } else {
            p = '.';
        }
        printf("Index: %02d Hex: 0x%02x ASCII: %c\n", i, a[i], p);
    }

    a[5] = 0xE5;

    memmove(&a[3], &a[0], 7);
    memmove(&a[0], &a[11], 5);
    memset(&a[5], 0, 6);

    printf("Итоговый массив: ");
    for(int i = 0; i < 16; i++) {
        printf("%02x ", a[i]);
    }
    printf("\n");

    return 0;
}
