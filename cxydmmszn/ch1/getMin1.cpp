/**
 * 设计一个有getMin功能的栈
 */
#include <stack>
#include <cassert>

using namespace std;

class MyStack1 {
private:
    stack<int> stackData;
    stack<int> stackMin;
public:
    void push(int newNum);

    int pop();

    int getMin();
};

void MyStack1::push(int newNum) {
    if (stackMin.empty()) {
        stackMin.push(newNum);
    } else if (newNum <= getMin()) {
        stackMin.push(newNum);
    }
    stackData.push(newNum);

}

int MyStack1::pop() {
    assert(!stackData.empty());
    int ret = stackData.top();
    stackData.pop();
    if (ret == getMin())
        stackMin.pop();

    return ret;
}

int MyStack1::getMin() {
    assert(!stackMin.empty());
    return stackMin.top();
}
