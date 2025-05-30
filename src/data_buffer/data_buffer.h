#ifndef DATA_BUFFER_H
#define DATA_BUFFER_H

#include <vector>
#include <cstddef>

class DataBuffer {
public:
    DataBuffer();
    explicit DataBuffer(size_t capacity);

    void push_back(double value);
    double at(size_t index) const;
    size_t size() const;
    void clear();

private:
    std::vector<double> buffer_;
};

#endif // DATA_BUFFER_H