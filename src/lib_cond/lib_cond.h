#ifndef LIB_COND_H
#define LIB_COND_H

// window shall be lower than fifo
int lib_cond_saturate(int value, int min, int max);
int lib_cond_fifo_push(int *fifo, int fifo_size, int value);
int lib_cond_median(int value, int *fifo, int window, int window_size);
int lib_cond_weighted_average(int value, int *fifo, int *weights, int window_size);

#endif // LIB_COND_H