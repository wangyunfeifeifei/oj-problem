#include <stack>
#include <cassert>

using namespace std;

class TwoStackQueue {
private:
    stack<int> *stackPush;
    stack<int> *stackPop;

public:
    TwoStackQueue();

    ~TwoStackQueue();

    void add(int pushInt);

    int poll();

    int peek();
};

TwoStackQueue::TwoStackQueue() {
    stackPush = new stack<int>;
    stackPop = new stack<int>;
}

TwoStackQueue::~TwoStackQueue() {
    delete stackPop;
    delete stackPush;
}

void TwoStackQueue::add(int pushInt) {
    stackPush->push(pushInt);
}

int TwoStackQueue::poll() {
    assert(!stackPop->empty() || !stackPush->empty());
    if (stackPop->empty()) {
        while (!stackPush->empty()) {
            stackPop->push(stackPush->top());
            stackPush->pop();
        }
    }
    int ret = stackPop->top();
    stackPop->pop();
    return ret;
}

int TwoStackQueue::peek() {
    assert(!stackPop->empty() || !stackPush->empty());
    if (stackPop->empty()) {
        while (!stackPush->empty()) {
            stackPop->push(stackPush->top());
            stackPush->pop();
        }
    }
    return stackPop->top();
}
