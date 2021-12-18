#include <stack>
#include <cassert>

using namespace std;

class MyStack2 {
private:
    stack<int> *stackData;
    stack<int> *stackMin;
public:
    MyStack2() {
        stackData = new stack<int>();
        stackMin = new stack<int>();
    }

    ~MyStack2() {
        delete stackData;
        delete stackMin;
    }

    void push(int newNum);

    int pop();

    int getMin();
};

void MyStack2::push(int newNum) {
    if (stackMin->empty())
        stackMin->push(newNum);
    else if (newNum < getMin())
        stackMin->push(newNum);
    else
        stackMin->push(stackMin->top());
    stackData->push(newNum);
}

int MyStack2::pop() {
    assert(!stackData->empty());
    stackMin->pop();
    int ret = stackData->top();
    stackData->pop();
    return ret;
}

int MyStack2::getMin() {
    assert(!stackMin->empty());
    return stackMin->top();
}
