#include <cstdio>

struct Student {
    int no;
    int score;
    int extra;
} Stu[1001];

bool Excellent(Student s) {
    return s.score + s.extra > 140 &&
           0.7 * s.score + 0.3 * s.extra >= 80;
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &Stu[i].no, &Stu[i].score, &Stu[i].extra);
        if (Excellent(Stu[i])) {
            printf("Excellent\n");
        } else {
            printf("Not excellent\n");
        }
    }
    return 0;
}
