#include <stdio.h>
#include <math.h>

int solve_quadratic(double a, double b, double c, double* px1, double* px2){
        double desc;
        desc = b*b - 4*a*c;
        if(desc < 0){
                return 0;
}
        else if(-1*pow(10, -10) <= desc <= pow(10, -10)){
                *px1 = (-1*b)/(2*a);
                return 1;
}
        else{
                *px1 = (-1*b + pow(desc, 0.5))/(2*a);
                *px2 = (-1*b - pow(desc, 0.5))/(2*a);
                return 2;

}
}

int main(){}
