#include <cstdio>

#define N 100005

struct Person {
    int dir;
    char name[11];
} P[N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d%s", &P[i].dir, P[i].name);
    }
    int d, k;
    int now = 0;
    while (m--) {
        scanf("%d%d", &d, &k);
        if (d == P[now].dir) now = (now - k + n) % n;
        else now = (now + k) % n;
    }
    printf("%s\n", P[now].name);
    return 0;
}

