#include <cstring>
#include <iostream>
using namespace std;

const int N = 1e5 + 3;  // 大于1e5的第一个质数

int h[N], e[N], ne[N];
int idx = 0;
int n;

void insert(int x) {
  int k = (x % N + N) % N;
  e[idx] = x;
  ne[idx] = h[k];
  h[k] = idx++;
}

bool find(int x) {
  int k = (x % N + N) % N;
  for (int i = h[k]; i != -1; i = ne[i]) {
    if (e[i] == x) return true;
  }
  return false;
}

int main() {
  scanf("%d", &n);
  memset(h, -1, sizeof h);
  char op[2];
  int x;
  while (n--) {
    scanf("%s%d", op, &x);
    if (*op == 'I') {
      insert(x);
    } else {
      if (find(x))
        printf("Yes\n");
      else
        printf("No\n");
    }
  }

  return 0;
}
