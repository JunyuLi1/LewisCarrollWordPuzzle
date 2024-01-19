#ifndef __PROJ5_PRIORITY_QUEUE_HPP
#define __PROJ5_PRIORITY_QUEUE_HPP

#include <cstddef>

namespace shindler::ics46::project5 {

template <typename T>
class PriorityQueue {
   private:
    // fill in private member data here

   public:
     PriorityQueue();

     ~PriorityQueue();

    // In general, a copy constructor and assignment operator
    // are good things to have.
    // For this quarter, I am not requiring these.
    //	PriorityQueue(const PriorityQueue & pq);
    //	PriorityQueue & operator=(const PriorityQueue & pq);
    // You do not need to implement these
    PriorityQueue(const PriorityQueue &) = delete;
    PriorityQueue(PriorityQueue &&) = delete;
    PriorityQueue &operator=(const PriorityQueue &) = delete;
    PriorityQueue &operator=(PriorityQueue &&) = delete;

    [[nodiscard]] size_t size() const noexcept;
    [[nodiscard]] bool empty() const noexcept;

    void push(const T& elem);

    // Note:  no non-const version of this one.  This is on purpose because
    // the interior contents should not be able to be modified due to the
    // heap property.  This isn't true of all priority queues but
    // for this project, we will do this.
    // min() should throw std::out_of_range if the queue
    // is empty.
    [[nodiscard]] const T& min() const;

    // popMin() should throw std::out_of_range if the queue
    // is empty.
    void popMin();
};

template <typename T>
PriorityQueue<T>::PriorityQueue() {
    // TODO: Implement this
}

template <typename T>
PriorityQueue<T>::~PriorityQueue() {
    // TODO: Implement this
}

template <typename T>
size_t PriorityQueue<T>::size() const noexcept {
    // TODO: Implement this
    return {};
}

template <typename T>
bool PriorityQueue<T>::empty() const noexcept {
    // TODO: Implement this
    return {};
}

template <typename T>
void PriorityQueue<T>::push(const T& elem) {
    // TODO: Implement this
}

template <typename T>
const T& PriorityQueue<T>::min() const {
    // TODO: Implement this
    return {};
}

template <typename T>
void PriorityQueue<T>::popMin() {
    // TODO: Implement this
}

}  // namespace shindler::ics46::project5

#endif
