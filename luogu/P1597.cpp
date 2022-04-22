#include <cstdio>
#include <cstring>
#include <cstdlib>

int main() {
    char str[256];
    scanf("%s", str);
    char *stmt[100];
    char *tok = strtok(str, ";");
    int n = 0;
    while (tok) {
        stmt[n++] = tok;
        tok = strtok(NULL, ";");
    }
    int ans[3] = {0};
    for (int i = 0; i < n; i++) {
        char *l = strtok(stmt[i], ":=");
        char *r = strtok(NULL, ":=");
        size_t idx = l[0] - 'a';
        if (strcmp(r, "a") == 0) {
            ans[idx] = ans[0];
        } else if (strcmp(r, "b") == 0) {
            ans[idx] = ans[1];
        } else if (strcmp(r, "c") == 0) {
            ans[idx] = ans[2];
        } else {
            ans[idx] = atoi(r);
        }
    }
    printf("%d %d %d\n", ans[0], ans[1], ans[2]);
    return 0;
}
