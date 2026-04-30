#include "unity.h"
#include "ring_buffer.h"

RingBuffer rb;

void setUp(void)    { rb_init(&rb); }
void tearDown(void) {}

// Test 1: Buffer should be empty after init
void test_rb_is_empty_after_init(void) {
    TEST_ASSERT_TRUE(rb_is_empty(&rb));
}

// Test 2: Buffer should not be empty after one push
void test_rb_not_empty_after_push(void) {
    rb_push(&rb, 42);
    TEST_ASSERT_FALSE(rb_is_empty(&rb));
}

// Test 3: Pop should return the pushed value (FIFO)
void test_rb_pop_returns_pushed_value(void) {
    rb_push(&rb, 99);
    TEST_ASSERT_EQUAL_UINT8(99, rb_pop(&rb));
}

// Test 4: Buffer should be full after BUFFER_SIZE pushes
void test_rb_is_full_after_max_pushes(void) {
    for (int i = 0; i < BUFFER_SIZE; i++) rb_push(&rb, i);
    TEST_ASSERT_TRUE(rb_is_full(&rb));
}

// Test 5: FIFO order — first in first out
void test_rb_fifo_order(void) {
    rb_push(&rb, 1);
    rb_push(&rb, 2);
    rb_push(&rb, 3);
    TEST_ASSERT_EQUAL_UINT8(1, rb_pop(&rb));
    TEST_ASSERT_EQUAL_UINT8(2, rb_pop(&rb));
    TEST_ASSERT_EQUAL_UINT8(3, rb_pop(&rb));
}

