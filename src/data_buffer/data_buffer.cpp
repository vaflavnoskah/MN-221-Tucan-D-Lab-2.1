#include "data_buffer.h"
#include <vector>
#include <stdexcept>

DataBuffer::DataBuffer(size_t capacity)
    : buffer_(capacity), head_(0), tail_(0), size_(0), capacity_(capacity) {}

void DataBuffer::push(int value) {
    if (size_ == capacity_) {
        throw std::overflow_error("Buffer is full");
    }
    buffer_[tail_] = value;
    tail_ = (tail_ + 1) % capacity_;
    ++size_;
}

int DataBuffer::pop() {
    if (size_ == 0) {
        throw std::underflow_error("Buffer is empty");
    }
    int value = buffer_[head_];
    head_ = (head_ + 1) % capacity_;
    --size_;
    return value;
}

size_t DataBuffer::size() const {
    return size_;
}

bool DataBuffer::empty() const {
    return size_ == 0;
}

bool DataBuffer::full() const {
    return size_ == capacity_;
}