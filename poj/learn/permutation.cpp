#include <algorithm>
using namespace std;

const int MAX_N = 100;

bool used[MAX_N];
int perm[MAX_N];

// 生成 {0, 1, 2, 3, ..., n-1}的n!中排列
void permutation1(int pos, int n) {
    if (pos == n) {
        /**
         * 这里可以写对perm的操作
         */
        return;
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            perm[pos] = i;
            used[i] = true;
            permutation1(pos+1, n);
            used[i] = false;
        }
    }
    return ;
}

int perm2[MAX_N];

void permutation2(int n) {
    for (int i = 0; i < n; i++) {
        perm2[i] = i;
    }
    do {
        // 这里写对perm2的操作
    } while (next_permutation(perm2, perm2 + n));

    return ;
}

