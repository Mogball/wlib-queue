#ifndef __WLIB_QUEUE_H__
#define __WLIB_QUEUE_H__

#include <wlib/utility>
#include <stddef.h>

namespace wlp {

    template<typename E, size_t Size>
    class queue {
        static_assert(Size > 0, "Queue must have positive capacity");

    public:
        queue() noexcept:
            m_head(0),
            m_tail(0),
            m_size(0) {}

        ~queue() noexcept {}

        bool full() const {
            return Size == m_size;
        }

        bool empty() const {
            return 0 == m_size;
        }

        size_t size() const {
            return m_size;
        }

        size_t capacity() const {
            return Size;
        }

        /**
         * Enqueue element. Returns true if insertion occurred.
         */
        template<typename V>
        bool enqueue(V &&v) {
            if (full()) {
                return false;
            }
            m_data[m_tail] = wlp::forward<V>(v);
            m_tail = (m_tail + 1) % Size;
            ++m_size;
            return true;
        }

        /**
         * Dequeue element. Returns true if removal occurred.
         */
        bool dequeue() {
            if (empty()) {
                return false;
            }
            m_head = (m_head + 1) % Size;
            --m_size;
            return true;
        }

        E &peek() {
            return m_data[m_head];
        }

        const E &peek() const {
            return m_data[m_head];
        }

        queue(const queue<E, Size> &) = delete;
        queue(queue<E, Size> &&) = delete;
        queue<E, Size> &operator=(const queue<E, Size> &) = delete;
        queue<E, Size> &operator=(queue<E, Size> &&) = delete;

    private:
        size_t m_head;
        size_t m_tail;
        size_t m_size;
        E m_data[Size];
    };

}

#endif
