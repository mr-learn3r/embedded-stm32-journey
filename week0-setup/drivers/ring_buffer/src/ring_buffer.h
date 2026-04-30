#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

#define BUFFER_SIZE 10

typedef struct{
  uint8_t arr[BUFFER_SIZE];
  uint8_t head;
  uint8_t tail;
}RingBuffer;  

void rb_init ( RingBuffer *rb);
void rb_push ( RingBuffer *rb, uint8_t data);
uint8_t rb_pop ( RingBuffer *rb);
bool rb_is_full ( RingBuffer *rb);
bool rb_is_empty ( RingBuffer *rb);

#endif
