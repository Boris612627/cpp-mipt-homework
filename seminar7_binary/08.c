#include <stdio.h>

int main() {
    int w = 600;
    int h = 400;
    int cx = 300;
    int cy = 200;
    int r = 100;

    FILE* f = fopen("flag.ppm", "w");
    if (f == NULL) return 1;

    fprintf(f, "P3\n");
    fprintf(f, "%d %d\n", w, h);
    fprintf(f, "255\n");

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            int b = 0;
            int dx = x - cx;
            int dy = y - cy;

            if (dx * dx + dy * dy <= r * r) {
                b = 1;
            }

            if (b) {
                fprintf(f, "190 0 41 ");
            } else {
                fprintf(f, "255 255 255 ");
            }
        }
        fprintf(f, "\n");
    }

    fclose(f);
    return 0;
}
