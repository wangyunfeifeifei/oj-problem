#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 试题：洛谷P3378

class Heap {
 public:
  void push(int i) {
    data_.push_back(i);
    shift_up(data_.size() - 1);
  }
  int top() { return data_[0]; }
  void pop() {
    swap(data_[0], data_.back());
    data_.pop_back();
    shift_down(0);
  }

 private:
  void shift_up(int i) {
    while (i > 0 && data_[(i - 1) / 2] > data_[i]) {
      // 父节点大于它
      swap(data_[(i - 1) / 2], data_[i]);
      i = (i - 1) / 2;
    }
  }
  void shift_down(int i) {
    while (2 * i + 1 < data_.size()) {
      // 如果有子节点
      int j = 2 * i + 1;
      if (j + 1 < data_.size() && data_[j + 1] < data_[j]) {
        j++;
      }
      if (data_[j] < data_[i]) {
        swap(data_[i], data_[j]);
      }
      i = j;
    }
  }

 private:
  vector<int> data_;
};

int main() {
  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  Heap h;
  for (int i = 0; i < n; i++) {
    int op;
    cin >> op;
    if (op == 1) {
      int t;
      cin >> t;
      h.push(t);
    } else if (op == 2) {
      cout << h.top() << endl;
    } else if (op == 3) {
      h.pop();
    }
  }
  return 0;
}
