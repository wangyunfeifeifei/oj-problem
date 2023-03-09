#include <iostream>
#include <string>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  string digits[] = {"zero",    "one",     "two",       "three",    "four",
                     "five",    "six",     "seven",     "eight",    "nine",
                     "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
                     "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
                     "twenty"};
  string shis[] = {"", "", "twenty", "thirty", "forty", "fifty"};
  int h, m;
  cin >> h >> m;
  if (h <= 20) {
    cout << digits[h] << " ";
  } else {
    cout << digits[20] << " " << digits[h % 20] << " ";
  }
  if (m == 0) {
    cout << "o'clock" << endl;
  } else if (m <= 20) {
    cout << digits[m] << endl;
  } else {
    cout << shis[m / 10] << " " << digits[m % 10] << endl;
  }
  return 0;
}
