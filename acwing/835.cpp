#include <iostream>
using namespace std;

const int N = 1e5 + 10;
// son[N][26]代表trie树
// cnt[N]表示节点的值
// idx表示当前开辟了多少节点
// 0 既是根节点，又是空节点
int son[N][26] = {0}, cnt[N] = {0}, idx = 0;

void insert(char str[]) {
  int p = 0;  // 根节点
  for (int i = 0; str[i]; i++) {
    int u = str[i] - '0';
    if (son[p][u] == 0) {
      // 该节点对应子节点为空
      // 创建子节点
      son[p][u] = ++idx;
    }
    p = son[p][u];
  }
  cnt[p]++;  // 该节点的值加一，本题中，=0就是非叶节点
}

int query(char str[]) {
  int p = 0;
  for (int i = 0; str[i]; i++) {
    int u = str[i] - '0';
    if (son[p][u] == 0) return 0;
    p = son[p][u];
  }
  return cnt[p];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  char op;
  char str[N];
  while (n--) {
    cin >> op >> str;
    if (op == 'I')
      insert(str);
    else
      printf("%d\n", query(str));
  }
  return 0;
}
