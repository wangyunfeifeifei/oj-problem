#include <cstdio>
#include <vector>

using namespace std;

int main() {
    vector<int> vec;
    int n;
    scanf("%d", &n);
    int x;
    while (scanf("%d", &x) != EOF) {
        vec.push_back(x);
    }
    int t = n;
    int cur = 0;
    for (int k: vec) {
        while (k--) {
            printf("%d", cur);
            t--;
            if (t == 0) {
                printf("\n");
                t = n;
            }
        }
        cur = !cur;
    }

    return 0;
}
