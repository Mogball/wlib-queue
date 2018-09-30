#ifndef __WLIB_QUEUE_TESTS_H__
#define __WLIB_QUEUE_TESTS_H__

#include "Defines.h"

DEFINE_TEST(1) {
    tqueue_t queue;
    ASSERT_TRUE(queue.empty());
    ASSERT_TRUE(!queue.full());
    ASSERT_TRUE(0 == queue.size());
    ASSERT_TRUE(16 == queue.capacity());
    return true;
}

DEFINE_TEST(2) {
    tqueue_t queue;
    ASSERT_TRUE(queue.enqueue(10));
    ASSERT_TRUE(!queue.empty());
    ASSERT_TRUE(!queue.full());
    ASSERT_TRUE(1 == queue.size());
    ASSERT_TRUE(10 == queue.peek());
    ASSERT_TRUE(queue.dequeue());
    ASSERT_TRUE(queue.empty());
    ASSERT_TRUE(0 == queue.size());
    return true;
}

DEFINE_TEST(3) {
    tqueue_t queue;
    ASSERT_TRUE(queue.enqueue(10));
    ASSERT_TRUE(queue.enqueue(20));
    ASSERT_TRUE(!queue.empty());
    ASSERT_TRUE(!queue.full());
    ASSERT_TRUE(2 == queue.size());
    ASSERT_TRUE(10 == queue.peek());
    ASSERT_TRUE(queue.dequeue());
    ASSERT_TRUE(20 == queue.peek());
    ASSERT_TRUE(queue.dequeue());
    ASSERT_TRUE(queue.empty());
    ASSERT_TRUE(0 == queue.size());
    return true;
}

DEFINE_TEST(4) {
    tqueue_t queue;
    for (int i = 0; i < 16; i++) {
        ASSERT_TRUE(queue.enqueue(i));
    }
    ASSERT_TRUE(0 == queue.peek());
    ASSERT_TRUE(0 == queue.peek());
    ASSERT_TRUE(0 == queue.peek());
    ASSERT_TRUE(16 == queue.size());
    ASSERT_TRUE(queue.full());
    ASSERT_TRUE(0 == queue.peek());
    for (int i = 0; i < 16; i++) {
        ASSERT_TRUE(i == queue.peek());
        ASSERT_TRUE(queue.dequeue());
    }
    ASSERT_TRUE(queue.empty());
    return true;
}

DEFINE_TEST(5) {
    tqueue_t queue;
    for (int i = 0; i < 16; i++) {
        ASSERT_TRUE(queue.enqueue(i) == true);
    }
    ASSERT_TRUE(queue.peek() == 0);
    ASSERT_TRUE(queue.dequeue());
    ASSERT_TRUE(queue.peek() == 1);
    ASSERT_TRUE(queue.dequeue());
    ASSERT_TRUE(queue.peek() == 2);
    ASSERT_TRUE(queue.dequeue());
    ASSERT_TRUE(queue.enqueue(16) == true);
    ASSERT_TRUE(queue.enqueue(17) == true);
    ASSERT_TRUE(queue.enqueue(18) == true);
    ASSERT_TRUE(queue.full() == true);
    return true;
}

DEFINE_TEST(6) {
     tqueue_t queue;
     for (int i = 0; i < 16; i++) {
         ASSERT_TRUE(queue.enqueue(i) == true);
     }
     ASSERT_TRUE(queue.enqueue(16) == false);
     return true;
}

DEFINE_TEST(7) {
     tqueue_t queue;
     for (int i = 0; i < 16; i++) {
         ASSERT_TRUE(queue.enqueue(i) == true);
     }
     ASSERT_TRUE(queue.full() == true);
     for (int i = 0; i < 16; i++) {
         ASSERT_TRUE(queue.peek() == i);
         ASSERT_TRUE(queue.dequeue());
     }
     ASSERT_TRUE(queue.empty() == true);
     return true;
}

DEFINE_TEST(8) {
     tqueue_t queue;
     for (int i = 0; i < 16; i++) {
         ASSERT_TRUE(queue.enqueue(i) == true);
     }
     for (int i = 0; i < 10; i++) {
         ASSERT_TRUE(queue.peek() == i);
         ASSERT_TRUE(queue.dequeue());
     }
     for (int i = 0; i < 6; i++) {
         ASSERT_TRUE(queue.enqueue(i) == true);
     }
     for (int i = 0; i < 6; i++) {
         ASSERT_TRUE(queue.peek() == i + 10);
         ASSERT_TRUE(queue.dequeue());
     }
     ASSERT_TRUE(queue.peek() == 0);
     ASSERT_TRUE(queue.dequeue());
     ASSERT_TRUE(queue.peek() == 1);
     ASSERT_TRUE(queue.dequeue());
     ASSERT_TRUE(queue.peek() == 2);
     ASSERT_TRUE(queue.dequeue());
     return true;
}

DEFINE_TEST(9) {
     tqueue_t queue;
     for (int i = 0; i < 12; i++) {
         ASSERT_TRUE(queue.enqueue(i) == true);
     }
     for (int i = 0; i < 10; i++) {
         ASSERT_TRUE(queue.peek() == i);
         ASSERT_TRUE(queue.dequeue());
     }
     for (int i = 0; i < 4; i++) {
         ASSERT_TRUE(queue.enqueue(i) == true);
     }
     ASSERT_TRUE(queue.peek() == 10);
     ASSERT_TRUE(queue.dequeue());
     ASSERT_TRUE(queue.peek() == 11);
     ASSERT_TRUE(queue.dequeue());
     ASSERT_TRUE(queue.enqueue(5));
     ASSERT_TRUE(queue.enqueue(6));
     ASSERT_TRUE(queue.peek() == 0);
     ASSERT_TRUE(queue.dequeue());
     for (int i = 0; i < 11; i++) {
         ASSERT_TRUE(queue.enqueue(i));
     }
     ASSERT_TRUE(queue.full() == true);
     return true;
}

DEFINE_TEST(10) {
     tqueue_t queue;
     for (int i = 0; i < 7; i++) {
         ASSERT_TRUE(queue.enqueue(i) == true);
     }
     for (int i = 0; i < 5; i++) {
         ASSERT_TRUE(queue.peek() == i);
         ASSERT_TRUE(queue.dequeue());
     }
     for (int i = 0; i < 14; i++) {
         ASSERT_TRUE(queue.enqueue(i) == true);
     }
     ASSERT_TRUE(queue.full() == true);
     ASSERT_TRUE(queue.enqueue(20) == false);
     ASSERT_TRUE(queue.peek() == 5);
     ASSERT_TRUE(queue.dequeue());
     ASSERT_TRUE(queue.peek() == 6);
     ASSERT_TRUE(queue.dequeue());
     ASSERT_TRUE(queue.enqueue(14));
     ASSERT_TRUE(queue.enqueue(15));
     ASSERT_TRUE(queue.peek() == 0);
     ASSERT_TRUE(queue.dequeue());
     for (int i = 1; i < 16; i++) {
         ASSERT_TRUE(queue.peek() == i);
         ASSERT_TRUE(queue.dequeue());
     }
     ASSERT_TRUE(queue.empty() == true);
     return true;
}

#endif
