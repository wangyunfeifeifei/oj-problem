#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/**
 * @brief 字符串匹配
 *
 * @param haystack 主串
 * @param needle 模式串
 * @return int 匹配位置
 */
int strStr(string haystack, string needle) {
  int m = needle.size();
  int n = haystack.size();
  unordered_map<char, int> mov;
  for (int i = 0; i < m - 1; i++) {
    mov[needle[i]] = m - i - 1;
  }
  int i = m - 1;
  while (i < n) {
    int cnt = 0;
    for (int j = m - 1; j >= 0 && needle[j] == haystack[i + j - m + 1]; j--) {
      cnt++;
    }
    if (cnt == m) {
      return i - m + 1;
    }
    if (mov.count(haystack[i]) != 0) {
      i += mov[haystack[i]];
    } else {
      i += m;
    }
  }

  return -1;
}

int main() {
  string a = "sadbutsad";
  string b = "sad";
  cout << strStr(a, b) << endl;

  return 0;
}
