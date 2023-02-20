#include <iostream>
#include <string>
using namespace std;

int main() {
  string nums[] = {"ling ", "yi ",  "er ", "san ", "si ",
                   "wu ",   "liu ", "qi ", "ba ",  "jiu "};
  string unit[] = {"", "shi ", "bai ", "qian "};  // 万以内的不用特殊处理
  string bigUnit[] = {"wan ", "yi "};             // 万和亿特殊处理
  string s;
  cin >> s;
  if (s == "0") {
    cout << "ling" << endl;
    return 0;
  }
  int len = s.size();
  int rest = len - 1;  // 第0位记为最高位，第len-1位记为第0位，rest指代当前位置
  string ans;
  for (int i = 0; i < len; i++, rest--) {
    int j = s[i] - '0', k = rest % 4;  // k为每四位中的哪一位
    if (j == 0) {
      // x0x要读零
      // xxx0万xxxx 不读零
      // x00000x只读最后一位零
      if (k != 0 && s[i + 1] != '0') ans += nums[0];
    } else if (j == 1) {
      if (k != 1) ans += nums[1];  // x10万/亿 直接读作十，不读1
      ans += unit[k];
    } else {
      ans += nums[j];
      ans += unit[k];
    }
    // 处理万和亿
    if (rest == 4) ans += bigUnit[0];
    if (rest == 8) ans += bigUnit[1];
  }
  cout << ans << endl;
  return 0;
}
