#include "lib_cond.h"
#include <Arduino.h>




int lib_cond_saturate(int value, int min, int max)
{
    int result = value;
    if (value < min)
    {
        result = min;
    }
    else if (value > max)
    {
        result = max;
    }
    else
    {
        result = value;
    }
    return result;
    // alternative implementation
    return constrain(value, min, max);
}

int lib_cond_fifo_push(int *fifo, int fifo_size, int value)
{
    // Shift all values to the right position
    for (int i = fifo_size - 1; i > 0; i--)
    {
        fifo[i] = fifo[i - 1];
    }

    // Push the value to the first position
    fifo[0] = value;

    // Return first value
    return fifo[0];
}

int lib_cond_copy_fifo(int *fifo, int *window, int fifo_size)
{
    // Copy the fifo to the window
    for (int i = 0; i < fifo_size; i++)
    {
        window[i] = fifo[i];
    }
    return fifo_size;
}

int cond_sort_buffer(int *buffer, int buffer_size)
{
    // Sort the buffer
    for (int i = 0; i < buffer_size - 1; i++)
    {
        for (int j = i + 1; j < buffer_size; j++)
        {
            if (buffer[i] > buffer[j])
            {
                int temp = buffer[i];
                buffer[i] = buffer[j];
                buffer[j] = temp;
            }
        }
    }
    return buffer_size;
    // alternative implementation
    // std::sort(buffer, buffer + buffer_size);
    // return buffer_size;
}

int lib_cond_median(int value, int *fifo, int *window, int window_size)
{   
    int result = 0;
    // push the value to the fifo
    int fifo_value = lib_cond_fifo_push(fifo, window_size, value);

    // copy the fifo to the window
    lib_cond_copy_fifo(fifo, window, window_size);

    // sort the window
    cond_sort_buffer(window, window_size);

    // extract the median value
    result = window[window_size / 2];
}

int lib_cond_weighted_average(int value, int *fifo, int *weights, int window_size)
{
    int result = 0;

    // push the value to the fifo
    int fifo_value = lib_cond_fifo_push(fifo, window_size, value);

    // calculate uppersum
    long uppersum = 0;
    for (int i = 0; i < window_size; i++)
    {
        // use casting to avoid overflow
        uppersum += (long)fifo[i] * weights[i];
    }

    // calculate lower sum (of weights)
    int lowersum = 0;
    for (int i = 0; i < window_size; i++)
    {
        lowersum += weights[i];
    }

    result = uppersum / lowersum;
    return result;
}