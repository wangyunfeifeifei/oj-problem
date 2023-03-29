#include <stdlib.h>

#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int m;
int head, e[N], ne[N], idx;

void init() {
  head = -1;
  idx = 0;
}

void add_to_head(int x) {
  e[idx] = x;
  ne[idx] = head;
  head = idx;
  idx++;
}

// 下标k后面插入
void add(int k, int x) {
  e[idx] = x;
  ne[idx] = ne[k];
  ne[k] = idx;
  idx++;
}

// 删除下标k后面的
void remove(int k) { ne[k] = ne[ne[k]]; }

int main() {
  freopen("input.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin >> m;
  char op;
  int k, x;

  init();

  while (m--) {
    cin >> op;
    if (op == 'H') {
      cin >> x;
      add_to_head(x);
    } else if (op == 'D') {
      cin >> k;
      if (k == 0) {
        head = ne[head];
      } else {
        remove(k - 1);
      }
    } else if (op == 'I') {
      cin >> k >> x;
      add(k - 1, x);
    }
  }
  int cur = head;
  while (cur != -1) {
    cout << e[cur] << ' ';
    cur = ne[cur];
  }
  return 0;
}
