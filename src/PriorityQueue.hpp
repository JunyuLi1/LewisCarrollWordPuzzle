#ifndef __PROJ5_PRIORITY_QUEUE_HPP
#define __PROJ5_PRIORITY_QUEUE_HPP

#include <array>
#include <cstddef>
#include <stdexcept>
#include <type_traits>
#include <vector>

namespace shindler::ics46::project5 {

template <typename T>
class PriorityQueue {
   private:
    // fill in private member data here
    std::vector<T> min_heap;

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
    return min_heap.size();
}

template <typename T>
bool PriorityQueue<T>::empty() const noexcept {
    return min_heap.empty();
}

template <typename T>
void PriorityQueue<T>::push(const T& elem) {
    min_heap.push_back(elem);
    size_t node_index = size()-1;
    while(node_index>0)
    {
        size_t paraent_index = (node_index-1) /2;
        if(min_heap[node_index]<min_heap[paraent_index]){
            std::swap(min_heap[node_index], min_heap[paraent_index]);
            node_index = paraent_index;
        }
        else {
            break;
        }
    }
}

template <typename T>
const T& PriorityQueue<T>::min() const {
    if(empty())
    {
        throw std::out_of_range("Queue is empty");
    }
    return min_heap[0];
}

template <typename T>
void PriorityQueue<T>::popMin() {
    if(empty())
    {
        throw std::out_of_range("Queue is empty");
    }
    std::swap(min_heap[0],min_heap[min_heap.size()-1]);
    min_heap.pop_back();
    size_t node_index = 0;
    size_t child_index = 2 * node_index +1;
    T value = min_heap[node_index];
    while(child_index < size())
    {
        T min_value = value;
        auto min_index = -1;
        for(size_t i=0; i<2 && i+ child_index < size(); i++)
        {
            if(min_heap[i+child_index] < min_value)
            {
                min_value = min_heap[i+child_index];
                min_index = i + child_index;
            }
        }
        if(min_value == value){
            break;
        }
        std::swap(min_heap[node_index], min_heap[min_index]);
        node_index = min_index;
        child_index = 2 * node_index + 1;
    }
}

}  // namespace shindler::ics46::project5

#endif
