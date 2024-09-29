#include <math.h>
#include <stdio.h>

#define PI 3.14159265358979323846

// Agnesi
double verziere(double x) { return ((1.0 / (1 + pow(x, 2)))); }

// Bernoulli
double lemniscate(double x) { return sqrt(sqrt(1 + 4 * pow(x, 2)) - pow(x, 2) - 1); }

// Квадратичная гипербола
double hyperbola(double x) { return (1.0 / pow(x, 2)); }

int main() {
    double x;
    double step = (2 * PI) / 41;

    for (int i = 20; i >= 0; i--) {
        for (int j = 0; j < 41; j++) {
            double x = -PI + j * step; 
            double y1 = verziere(x);
            double y2 = lemniscate(x);
            double y3 = hyperbola(x);

            
            int y1_pos = (int)((1.0 - y1) * 20);
            int y2_pos = (int)((1.0 - y2) * 20);
            int y3_pos = (int)((1.0 - y3) * 20);

            if (i == y1_pos) {
                printf("*"); 
            } else if (i == y2_pos) {
                printf("*"); 
            } else if (i == y3_pos) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n"); 
    }
    
    return 0;
}
