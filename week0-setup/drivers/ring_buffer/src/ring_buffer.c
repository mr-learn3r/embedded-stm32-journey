#include "ring_buffer.h"

void rb_init(RingBuffer *rb) 
{
  rb->head =0;
  rb->tail =0;
}

void rb_push(RingBuffer *rb, uint8_t data) {
    if (rb_is_full(rb)) return;
    rb->arr[rb->head] = data;
    rb->head = (rb->head + 1) % BUFFER_SIZE;
}

uint8_t rb_pop(RingBuffer *rb) 
{ if(rb_is_empty(rb))
    return -1;
  else
    {
      uint8_t x = rb->arr[rb->tail];
      rb->tail = (rb->tail+1)%BUFFER_SIZE;
      return x;
    }
}

bool rb_is_full(RingBuffer *rb) 
{ if((rb->head+1)%BUFFER_SIZE == rb->tail)
    return true;
  else
    return false;
}

bool rb_is_empty(RingBuffer *rb) 
{ if(rb->head == rb->tail) 
    return true;
  else
    return false;
}
