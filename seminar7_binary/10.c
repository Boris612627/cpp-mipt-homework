#include <stdio.h>
#include <math.h>

int main() {
    int w = 500;
    int h = 500;
    double k = 255.0;
    const char* names[5] = {"func_1.ppm", "func_2.ppm", "func_3.ppm", "func_4.ppm", "func_5.ppm"};

    for (int f_num = 1; f_num <= 5; f_num++) {

        FILE* f = fopen(names[f_num - 1], "w");
        if (f == NULL) return 1;

        fprintf(f, "P3\n");
        fprintf(f, "%d %d\n", w, h);
        fprintf(f, "255\n");

        for (int py = 0; py < h; py++) {
            for (int px = 0; px < w; px++) {

                double x = (double)px / (w - 1) * 2.0 - 1.0;
                double y = 1.0 - (double)py / (h - 1) * 2.0;
                double val = 0.0;

                if (f_num == 1) {
                    val = k * fabs(x * y);
                }
                else if (f_num == 2) {
                    val = k * fabs(sin(10.0 * (x*x + y*y)));
                }
                else if (f_num == 3) {
                    val = k * fabs(sin(5000.0 * (x*x + y*y)));
                }
                else if (f_num == 4) {
                    val = k * fabs(cos(10.0 * x) * sin(10.0 * y));
                }
                else if (f_num == 5) {
                    val = (k / 2.0) * fabs(sin(3.0 / (0.1 + fabs(x))) + sin(3.0 / (0.1 + fabs(y))));
                }

                int c = (int)val;
                if (c > 255) c = 255;
                if (c < 0) c = 0;

                fprintf(f, "%d %d %d ", c, c, c);
            }
            fprintf(f, "\n");
        }
        fclose(f);
    }

    return 0;
}
