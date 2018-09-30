#include <wlib/queue>
#include <string>
#include <cassert>
#include <cstdio>

int main(void) {
    wlp::queue<std::string, 16> queueString;
    std::string value("value");
    assert(0 != value.size());
    queueString.enqueue(value);
    assert(0 != value.size());
    assert(0 != queueString.peek().size());
    queueString.enqueue(std::move(value));
    assert(0 == value.size());
    assert(0 != queueString.peek().size());

    assert(2 == queueString.size());
    assert("value" == queueString.peek());
    assert(queueString.dequeue());
    assert(queueString.dequeue());
    assert(!queueString.dequeue());
    queueString.peek(); // should not crash

    printf("Test passed\n");
}
