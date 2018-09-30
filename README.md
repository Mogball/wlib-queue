# wlib-queue

Lightweight static queue implementation.

## Usage

```bash
wio install wlib-queue
```

And in code

```c++
wlp::queue<int, 32> intQueue;
intQueue.enqueue(25);
int front = intQueue.peek();
intQueue.dequeue();
```

Calling `peek` on an empty queue will return
an erroneous value.
