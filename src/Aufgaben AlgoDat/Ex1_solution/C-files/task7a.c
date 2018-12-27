#include <math.h>

void drawLevyCurve(int iter, double r, int phi) {
    if (iter==0) {
        printf("(%f:%d)\n", r, phi);
    } else {
        drawLevyCurve(iter-1, r * sqrt(0.5), phi-45);
        drawLevyCurve(iter-1, r * sqrt(0.5), phi+45);
    }
}
