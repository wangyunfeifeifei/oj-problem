#include <cstdio>
#include <cmath>

typedef struct Point {
    double x;
    double y;

    double (*dist)(Point &, Point &);
} P;

double dist(Point &a, Point &b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

P NewPoint(double x, double y) {
    return P{x, y, dist};
}

int main() {
    double x;
    double y;
    P p[3];
    for (int i = 0; i < 3; i++) {
        scanf("%lf%lf", &x, &y);
        p[i] = NewPoint(x, y);
    }
    double sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += p[i].dist(p[i], p[(i + 1) % 3]);
    }
    printf("%.2lf\n", sum);
    return 0;
}
