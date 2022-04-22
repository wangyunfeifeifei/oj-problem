#include <cstdio>

typedef struct {
    char name[10];
    int lang;
    int math;
    int eng;
    int total;
} Stu;

Stu highest;

int main() {
    int n;
    scanf("%d", &n);
    highest.total = -1;

    Stu stu;
    for (int i = 0; i < n; i++) {
        scanf("%s%d%d%d", stu.name, &stu.lang, &stu.math, &stu.eng);
        stu.total = stu.lang + stu.math + stu.eng;
        if (stu.total > highest.total) {
            highest = stu;
        }
    }
    printf("%s %d %d %d\n", highest.name, highest.lang, highest.math, highest.eng);
    return 0;
}
